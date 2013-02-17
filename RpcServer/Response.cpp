/*
 * Response.cpp
 *
 *  Created on: 2013-2-4
 *      Author: root
 */

#include "Response.h"

Response::Response(BsonObj *srcResp, Api *api) : m_SrcResp(srcResp), m_Api(api) {}

Response::~Response() {
	delete this->m_SrcResp;
}

const char* Response::Get() {
	if (this->m_Api->Filtrate()) {
		BsonObj resp;
		const char **temp = this->m_Api->GetRespNames();
		int count = sizeof(temp) / sizeof(temp[0]);
		for (int i=0; i < count; i++) {
			resp.set(*(temp+i), this->m_SrcResp->getByKey(*(temp+i)));
		}
		return resp.getData();
	}
	return this->m_SrcResp->getData();
}



