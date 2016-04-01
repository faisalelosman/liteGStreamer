#ifndef FileReader_h
#define FileReader_h

#include <stdio.h>
#include <stdlib.h>
#include "Module.h"

class FileReader: public Module{
public:
	FILE*	op_file;
	bool	ov_isFileOpened;
	int 	ov_size;

	FileReader(char* ap_filename);
	virtual bool putData(char* ap_data, int av_size){}
	virtual bool wakeup();

};
#endif 