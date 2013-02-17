/*
 * Response.h
 *
 *  Created on: 2013-2-4
 *      Author: root
 */

#ifndef RESPONSE_H_
#define RESPONSE_H_

#include "../Util/CoreHead.h"
#include "../Api/Api.h"

class Response {
public:

	Response(BsonObj *srcResp, Api *api);

	~Response();

	const char* Get();

private:

	BsonObj *m_SrcResp;

	Api *m_Api;

	Response(const Response& rep);

	Response& operator=(const Response& rep);

};


#endif /* RESPONSE_H_ */
