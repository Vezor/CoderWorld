/*
 * RedisUtil.cpp
 *
 *  Created on: 2013-1-24
 *      Author: root
 */

#include "RedisUtil.h"

SortCondition::SortCondition() {
	this->m_Condition = new char[512];
	this->m_Condition[0] = '\0';
}

SortCondition::SortCondition(const char *condition) {
	this->m_Condition = new char[512];
	strcpy(this->m_Condition, condition);
}

SortCondition::~SortCondition() {
	delete [] this->m_Condition;
}

SortCondition& SortCondition::by(const char *pattern) {
	strcatt(2, this->m_Condition, " by ", pattern);
	return *this;
}

SortCondition& SortCondition::limit(const char *offset, const char *count) {
	strcatt(3, this->m_Condition, " limit ", offset, count);
	return *this;
}

SortCondition& SortCondition::get(const char *pattern) {
	strcatt(2, this->m_Condition, " get ", pattern);
	return *this;
}

SortCondition& SortCondition::asc() {
	strcat(this->m_Condition, " asc");
	return *this;
}

SortCondition& SortCondition::desc() {
	strcat(this->m_Condition, " desc");
	return *this;
}

SortCondition& SortCondition::alpha() {
	strcat(this->m_Condition, " alpha");
	return *this;
}

SortCondition& SortCondition::store(const char *dest) {
	strcatt(2, this->m_Condition, " store ", dest);
	return *this;
}

SortCondition& SortCondition::withscore() {
	strcat(this->m_Condition, " withscore");
	return *this;
}

char* SortCondition::getCondition() const {
	return this->m_Condition;
}

Pairs::Pairs() {
	this->m_Pairs = new char[1024];
	this->m_Pairs[0] = '\0';
}

Pairs::~Pairs() {
	delete [] this->m_Pairs;
}

void Pairs::AddPair(const char *keyOrField, const char *value) {
	strcatt(5, this->m_Pairs, " ", keyOrField, " \"", value, "\"");
}

char* Pairs::GetPairs() const {
	return this->m_Pairs;
}

KFList::KFList() {
	this->m_List = new char[512];
	this->m_List[0] = '\0';
}

KFList::~KFList() {
	delete [] this->m_List;
}

void KFList::AddKeyOrField(const char *keyOrField) {
	strcatt(2, this->m_List, " ", keyOrField);
}

char* KFList::GetList() const {
	return this->m_List;
}
