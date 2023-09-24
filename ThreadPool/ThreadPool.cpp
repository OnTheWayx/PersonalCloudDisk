#include "ThreadPool.h"

ThreadPool::ThreadPool(XUUint32 PoolThreadNum, XUUint32 PoolTaskNum, void *ThreadFunc(void *))
    : mThreadNum(PoolThreadNum), mTaskMaxNum(PoolTaskNum), mThreadWorkFunc(ThreadFunc)
{
}