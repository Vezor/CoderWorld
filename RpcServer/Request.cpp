/*
 * Request.cpp
 *
 *  Created on: 2012-10-13
 *      Author: root
 */

#include "Request.h"

Request::Request(char* parameter): m_Parameter(parameter) {};

Request::~Request() { delete this->m_Parameter; }

const BsonObj& Request::GetParamMap(){
	char** parameters = split(this->m_Parameter, "&");
	BsonObj* paramMap = new BsonObj();
	char *name, *value;
	for (; *parameters != NULL; parameters++) {
		int idx = FindEqualSymbol(*parameters);
		*parameters[idx] = '\0';
		name = *parameters;
		value = *parameters + idx + 1;
		paramMap->set(name, value);
	}
	return *paramMap;
}




