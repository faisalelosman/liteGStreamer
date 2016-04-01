#ifndef Streamer_h
#define Streamer_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Module.h"
#include "Pool.h"
#include "Thread.h"

class Frame{
public:
	char*	op_data;
	int		ov_size;
};

class Streamer;
class Consumer : public Thread
{
	public:
		Pool<Frame>*	op_pool;
		Streamer*		op_streamer;
		int 			ov_interFrameDelayInMicroSecond;
	protected:
		virtual void run();
	public:
		Consumer(Pool<Frame>* ap_pool,Streamer* ap_streamer,int av_interFrameDelayInMicroSecond){
			op_pool=ap_pool;
			op_streamer=ap_streamer;
			ov_interFrameDelayInMicroSecond=av_interFrameDelayInMicroSecond;
		}
};

class Streamer: public Module{
public:
	Pool<Frame>* op_pool;
	int 		 ov_interFrameDelayInMicroSecond;
	Consumer* 	 op_consumer;
	bool		 ov_isFirstFrame;
	
	Streamer(int av_interFrameDelayInMicroSecond){
		ov_interFrameDelayInMicroSecond=av_interFrameDelayInMicroSecond;
		op_pool=new Pool<Frame>();
		op_consumer=new Consumer(NULL,NULL,0);
		ov_isFirstFrame=true;
	}
	virtual bool putData(char* ap_data, int av_size);
	virtual bool wakeup(){}
	bool wakeup(char* ap_data, int av_size);
	void join();
};
#endif 