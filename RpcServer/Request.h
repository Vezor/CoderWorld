/*
 * Request.h
 *
 *  Created on: 2012-10-13
 *      Author: root
 */

#ifndef REQUEST_H_
#define REQUEST_H_

#include "../Util/CoreHead.h"
#include "../Util/Util.h"

class Request {
public:

	Request(char* parameter);

	~Request();

	const BsonObj& GetParamMap();

private:

	char* m_Parameter;

	Request(const Request& req);

	Request& operator=(const Request& req);

};


#endif /* REQUEST_H_ */
