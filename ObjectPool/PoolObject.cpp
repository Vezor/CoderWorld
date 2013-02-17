/*
 * PoolObject.cpp
 *
 *  Created on: 2012-12-15
 *      Author: root
 */

#include "PoolObject.h"

PoolObject::PoolObject() : m_LastUseTime(0) {
	this->m_Next = NULL;
}

PoolObject::~PoolObject() {
	if (this->m_Next)
		delete this->m_Next;
}

void PoolObject::LinkNextObject(PoolObject *next) {
	this->m_Next = next;
}

PoolObject* PoolObject::GetNextObject() {
	return this->m_Next;
}

void PoolObject::SetLastUseTime(const time_t& time) {
	this->m_LastUseTime = time;
}

const time_t& PoolObject::GetLastUseTime() {
	return this->m_LastUseTime;
}
