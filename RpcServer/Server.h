/*
 * Server.h
 *
 *  Created on: 2012-10-13
 *      Author: root
 */

#ifndef SERVER_H_
#define SERVER_H_

#include "Request.h"
#include "Response.h"
#include "../Api/Api.h"

typedef str_equal_to<const char*> url_equal;

typedef __gnu_cxx::hash_map< const char*, Api*, __gnu_cxx::hash<const char*>, url_equal > ApiMap;

class Server {
public:

	Server();

	~Server();

	int Accept();

	void Process();

	void AddMethod(Api* api);

	void InitApiMap(Api* apis[], int apiCount);

private:

	char* GetParameter() const;

	char* GetUrl() const;

	Server(const Server& s);

	Server& operator=(const Server& s);

	ApiMap m_ApiMap;
};

#endif /* SERVER_H_ */
