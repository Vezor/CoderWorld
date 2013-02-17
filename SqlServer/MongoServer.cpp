/*
 * MongoServer.cpp
 *
 *  Created on: 2012-10-27
 *      Author: root
 */

#include "MongoServer.h"

MongoServer::MongoServer() : m_Database("CodeWorld.") {
	mongo_init(this->m_MongoClient);
	mongo_set_op_timeout(this->m_MongoClient, 1000);
	mongo_client(this->m_MongoClient, "127.0.0.1", port);
}

MongoServer::~MongoServer() {
	mongo_destroy(this->m_MongoClient);
	free(this->m_MongoClient);
}

bool MongoServer::Insert(const char* collectionName, const BsonObj& prop2value) {
	return mongo_insert(this->m_MongoClient, collectionName, prop2value.get(), this->m_MongoClient->write_concern) == MONGO_OK;
}

bool MongoServer::Remove(const char* collectionName, const BsonObj& query) {
	return mongo_remove(this->m_MongoClient, collectionName, query.get(), this->m_MongoClient->write_concern) == MONGO_OK;
}

bool MongoServer::Update(const char* collectionName, const BsonObj& query, const BsonObj& update, int flag) {
	return mongo_update(this->m_MongoClient, collectionName, query.get(), update.get(), flag, this->m_MongoClient->write_concern) == MONGO_OK;
}

BsonObj* MongoServer::Select(const char* collectionName, const BsonObj& query) {
	mongo_cursor* cursor = new mongo_cursor();
	mongo_cursor_init(cursor, this->m_MongoClient, collectionName);
	mongo_cursor_set_query(cursor, query.get());
	if (mongo_cursor_next(cursor) == MONGO_OK) {
		return new BsonObj(const_cast<bson *>(mongo_cursor_bson(cursor)));
	} else {
		return new BsonObj();
	}
}

const char* MongoServer::GetDatabaseName() {
	return this->m_Database;
}

bool MongoServer::IsAvailable() {
	return this->m_MongoClient->sock > 0;
}




