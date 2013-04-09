/*
 * SocialEntityServer.cpp
 *
 *  Created on: 2013-2-3
 *      Author: root
 */

#include "SocialEntityServer.h"

SocialEntityServer::SocialEntityServer() : m_Server() {}

SocialEntityServer::~SocialEntityServer() {}

bool SocialEntityServer::Create(const char *entity) {
	this->m_Server.HSet(entity, "cre", "1");
	return true;
}

BsonObj* SocialEntityServer::GetAll(const char *entity) {
	RedisReply *reply = this->m_Server.HGetAll(entity);
	int count = reply->GetElementsSize();
	char** elements = reply->GetElement();
	BsonObj *bobj = new BsonObj();
	for (int i = 0; i < count; i++) {
		char *key = *(elements+i);
		i++;
		char *value = *(elements+i);
		bobj->set(key, value);
	}
	return bobj;
}

char** SocialEntityServer::GetSome(const char *entity, const KFList& proplist) {
	return this->m_Server.HMGet(entity, proplist)->GetElement();
}

BsonObj* SocialEntityServer::GetOne(const char *entity, const char *prop) {
	BsonObj *bobj = new BsonObj();
	RedisReply *reply = this->m_Server.HGet(entity, prop);
	bobj->set(prop, *(reply->GetElement()));
	return bobj;
}

bool SocialEntityServer::SetProp(const char *entity, const char *prop, int value) {
	this->m_Server.HSet(entity, prop, value);
	return true;
}

int SocialEntityServer::IncrProp(const char *entity, const char *prop, int incr) {
	return this->m_Server.HIncrBy(entity, prop, incr)->GetInt();
}

int SocialEntityServer::DecrProp(const char *entity, const char *prop, int desc) {
	return this->m_Server.HIncrBy(entity, prop, desc)->GetInt();
}

bool SocialEntityServer::IsAvailable() {
	return this->m_Server.IsAvailable();
}

