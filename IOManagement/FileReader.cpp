#include "FileReader.h"

FileReader::FileReader(char* ap_filename){
  FILE* lv_file;
  lv_file=fopen(ap_filename,"r");
  if(lv_file==NULL){
    ov_isFileOpened=false;
    perror ("Error openeing file");
  }
  else{
    ov_isFileOpened=true;
  
    fseek(lv_file,0,SEEK_END);
    ov_size = ftell(lv_file);
    fclose(lv_file);
    op_file=fopen(ap_filename,"r");
  }
}

bool FileReader::wakeup(){
  int lv_size;
  char* lp_buffer;
	if(ov_isFileOpened){
    //Read the file
    lp_buffer=(char*)malloc(ov_size);
    while(!feof(op_file)){
      if(fread(lp_buffer,sizeof(char),ov_size,op_file)==NULL) break;
      for(std::list<Module*>::iterator it=op_destinations.begin();it!=op_destinations.end(); it++)
        (*it)->putData(lp_buffer,ov_size);
    }
    fclose(op_file);
    delete lp_buffer;
    return true;
  }
	return false;
}