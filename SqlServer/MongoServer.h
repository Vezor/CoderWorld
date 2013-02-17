/*
 * MongoServer.h
 *
 *  Created on: 2012-10-26
 *      Author: root
 */

#ifndef MONGOSERVER_H_
#define MONGOSERVER_H_

#include "../Util/CoreHead.h"
#include "../Util/Util.h"

class MongoServer {
public:

	MongoServer();

	~MongoServer();

	bool Insert(const char* collectionName, const BsonObj& prop2value);

	bool Remove(const char* collectionName, const BsonObj& query);

	bool Update(const char* collectionName, const BsonObj& query, const BsonObj& update, int flag = MONGO_UPDATE_BASIC);

	BsonObj* Select(const char* collectionName, const BsonObj& query);

	const char* GetDatabaseName();

	bool IsAvailable();

private:

	const char* m_Database;

	mongo* m_MongoClient;

	MongoServer(const MongoServer& ms);

	MongoServer& operator=(const MongoServer& ms);

};


#endif /* MONGOSERVER_H_ */
