/*
 * Api.cpp
 *
 *  Created on: 2013-2-5
 *      Author: root
 */

#include "Api.h"

Api::Api(const char *url, bool filtrate, const char **respNames):
	m_Url(url),
	m_Filtrate(filtrate),
	m_RespNames(respNames) {};

Api::~Api(){ delete this->m_Url; delete [] this->m_RespNames;};

const char* Api::GetUrl() const {
	return this->m_Url;
}

bool Api::Filtrate() {
	return this->m_Filtrate;
}

const char** Api::GetRespNames() const {
	return this->m_RespNames;
}
