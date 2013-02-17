/*
 * SetLinkEntityServer.h
 *
 *  Created on: 2013-2-3
 *      Author: root
 */

#ifndef SETLINKENTITYSERVER_H_
#define SETLINKENTITYSERVER_H_

#include "../SqlServer/RedisServer.h"

class SetLinkEntityServer : public PoolObject {
public:

	SetLinkEntityServer();

	virtual ~SetLinkEntityServer();

	bool Link(const char *field, const char *id);

	bool Unlink(const char *field, const char *id);

	bool IsLink(const char *field, const char *id);

	char** GetLinkSet(const char *field, int count);

	char** GetMutualLinkSet(const char *field1, const char *field2, int count);

	bool IsAvailable();

private:

	RedisServer m_Server;

	SetLinkEntityServer(const SetLinkEntityServer& ses);

	SetLinkEntityServer& operator=(const SetLinkEntityServer& ses);

};



#endif /* SETLINKENTITYSERVER_H_ */
