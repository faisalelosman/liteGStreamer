#include "Streamer.h"

bool Streamer::putData(char* ap_data, int av_size){
  Frame lv_frame;

  lv_frame.op_data=(char*)malloc(av_size*sizeof(char));
  lv_frame.ov_size=av_size;
  memcpy(lv_frame.op_data,ap_data,av_size*sizeof(char));

  op_pool->push(lv_frame);
  if(ov_isFirstFrame){
    op_consumer->start();
    op_consumer->op_pool=op_pool;
    op_consumer->op_streamer=this;
    op_consumer->ov_interFrameDelayInMicroSecond=ov_interFrameDelayInMicroSecond;
    ov_isFirstFrame=false;
  }
}

bool Streamer::wakeup(char* ap_data, int av_size){
  for(std::list<Module*>::iterator it=op_destinations.begin();it!=op_destinations.end(); it++)
    (*it)->putData(ap_data,av_size);
}

void Consumer::run()
{
  if (!op_streamer) return;
  Frame lv_frame;
  bool lv_isFirstTime=true;
  while(true){
    if(op_pool->size()>0){
      lv_frame=op_pool->pop();
      op_streamer->wakeup(lv_frame.op_data, lv_frame.ov_size);
      delete lv_frame.op_data;
      lv_isFirstTime=false;
    }
    else
      if(!lv_isFirstTime) return;
      usleep(ov_interFrameDelayInMicroSecond);
  }
}
void Streamer::join(){
  op_consumer->join();
}