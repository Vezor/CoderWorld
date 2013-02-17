/*
 * SetLinkEntityServer.cpp
 *
 *  Created on: 2013-2-3
 *      Author: root
 */

#include "SetLinkEntityServer.h"

SetLinkEntityServer::SetLinkEntityServer() : m_Server() {}

SetLinkEntityServer::~SetLinkEntityServer() {}

bool SetLinkEntityServer::Link(const char *field, const char *id) {
	return this->m_Server.SAdd(field, id)->GetInt() > 0;
}

bool SetLinkEntityServer::Unlink(const char *field, const char *id) {
	return this->m_Server.SRem(field, id)->GetInt() > 0;
}

bool SetLinkEntityServer::IsLink(const char *field, const char *id) {
	return this->m_Server.SIsMember(field, id)->GetInt() > 0;
}

char** SetLinkEntityServer::GetLinkSet(const char *field, int count) {
	return this->m_Server.SRandMember(field, count)->GetElement();
}

char** SetLinkEntityServer::GetMutualLinkSet(const char *field1, const char *field2, int count) {
	char *mutual = new char[128];
	mutual[0] = '\0';
	strcatt(3, mutual, field1, "m", field2);
	if (this->m_Server.Exists(mutual)) {
		return this->m_Server.SRandMember(mutual, count)->GetElement();
	}
	if (this->m_Server.SInterStore(mutual, field1, field2)->GetInt()) {
		this->m_Server.Expire(mutual, 3600);
		return this->m_Server.SRandMember(mutual, count)->GetElement();
	}
	return NULL;
}

bool SetLinkEntityServer::IsAvailable() {
	return this->m_Server.IsAvailable();
}
