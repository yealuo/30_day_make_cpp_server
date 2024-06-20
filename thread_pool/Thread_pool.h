//
// Created by yeluo on 24-6-9.
//

#pragma once

#include <mutex>
#include <condition_variable>
#include <queue>
#include <functional>
#include <future>
#include <thread>

class Thread_pool {
private:
    std::mutex mtx;
    std::condition_variable cond_var;
    bool stop;

    std::queue<std::function<void()>> task_queue;
    std::vector<std::thread> workers;

    void worker_thread();

public:
    explicit Thread_pool(size_t thread_num);

    ~Thread_pool();

    template<typename Func, typename... Args>
    auto thread_pool_post(Func &&func, Args &&... args) -> std::future<std::invoke_result_t<Func, Args...>>;

};

template<typename Func, typename... Args>
auto Thread_pool::thread_pool_post(Func &&func, Args &&... args) -> std::future<std::invoke_result_t<Func, Args...>> {
    using return_type = std::invoke_result_t<Func, Args...>;

    auto task = std::make_shared<std::packaged_task<return_type()>>(
            std::bind(std::forward<Func>(func), std::forward<Args>(args)...));

    auto res = task->get_future();
    {
        std::unique_lock<std::mutex> lock(mtx);
        if (stop) {
            throw std::runtime_error("加入了一个停止的线程池");
        }
        task_queue.emplace([task] { (*task)(); });
    }
    cond_var.notify_one();
    return res;
}

