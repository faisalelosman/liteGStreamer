#ifndef H264ExtractorFromPcap_h
#define H264ExtractorFromPcap_h
#include "Module.h"

class H264ExtractorFromPcap: public Module{
public:
	H264ExtractorFromPcap();
	virtual  bool putData(char* ap_data, int av_size);
	virtual  bool connect(Module* ap_module);
	virtual  bool wakeup();
};
#endif 