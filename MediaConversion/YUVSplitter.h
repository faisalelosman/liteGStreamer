#ifndef YUVSplitter_h
#define YUVSplitter_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Module.h"

class YUVSplitter: public Module{
public:
	char* 	op_data;
	int		ov_width;
	int		ov_height;

	YUVSplitter(int av_width,int av_height){
		ov_width	= av_width;
		ov_height	= av_height;
	}
	virtual bool putData(char* ap_data, int av_size);
	virtual bool wakeup(){}
	bool wakeup(char* ap_data, int av_size);
};
#endif 