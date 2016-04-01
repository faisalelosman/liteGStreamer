#ifndef __POOL_H__
#define __POOL_H__

#include "Mutex.h"
#include <queue>
#include <unistd.h>

template <class T> class Pool
{
	private:
		std::queue<T> data;
		Mutex mtx;
	public:
		Pool()
			{}
		~Pool()
			{
				mtx.lock();
				while (data.size()) data.pop();
				mtx.unlock();
			}
		size_t size() 
			{
				mtx.lock();
				size_t result = data.size();
				mtx.unlock();
				return result;
			}
		void push(T item)
			{
				mtx.lock();
				data.push(item);
				mtx.unlock();
			}
		T pop()
			{
				mtx.lock();
				T item = data.front(); data.pop();
				mtx.unlock();
				return item;
			}
};

#endif
