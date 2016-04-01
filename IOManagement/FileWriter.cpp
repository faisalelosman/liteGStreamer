#include "FileWriter.h"

FileWriter::FileWriter(char* ap_filename){
  op_file=fopen(ap_filename,"w");
  fclose (op_file);
  op_file=fopen(ap_filename,"a");
  if(op_file==NULL){
    ov_isFileOpened=false;
    perror ("Error openeing file");
  }
  else{
    ov_isFileOpened=true;
  } 
}

bool FileWriter::putData(char* ap_data, int av_size){
	if(ov_isFileOpened){
    fwrite (ap_data , sizeof(char), av_size, op_file);
    return true;
  }
	return false;
}