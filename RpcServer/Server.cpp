/*
 * Server.cpp
 *
 *  Created on: 2012-10-13
 *      Author: root
 */

#include "Server.h"

Server::Server(){};

Server::~Server(){};

int Server::Accept(){
	return FCGI_Accept();
}

void Server::Process(){
	char* url = this->GetUrl();
	char* parameter = this->GetParameter();
	if (url == NULL || parameter == NULL)
		return;
	Request req(parameter);
	ApiMap::iterator it = this->m_ApiMap.find(url);
	if (it != this->m_ApiMap.end()){
		BsonObj *res = it->second->Process(req.GetParamMap());
		if (res == NULL)
			return;
		Response resp(res, it->second);
		FCGI_printf("%s", resp.Get());
	} else {
		throw BaseException(REQUEST_URL_UNFIND, url);
	}
}

void Server::AddMethod(Api* api){
	this->m_ApiMap[api->GetUrl()] = api;
}

void Server::InitApiMap(Api* apis[], int apiCount){
	for (int i = 0; i < apiCount; i++) {
		this->AddMethod(apis[i]);
	}
}

char* Server::GetParameter() const {
	return getenv("QUERY_STRING");
}

char* Server::GetUrl() const {
	return getenv("DOCUMENT_URI");
}



