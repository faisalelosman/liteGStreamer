#include "YUVSplitter.h"



bool YUVSplitter::wakeup(char* ap_data, int av_size){
  for(std::list<Module*>::iterator it=op_destinations.begin();it!=op_destinations.end(); it++)
    (*it)->putData(ap_data,av_size);
}

bool YUVSplitter::putData(char* ap_data, int av_size){
  op_data=(char*)malloc(av_size*sizeof(char));
  memcpy(op_data,ap_data,av_size*sizeof(char));
  char* lp_yuv=(char*)malloc(ov_width*ov_height*sizeof(char)*1.5);
  int lv_size=0;

  while(av_size-lv_size>=ov_width*ov_height*sizeof(char)*1.5){
    memcpy(lp_yuv,ap_data+lv_size,ov_width*ov_height*sizeof(char)*1.5);
    lv_size+=ov_width*ov_height*sizeof(char)*1.5;
    wakeup(lp_yuv,ov_width*ov_height*sizeof(char)*1.5);
  }

  return true;
}