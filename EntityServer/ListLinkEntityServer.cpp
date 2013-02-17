/*
 * ListLinkEntityServer.cpp
 *
 *  Created on: 2013-2-3
 *      Author: root
 */

#include "ListLinkEntityServer.h"

ListLinkEntityServer::ListLinkEntityServer() : m_Server() {}

ListLinkEntityServer::~ListLinkEntityServer() {}

bool ListLinkEntityServer::Link(const char *field, const char *id) {
	return this->m_Server.LPush(field, id);
}

bool ListLinkEntityServer::Unlink(const char *field, const char *id) {
	return this->m_Server.LRem(field, 0, id);
}

char** ListLinkEntityServer::GetLinkedList(const char *field, int start, int end) {
	return this->m_Server.LRange(field, start, end)->GetElement();
}

bool ListLinkEntityServer::IsAvailable() {
	return this->m_Server.IsAvailable();
}


