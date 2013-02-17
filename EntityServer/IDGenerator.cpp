/*
 * IDGenerator.cpp
 *
 *  Created on: 2013-2-5
 *      Author: root
 */

#include "IDGenerator.h"

IDGenerator::IDGenerator() {}

IDGenerator::~IDGenerator() {}

const char *IDGenerator::NextID(const char* ID) {
	return this->m_Server.Incr(ID)->GetString();
}

bool IDGenerator::IsAvailable() {
	return this->m_Server.IsAvailable();
}


