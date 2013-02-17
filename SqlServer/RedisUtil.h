/*
 * RedisUtil.h
 *
 *  Created on: 2013-1-24
 *      Author: root
 */

#ifndef REDISUTIL_H_
#define REDISUTIL_H_

#include "../Util/CoreHead.h"

class SortCondition {
public:

	SortCondition();

	SortCondition(const char *condition);

	~SortCondition();

	SortCondition& by(const char *pattern);

	SortCondition& limit(const char *offset, const char *count);

	SortCondition& get(const char *pattern);

	SortCondition& asc();

	SortCondition& desc();

	SortCondition& alpha();

	SortCondition& store(const char *dest);

	SortCondition& withscore();

	char* getCondition() const;

private:

	char *m_Condition;

	SortCondition(const SortCondition& sc);

	SortCondition& operator=(const SortCondition& sc);

};

class Pairs {
public:

	Pairs();

	~Pairs();

	void AddPair(const char *keyOrField, const char *value);

	char* GetPairs() const;

private:

	char *m_Pairs;

	Pairs(const Pairs& p);

	Pairs& operator=(const Pairs& p);
};

class KFList {
public:

	KFList();

	~KFList();

	void AddKeyOrField(const char *keyOrField);

	char* GetList() const;

private:

	char *m_List;

	KFList(const KFList& l);

	KFList& operator=(const KFList& l);

};




#endif /* REDISUTIL_H_ */
