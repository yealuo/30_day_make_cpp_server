//
// Created by yeluo on 24-6-9.
//
#include "Thread_pool.h"

Thread_pool::Thread_pool(size_t thread_num) : stop(false) {
    for (int i = 0; i < thread_num; ++i)
        workers.emplace_back([this]() { worker_thread(); });
}

Thread_pool::~Thread_pool() {
    {
        std::lock_guard<std::mutex> lock(mtx);
        stop = true;
    }
    cond_var.notify_all();
    for (std::thread &t: workers)
        t.join();
}

void Thread_pool::worker_thread() {
    std::function<void()> task;
    while (true) {
        {
            std::unique_lock<std::mutex> lock(mtx);
            cond_var.wait(lock, [this]() { return stop || !task_queue.empty(); });
            if (stop && task_queue.empty()) return;
            task = std::move(task_queue.front());
            task_queue.pop();
        }
        task();
    }
}
