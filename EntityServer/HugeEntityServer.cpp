/*
 * HugeEntityServer.cpp
 *
 *  Created on: 2012-10-27
 *      Author: root
 */

#include "HugeEntityServer.h"

HugeEntityServer::HugeEntityServer() {}

HugeEntityServer::~HugeEntityServer() {}

bool HugeEntityServer::Insert(const char* collectionName, const BsonObj& prop2value) {
	return this->m_Server.Insert(collectionName, prop2value);
}

bool HugeEntityServer::Remove(const char* collectionName, const BsonObj& query) {
	return this->m_Server.Remove(collectionName, query);
}

bool HugeEntityServer::Update(const char* collectionName, const BsonObj& query, const BsonObj& update) {
	return this->m_Server.Update(collectionName, query, update);
}

BsonObj* HugeEntityServer::Select(const char* collectionName, const BsonObj& query) {
	return this->m_Server.Select(collectionName, query);
}

bool HugeEntityServer::IsAvailable() {
	return this->m_Server.IsAvailable();
}



