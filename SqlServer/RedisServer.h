/*
 * RedisServer.h
 *
 *  Created on: 2012-10-19
 *      Author: root
 */

#ifndef REDISSERVER_H_
#define REDISSERVER_H_

#include "../Util/CoreHead.h"
#include "RedisUtil.h"

class RedisReply {
public:

	RedisReply();

	RedisReply(redisReply *reply);

	~RedisReply();

	int GetInt() const;

	const char* GetString() const;

	int GetStrLen() const;

	char** GetElement() const;

	size_t GetElementsSize() const;

private:

	redisReply *m_Reply;

	RedisReply(RedisReply* reply);

	RedisReply& operator=(RedisReply* reply);

};

class RedisServer {
public:

	RedisServer();

	~RedisServer();

	bool IsAvailable();

	bool Del(const char  *key);

	RedisReply* Keys(const char *key);

	RedisReply* RandomKey();

	RedisReply* TTL(const char *key); //time to live , second

	RedisReply* PTTL(const char *key); //time to live, millisecond

	bool Exists(const char *key);

	RedisReply* Move(const char *key, unsigned int id);

	RedisReply* Rename(const char *key, const char *newkey); //if newkey exist, overwritten

	RedisReply* RenameNX(const char *key, const char *newkey); //if newkey exist, return 0, and nothing happen else

	RedisReply* Type(const char *key);

	RedisReply* Expire(const char *key, unsigned int second); //set expire time, use second

	RedisReply* PExpire(const char *key, unsigned int millisecond); //set expire time, use millisecond

	RedisReply* ExpireAT(const char *key, unsigned int timestamp); //set expire time, use unix timestamp

	RedisReply* PExpireAT(const char *key, unsigned int millitimestamp); //set expire time, use unix timestamp millisecond

	RedisReply* Persist(const char *key); //make a key persist, remove its expire time

	RedisReply* Sort(const char *key, const SortCondition& sc);

//	RedisReply* Set(const char *key, const char *value);
//
//	RedisReply* Set(const char *key, int value);
//
//	RedisReply* SetNX(const char *key, const char *value);
//
//	RedisReply* SetNX(const char *key, int value);
//
//	RedisReply* SetEX(const char *key, int second, const char *value);
//
//	RedisReply* SetEX(const char *key, int second, int value);
//
//	RedisReply* PSetEX(const char *key, int millisecond, const char *value);
//
//	RedisReply* PSetEX(const char *key, int millisecond, int value);
//
//	RedisReply* SetRange(const char *key, int offset, const char *value);
//
//	RedisReply* SetRange(const char *key, int offset, int value);
//
//	RedisReply* MSet(const Pairs& pairs);
//
//	RedisReply* MSetNX(const Pairs& pairs);
//
//	RedisReply* Append(const char *key, const char *value);
//
//	RedisReply* Append(const char *key, int value);
//
//	RedisReply* Get(const char *key);
//
//	RedisReply* MGet(const KFList& keylist);
//
//	RedisReply* GetRange(const char *key, int start, int end);
//
//	RedisReply* GetSet(const char *key, const char *value);
//
//	RedisReply* GetSet(const char *key, int value);
//
//	RedisReply* StrLen(const char *key);
//
//	RedisReply* Decr(const char *key);
//
//	RedisReply* DecrBy(const char *key, int decr);
//
	RedisReply* Incr(const char *key);
//
//	RedisReply* IncrBy(const char *key, int incr);
//
//	RedisReply* SetBit(const char *key, int offset, int value);
//
//	RedisReply* GetBit(const char *key, int offset);
//
//	RedisReply* BitOP(const char *op, const char *destkey, const KFList& keylist);
//
//	RedisReply* BitCount(const char *key);
//
//	RedisReply* BitCount(const char *key, int start, int end);
//
	RedisReply* HSet(const char *key, const char *field, const char *value);

	RedisReply* HSet(const char *key, const char *field, int value);

	RedisReply* HSetNX(const char *key, const char *field, const char *value);

	RedisReply* HSetNX(const char *key, const char *field, int value);

	RedisReply* HMSet(const char *key, const Pairs& pairs);

	RedisReply* HGet(const char *key, const char *field);

	RedisReply* HMGet(const char *key, const KFList& fieldlist);

	RedisReply* HGetAll(const char *key);

	RedisReply* HDel(const char *key, const char *field);

	RedisReply* HDel(const char *key, const KFList& fieldlist);

	RedisReply* HLen(const char *key);

	RedisReply* HExists(const char *key, const char *field);

	RedisReply* HIncrBy(const char *key, const char *field, int increment);

	RedisReply* HIncrByFloat(const char *key, const char *field, double increment);

	RedisReply* HKeys(const char *key);

	RedisReply* HVals(const char *key);

	bool LPush(const char *key, const char *value);

	bool LPush(const char *key, int value);

	bool LPush(const char *key, const KFList& valuelist);

	RedisReply* LPushX(const char *key, const char *value);

	RedisReply* LPushX(const char *key, int value);

	RedisReply* RPush(const char *key, const char *value);

	RedisReply* RPush(const char *key, int value);

	RedisReply* RPush(const char *key, const KFList& valuelist);

	RedisReply* RPushX(const char *key, const char *value);

	RedisReply* RPushX(const char *key, int value);

	RedisReply* LPop(const char *key);

	RedisReply* RPop(const char *key);

	RedisReply* BLPop(const char *key, int timeout);

	RedisReply* BRPop(const char *key, int timeout);

	RedisReply* BLPop(const KFList& keylist, int timeout);

	RedisReply* BRPop(const KFList& keylist, int timeout);

	RedisReply* LLen(const char *key);

	RedisReply* LRange(const char *key, int start, int end);

	bool LRem(const char *key, int count, const char *value);

	bool LRem(const char *key, int count, int value);

	RedisReply* LSet(const char *key, int index, const char *value);

	RedisReply* LSet(const char *key, int index, int value);

	RedisReply* LTrim(const char *key, int start, int stop);

	RedisReply* LIndex(const char *key, int index);

	RedisReply* LInsertBefore(const char *key, const char *pivot, const char *value);

	RedisReply* LInsertBefore(const char *key, const char *pivot, int value);

	RedisReply* LInsertAfter(const char *key, const char *pivot, const char *value);

	RedisReply* LInsertAfter(const char *key, const char *pivot, int value);

	RedisReply* RPopLPush(const char *source, const char *destination);

	RedisReply* BRPopLPush(const char *source, const char *destination, int timeout);

	RedisReply* SAdd(const char *key, const char *member);

	RedisReply* SAdd(const char *key, int member);

	RedisReply* SAdd(const char *key, const KFList& members);

	RedisReply* SRem(const char *key, const char *member);

	RedisReply* SRem(const char *key, int member);

	RedisReply* SRem(const char *key, const KFList& members);

	RedisReply* SMembers(const char *key);

	RedisReply* SIsMember(const char *key, const char *member);

	RedisReply* SIsMember(const char *key, int member);

	RedisReply* SCard(const char *key);

	RedisReply* SMove(const char *source, const char *destination, const char *member);

	RedisReply* SMove(const char *source, const char *destination, int member);

	RedisReply* SPop(const char *key);

	RedisReply* SRandMember(const char *key);

	RedisReply* SRandMember(const char *key, int count);

	RedisReply* SInter(const KFList& keys);

	RedisReply* SInterStore(const char *destination, const char *key1, const char *key2);

	RedisReply* SInterStore(const char *destination, const KFList& keys);

	RedisReply* SUnion(const KFList& keys);

	RedisReply* SUnionStore(const char *destination, const KFList& keys);

	RedisReply* SDiff(const KFList& keys);

	RedisReply* SDiffStore(const char *destination, const KFList& keys);

//	RedisReply* ZAdd(const char *key, int score, const char *member);
//
//	RedisReply* ZAdd(const char *key, double score, const char *member);
//
//	RedisReply* ZAdd(const char *key, const Pairs& pairs);
//
//	RedisReply* ZRem(const char *key, const char *member);
//
//	RedisReply* ZRem(const char *key, const KFList& member);
//
//	RedisReply* ZCard(const char *key);
//
//	RedisReply* ZCount(const char *key, int min, int max);
//
//	RedisReply* ZScore(const char *key, const char *member);
//
//	RedisReply* ZIncrBy(const char *key, int increment, const char *member);
//
//	RedisReply* ZIncrBy(const char *key, double incrememt, const char *member);
//
//	RedisReply* ZRange(const char *key, int start, int stop);
//
//	RedisReply* ZRangeWithScores(const char *key, int start, int stop);
//
//	RedisReply* ZRevRange(const char *key, int start, int stop);
//
//	RedisReply* ZRevRangeWithScores(const char *key, int start, int stop);
//
//	RedisReply* ZRangeByScore(const char *key, int min, int max, const SortCondition& sc);
//
//	RedisReply* ZRevRangeByScore(const char *key, int max, int min, const SortCondition& sc);
//
//	RedisReply* ZRank(const char *key, const char *member);
//
//	RedisReply* ZRevRank(const char *key, const char *member);
//
//	RedisReply* ZRemRangeByRank(const char *key, int start, int stop);
//
//	RedisReply* ZRemRangeByScore(const char *key, int min, int max);
//
//	RedisReply* Publish(const char *channel, const char *message);
//
//	RedisReply* Subscribe(const char *channel);
//
//	RedisReply* Subscribe(const KFList& channellist);
//
//	RedisReply* PSubscribe(const char *pattern);
//
//	RedisReply* PSubscribe(const KFList& patternlist);
//
//	RedisReply* Unsubscribe(const char *channel);
//
//	RedisReply* Unsubscribe(const KFList& channellist);
//
//	RedisReply* PUnsubscribe(const char *pattern);
//
//	RedisReply* PUnsubscribe(const KFList& patternlist);
//
	void Watch(const char *key);

	void Watch(const KFList& keylist);

	void Unwatch();

	void Multi();

	void Discard();

	RedisReply* Exec();

private:

	redisContext *m_RedisClient;

	RedisReply* RedisCommand(const char *command, ...);

};

#endif /* REDISSERVER_H_ */
