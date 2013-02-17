/*
 * SocialEntityServer.h
 *
 *  Created on: 2012-10-19
 *      Author: root
 */

#ifndef SOCIALENTITYSERVER_H_
#define SOCIALENTITYSERVER_H_

#include "../SqlServer/RedisServer.h"
#include "../ObjectPool/PoolObject.h"

class SocialEntityServer : public PoolObject {
public:

	SocialEntityServer();

	~SocialEntityServer();

	bool Create(const char *entity);

	BsonObj* GetAll(const char *entity);

	char** GetSome(const char *entity, const KFList& proplist);

	BsonObj* GetOne(const char *entity, const char *prop);

	bool SetProp(const char *entity, const char *prop, int value);

	int IncrProp(const char *entity, const char *prop, int incr=1);

	int DecrProp(const char *entity, const char *prop, int desc=-1);

	bool IsAvailable();

private:

	RedisServer m_Server;

	SocialEntityServer(const SocialEntityServer& ses);

	SocialEntityServer& operator=(const SocialEntityServer& ses);

};


#endif /* SOCIALENTITYSERVER_H_ */
