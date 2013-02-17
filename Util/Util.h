/*
 * Util.h
 *
 *  Created on: 2012-10-13
 *      Author: root
 */

#ifndef UTIL_H_
#define UTIL_H_

#include "CoreHead.h"
#include "CStyleTool.h"
#include "../Exception/BaseException.h"
#include "BsonObj.h"

char** split(char* str,const char* c);

int FindEqualSymbol(char *source);

const unsigned char* md5(const char* str);

void Log(int code, const char* log);

void ExceptionHandle(const BaseException& ex);


#endif /* UTIL_H_ */
