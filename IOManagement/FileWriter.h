#ifndef FileWriter_h
#define FileWriter_h

#include <stdio.h>
#include <stdlib.h>
#include "Module.h"

class FileWriter: public Module{
public:
	FILE*	op_file;
	bool	ov_isFileOpened;

	FileWriter(char* filename);
	virtual bool putData(char* ap_data, int av_size);
	virtual bool wakeup(){}
	bool close(){
		fclose (op_file);
		return true;
	}
};

#endif 