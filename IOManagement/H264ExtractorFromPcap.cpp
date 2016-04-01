#include "H264ExtractorFromPcap.h"
#include <stdio.h>


H264ExtractorFromPcap::H264ExtractorFromPcap()
:Module(){}

bool H264ExtractorFromPcap::putData(char* ap_data, int av_size){
	return true;
}
bool H264ExtractorFromPcap::connect(Module* ap_module){
	return true;
}
bool H264ExtractorFromPcap::wakeup(){
	printf("hi H264ExtractorFromPcap\n");
	return true;
}