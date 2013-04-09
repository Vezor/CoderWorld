/*
 * Util.cpp
 *
 *  Created on: 2012-10-13
 *      Author: root
 */

#include "Util.h"
const char* logfile = "/usr/workspace/CodeWorld/log";

char** split(char* str,const char* c)
{
	if (str == NULL or c == NULL)
		return NULL;
    char *cstr, *p;;
    char **res;
    char **temp = res;
    cstr = new char[strlen(str)+1];
    strcpy(cstr,str);
    p = strtok(cstr,c);
    while(p!=NULL)
    {
        *(temp++) = p;
        p = strtok(NULL,c);
    }
    *temp = NULL;
    return res;
}

int FindEqualSymbol(char *source) {
	if (source == NULL)
		return NULL;
	char *temp = source;
	while(*temp != '=' or *temp != '\0') {
		temp++;
	}
	if (*temp == '\0'){
		throw BaseException(REQUEST_PARAMETER_ERROR, source);
	}
	return temp - source;
}

const unsigned char* md5(const char* str) {
	if (str == NULL)
		return NULL;
	unsigned char *md5str = new unsigned char[16];
	mongo_md5_state_t md;
	mongo_md5_init(&md);
	mongo_md5_append(&md, (const unsigned char *)str, strlen(str));
	mongo_md5_finish(&md, md5str);
	return md5str;
}

void Log(int code, const char* log) {
	if (log == NULL)
		return;
	try {
		time_t t;
		time(&t);
		_IO_FILE *fp = fopen(logfile, "a");
		if (fp == NULL) {
			printf("Error happen when open log file");
			return ;
		}
		fprintf(fp, "%s Error code %d : %s", ctime(&t), code, log);
		fclose(fp);
	} catch(const std::exception& ex){
		std::cout<<"Exception happen when doing log, exception is "<<ex.what()<<std::endl;
	}
}

void ExceptionHandle(const BaseException& ex) {
	int code = ex.GetExceptionCode();
	const char* desc = ex.GetExceptionDesc();
	if (desc == NULL)
		return ;
	Log(code, desc);
	BsonObj exception;
	exception.set("res", "false");
	exception.set("type", "exception");
	exception.set("code", code);
	FCGI_printf(exception.getData());
}



