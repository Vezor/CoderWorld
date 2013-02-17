/*
 * HugeEntityServer.h
 *
 *  Created on: 2012-10-27
 *      Author: root
 */

#ifndef HUGEENTITYSERVER_H_
#define HUGEENTITYSERVER_H_

#include "../SqlServer/MongoServer.h"

class HugeEntityServer : public PoolObject {
public:

	HugeEntityServer();

	virtual ~HugeEntityServer();

	bool Insert(const char* collectionName, const BsonObj& prop2value);

	bool Remove(const char* collectionName, const BsonObj& query);

	bool Update(const char* collectionName, const BsonObj& query, const BsonObj& update);

	BsonObj* Select(const char* collectionName, const BsonObj& query);

	bool IsAvailable();

private:

	MongoServer m_Server;

	HugeEntityServer(const HugeEntityServer& hes);

	HugeEntityServer& operator=(const HugeEntityServer& hes);

};



#endif /* HUGEENTITYSERVER_H_ */
