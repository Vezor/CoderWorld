/*
 * ListLinkEntityServer.h
 *
 *  Created on: 2013-2-3
 *      Author: root
 */

#ifndef LISTLINKENTITYSERVER_H_
#define LISTLINKENTITYSERVER_H_

#include "../SqlServer/RedisServer.h"

class ListLinkEntityServer : public PoolObject {
public:

	ListLinkEntityServer();

	virtual ~ListLinkEntityServer();

	bool Link(const char *field, const char *id);

	bool Unlink(const char *field, const char *id);

	char** GetLinkedList(const char *field, int start, int end);

	bool IsAvailable();

private:

	RedisServer m_Server;

	ListLinkEntityServer(const ListLinkEntityServer& lles);

	ListLinkEntityServer& operator=(const ListLinkEntityServer& lles);

};



#endif /* LISTLINKENTITYSERVER_H_ */
