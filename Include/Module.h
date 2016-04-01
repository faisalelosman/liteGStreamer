#ifndef Module_h
#define Module_h

#include <list>

using namespace std;

class Module{
public:
	std::list<Module*> op_destinations;

	virtual bool putData(char* ap_data, int av_size)=0;
	virtual bool connect(Module* ap_module){
		op_destinations.push_front(ap_module);
	}
	virtual bool wakeup()=0;
};
#endif 