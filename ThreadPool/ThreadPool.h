#ifndef _THREADPOOL_H_
#define _THREADPOOL_H_

/**
 * 线程池类
 */
#include <thread>
#include <mutex>
#include <condition_variable>
#include <memory>

#include "../Base/variabletype.h"

class ThreadPool
{
public:
    ThreadPool(XUUint32 PoolThreadNum, XUUint32 PoolTaskNum, void *ThreadFunc(void *));
    ~ThreadPool() = default;

public:
    XUBool StartWork();
    XUBool Destroy();

private:
    /**
     * 线程函数
     */
    XUVoid *(*mThreadWorkFunc)(XUVoid *arg);
    XUUint32 mThreadNum;
    XUUint32 mThreadBusyNum;
    XUUint32 mTaskMaxNum;
    XUUint32 mTaskBusyNum;
    std::mutex mThreadBNumMut;
    std::mutex mTaskBNumMut;

    // std::thread;
    std::shared_ptr<std::thread *> mThreadsPtr;
};

#endif