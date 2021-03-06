/*
 * RedisServer.cpp
 *
 *  Created on: 2012-11-4
 *      Author: root
 */

#include "RedisServer.h"

RedisReply::RedisReply() : m_Reply(NULL) {}

RedisReply::RedisReply(redisReply *reply) : m_Reply(reply) {}

RedisReply::~RedisReply() {
	freeReplyObject(this->m_Reply);
}

int RedisReply::GetInt() const {
	return this->m_Reply->integer;
}

const char* RedisReply::GetString() const {
	return this->m_Reply->str;
}

int RedisReply::GetStrLen() const {
	return this->m_Reply->len;
}

char** RedisReply::GetElement() const {
	redisReply **replys = this->m_Reply->element;
	size_t count = this->m_Reply->elements;
	char **res = new char*[count];
	for (size_t idx = 0; idx < count; idx++) {
		redisReply *reply = *(replys + idx);
		char *element = new char[reply->len + 1];
		res[idx] = element;
		strcpy(element, reply->str);
	}
	return res;
}

size_t RedisReply::GetElementsSize() const {
	return this->m_Reply->elements;
}

RedisServer::RedisServer() {
	this->m_RedisClient = redisConnect("127.0.0.1", port);
}

RedisServer::~RedisServer() {
	redisFree(this->m_RedisClient);
}

bool RedisServer::IsAvailable() {
	return !(this->m_RedisClient->err);
}

RedisReply* RedisServer::RedisCommand(const char *command, ...) {
	va_list args;
	va_start(args, command);
	redisReply *reply = static_cast<redisReply*>(redisvCommand(this->m_RedisClient, command, args));
	va_end(args);
	if (reply == NULL) {
		throw BaseException(REDIS_SERVER_ERROR, this->m_RedisClient->errstr);
	}
	return new RedisReply(reply);
}

bool RedisServer::Del(const char  *key) {
	return RedisCommand("del %s", key)->GetInt() > 0;
}

RedisReply* RedisServer::Keys(const char *key) {
	return RedisCommand("keys %s", key);
}

RedisReply* RedisServer::RandomKey() {
	return RedisCommand("randomkey");
}

RedisReply* RedisServer::TTL(const char *key) {
	return RedisCommand("ttl %s", key);
}

RedisReply* RedisServer::PTTL(const char *key) {
	return RedisCommand("pttl %s", key);
}

bool RedisServer::Exists(const char *key) {
	return RedisCommand("exists %s", key)->GetInt() == 1;
}

RedisReply* RedisServer::Move(const char *key, unsigned int id) {
	return RedisCommand("move %s %d", key, id);
}

RedisReply* RedisServer::Rename(const char *key, const char *newkey) {
	return RedisCommand("rename %s %s", key, newkey);
}

RedisReply* RedisServer::RenameNX(const char *key, const char *newkey) {
	return RedisCommand("renamenx s% s%", key, newkey);
}

RedisReply* RedisServer::Type(const char *key) {
	return RedisCommand("type %s", key);
}

RedisReply* RedisServer::Expire(const char *key, unsigned int second) {
	return RedisCommand("expire %s %d", key, second);
}

RedisReply* RedisServer::PExpire(const char *key, unsigned int millisecond) {
	return RedisCommand("pexpire %s %d", key, millisecond);
}

RedisReply* RedisServer::ExpireAT(const char *key, unsigned int timestamp) {
	return RedisCommand("expireat %s %d", key, time);
}

RedisReply* RedisServer::PExpireAT(const char *key, unsigned int millitimestamp) {
	return RedisCommand("pexpireat %s %d", key, millitimestamp);
}

RedisReply* RedisServer::Persist(const char *key) {
	return RedisCommand("persist %s", key);
}

RedisReply* RedisServer::Sort(const char *key, const SortCondition& sc) {
	return RedisCommand("sort %s %s", key, sc.getCondition());
}

//RedisReply* RedisServer::Set(const char *key, const char *value) {
//	return RedisCommand("set %s \"%s\"", key, value);
//}
//
//RedisReply* RedisServer::Set(const char *key, int value) {
//	return RedisCommand("set %s %d", key, value);
//}
//
//RedisReply* RedisServer::SetNX(const char *key, const char *value) {
//	return RedisCommand("setnx %s \"%s\"", key, value);
//}
//
//RedisReply* RedisServer::SetNX(const char *key, int value) {
//	return RedisCommand("setnx %s %d", key, value);
//}
//
//RedisReply* RedisServer::SetEX(const char *key, int second, const char *value) {
//	return RedisCommand("setex %s %d \"%s\"", key, second, value);
//}
//
//RedisReply* RedisServer::SetEX(const char *key, int second, int value) {
//	return RedisCommand("setex %s %d %d", key, second, value);
//}
//
//RedisReply* RedisServer::PSetEX(const char *key, int millisecond, const char *value) {
//	return RedisCommand("psetex %s %d \"%s\"", key, millisecond, value);
//}
//
//RedisReply* RedisServer::PSetEX(const char *key, int millisecond, int value) {
//	return RedisCommand("psetex %s %d %d", key, millisecond, value);
//}
//
//RedisReply* RedisServer::SetRange(const char *key, int offset, const char *value) {
//	return RedisCommand("setrange %s %d \"%s\"", key, offset, value);
//}
//
//RedisReply* RedisServer::SetRange(const char *key, int offset, int value) {
//	return RedisCommand("setrange %s %d %d", key, offset, value);
//}
//
//RedisReply* RedisServer::MSet(const Pairs& pairs) {
//	return RedisCommand("mset %s", pairs.GetPairs());
//}
//
//RedisReply* RedisServer::MSetNX(const Pairs& pairs) {
//	return RedisCommand("msetnx %s", pairs.GetPairs());
//}
//
//RedisReply* RedisServer::Append(const char *key, const char *value) {
//	return RedisCommand("append %s \"%s\"", key, value);
//}
//
//RedisReply* RedisServer::Append(const char *key, int value) {
//	return RedisCommand("append %s %d", key, value);
//}
//
//RedisReply* RedisServer::Get(const char *key) {
//	return RedisCommand("get %s", key);
//}
//
//RedisReply* RedisServer::MGet(const KFList& keylist) {
//	return RedisCommand("mget %s", keylist.GetList());
//}
//
//RedisReply* RedisServer::GetRange(const char *key, int start, int end) {
//	return RedisCommand("getrange %s %d %d", key, start, end);
//}
//
//RedisReply* RedisServer::GetSet(const char *key, const char *value) {
//	return RedisCommand("getset %s \"%s\"", key, value);
//}
//
//RedisReply* RedisServer::GetSet(const char *key, int value) {
//	return RedisCommand("getset %s %d", key, value);
//}
//
//RedisReply* RedisServer::StrLen(const char *key) {
//	return RedisCommand("strlen %s", key);
//}
//
//RedisReply* RedisServer::Decr(const char *key) {
//	return RedisCommand("decr %s", key);
//}
//
//RedisReply* RedisServer::DecrBy(const char *key, int decr) {
//	return RedisCommand("decrby %s %d", key, decr);
//}
//
RedisReply* RedisServer::Incr(const char *key) {
	return RedisCommand("incr %s", key);
}
//
//RedisReply* RedisServer::IncrBy(const char *key, int incr) {
//	return RedisCommand("incrby %s %d", key, incr);
//}
//
//RedisReply* RedisServer::SetBit(const char *key, int offset, int value) {
//	return RedisCommand("setbit %s %d %d", key, offset, value);
//}
//
//RedisReply* RedisServer::GetBit(const char *key, int offset) {
//	return RedisCommand("getbit %s %d", key, offset);
//}
//
//RedisReply* RedisServer::BitOP(const char *op, const char *destkey, const KFList& keylist) {
//	return RedisCommand("bitop %s %s %s", op, destkey, keylist.GetList());
//}
//
//RedisReply* RedisServer::BitCount(const char *key) {
//	return RedisCommand("bitcount %s", key);
//}
//
//RedisReply* RedisServer::BitCount(const char *key, int start, int end) {
//	return RedisCommand("bitcount %s %d %d", key, start, end);
//}
//
RedisReply* RedisServer::HSet(const char *key, const char *field, const char *value) {
	return RedisCommand("hset %s %s \"%s\"", key, field, value);
}

RedisReply* RedisServer::HSet(const char *key, const char *field, int value) {
	return RedisCommand("hset %s %s %d", key, field, value);
}

RedisReply* RedisServer::HSetNX(const char *key, const char *field, const char *value) {
	return RedisCommand("hsetnx %s %s \"%s\"", key, field, value);
}

RedisReply* RedisServer::HSetNX(const char *key, const char *field, int value) {
	return RedisCommand("hsetnx %s %s %d", key, field, value);
}

RedisReply* RedisServer::HMSet(const char *key, const Pairs& pairs) {
	return RedisCommand("hmset %s %s", key, pairs.GetPairs());
}

RedisReply* RedisServer::HGet(const char *key, const char *field) {
	return RedisCommand("hget %s %s", key, field);
}

RedisReply* RedisServer::HMGet(const char *key, const KFList& fieldlist) {
	return RedisCommand("hmget %s %s", key, fieldlist.GetList());
}

RedisReply* RedisServer::HGetAll(const char *key) {
	return RedisCommand("hgetall %s", key);
}

RedisReply* RedisServer::HDel(const char *key, const char *field) {
	return RedisCommand("hdel %s %s", key, field);
}

RedisReply* RedisServer::HDel(const char *key, const KFList& fieldlist) {
	return RedisCommand("hdel %s %s", key, fieldlist.GetList());
}

RedisReply* RedisServer::HLen(const char *key) {
	return RedisCommand("hlen %s", key);
}

RedisReply* RedisServer::HExists(const char *key, const char *field) {
	return RedisCommand("hexists %s %s", key, field);
}

RedisReply* RedisServer::HIncrBy(const char *key, const char *field, int increment) {
	return RedisCommand("hincrby %s %s %d", key, field, increment);
}

RedisReply* RedisServer::HIncrByFloat(const char *key, const char *field, double increment) {
	return RedisCommand("hincrbyfloat %s %s %f", key, field, increment);
}

RedisReply* RedisServer::HKeys(const char *key) {
	return RedisCommand("hkeys %s", key);
}

RedisReply* RedisServer::HVals(const char *key) {
	return RedisCommand("hvals %s", key);
}

bool RedisServer::LPush(const char *key, const char *value) {
	return RedisCommand("lpush %s \"%s\"", key, value)->GetInt() > 0;
}

bool RedisServer::LPush(const char *key, int value) {
	return RedisCommand("lpush %s %d", key, value)->GetInt() > 0;
}

bool RedisServer::LPush(const char *key, const KFList& valuelist) {
	return RedisCommand("lpush %s %s", key, valuelist.GetList())->GetInt() > 0;
}

RedisReply* RedisServer::LPushX(const char *key, const char *value) {
	return RedisCommand("lpushx %s %s", key, value);
}

RedisReply* RedisServer::LPushX(const char *key, int value) {
	return RedisCommand("lpushx %s %d", key, value);
}

RedisReply* RedisServer::RPush(const char *key, const char *value) {
	return RedisCommand("rpush %s \"%s\"", key, value);
}

RedisReply* RedisServer::RPush(const char *key, int value) {
	return RedisCommand("rpush %s %d", key, value);
}

RedisReply* RedisServer::RPush(const char *key, const KFList& valuelist) {
	return RedisCommand("rpush %s %s", key, valuelist.GetList());
}

RedisReply* RedisServer::RPushX(const char *key, const char *value) {
	return RedisCommand("rpushx %s %s", key, value);
}

RedisReply* RedisServer::RPushX(const char *key, int value) {
	return RedisCommand("rpushx %s %d", key, value);
}

RedisReply* RedisServer::LPop(const char *key) {
	return RedisCommand("lpop %s", key);
}

RedisReply* RedisServer::RPop(const char *key) {
	return RedisCommand("rpop %s", key);
}

RedisReply* RedisServer::BLPop(const char *key, int timeout) {
	return RedisCommand("blpop %s %d", key, timeout);
}

RedisReply* RedisServer::BRPop(const char *key, int timeout) {
	return RedisCommand("brpop %s %d", key, timeout);
}

RedisReply* RedisServer::BLPop(const KFList& keylist, int timeout) {
	return RedisCommand("blpop %s %d", keylist.GetList(), timeout);
}

RedisReply* RedisServer::BRPop(const KFList& keylist, int timeout) {
	return RedisCommand("brpop %s %d", keylist.GetList(), timeout);
}

RedisReply* RedisServer::LLen(const char *key) {
	return RedisCommand("llen %s", key);
}

RedisReply* RedisServer::LRange(const char *key, int start, int end) {
	return RedisCommand("lrange %s %d %d", key, start, end);
}

bool RedisServer::LRem(const char *key, int count, const char *value) {
	return RedisCommand("lrem %s %d \"%s\"", key, count, value)->GetInt() > 0;
}

bool RedisServer::LRem(const char *key, int count, int value) {
	return RedisCommand("lrem %s %d %d", key, count, value)->GetInt() > 0;
}

RedisReply* RedisServer::LSet(const char *key, int index, const char *value) {
	return RedisCommand("lset %s %d %\"s\"", key, index, value);
}

RedisReply* RedisServer::LSet(const char *key, int index, int value) {
	return RedisCommand("lset %s %d %d", key, index, value);
}

RedisReply* RedisServer::LTrim(const char *key, int start, int stop) {
	return RedisCommand("ltrim %s %d %d", key, start, stop);
}

RedisReply* RedisServer::LIndex(const char *key, int index) {
	return RedisCommand("lindex %s %d", key, index);
}

RedisReply* RedisServer::LInsertBefore(const char *key, const char *pivot, const char *value) {
	return RedisCommand("linsertbefore %s before %s %s", key, pivot, value);
}

RedisReply* RedisServer::LInsertBefore(const char *key, const char *pivot, int value) {
	return RedisCommand("linsertbefore %s before %s %d", key, pivot, value);
}

RedisReply* RedisServer::LInsertAfter(const char *key, const char *pivot, const char *value) {
	return RedisCommand("linsertbefore %s after %s %s", key, pivot, value);
}

RedisReply* RedisServer::LInsertAfter(const char *key, const char *pivot, int value) {
	return RedisCommand("linsertbefore %s after %s %d", key, pivot, value);
}

RedisReply* RedisServer::RPopLPush(const char *source, const char *destination) {
	return RedisCommand("rpoplpush %s %s", source, destination);
}

RedisReply* RedisServer::BRPopLPush(const char *source, const char *destination, int timeout) {
	return RedisCommand("brpoplpush %s %s %d", source, destination, timeout);
}

RedisReply* RedisServer::SAdd(const char *key, const char *member) {
	return RedisCommand("sadd %s \"%s\"", key, member);
}

RedisReply* RedisServer::SAdd(const char *key, int member) {
	return RedisCommand("sadd %s %d", key, member);
}

RedisReply* RedisServer::SAdd(const char *key, const KFList& members) {
	return RedisCommand("sadd %s %s", key, members.GetList());
}

RedisReply* RedisServer::SRem(const char *key, const char *member) {
	return RedisCommand("srem %s \"%s\"", key, member);
}

RedisReply* RedisServer::SRem(const char *key, int member) {
	return RedisCommand("srem %s %d", key, member);
}

RedisReply* RedisServer::SRem(const char *key, const KFList& members) {
	return RedisCommand("srem %s %s", key, members.GetList());
}

RedisReply* RedisServer::SMembers(const char *key) {
	return RedisCommand("smembers %s", key);
}

RedisReply* RedisServer::SIsMember(const char *key, const char *member) {
	return RedisCommand("sismember %s \"%s\"", key, member);
}

RedisReply* RedisServer::SIsMember(const char *key, int member) {
	return RedisCommand("sismember %s %d");
}

RedisReply* RedisServer::SCard(const char *key) {
	return RedisCommand("scard %s", key);
}

RedisReply* RedisServer::SMove(const char *source, const char *destination, const char *member) {
	return RedisCommand("smove %s %s %s", source, destination, member);
}

RedisReply* RedisServer::SMove(const char *source, const char *destination, int member) {
	return RedisCommand("smove %s %s %d", source, destination, member);
}

RedisReply* RedisServer::SPop(const char *key) {
	return RedisCommand("spop %s", key);
}

RedisReply* RedisServer::SRandMember(const char *key) {
	return RedisCommand("srandmember %s", key);
}

RedisReply* RedisServer::SRandMember(const char *key, int count) {
	return RedisCommand("srandmember %s %d", key, count);
}

RedisReply* RedisServer::SInter(const KFList& keys) {
	return RedisCommand("sinter %s", keys.GetList());
}

RedisReply* RedisServer::SInterStore(const char *destination, const char *key1, const char *key2) {
	return RedisCommand("sinterstore %s %s %s", destination, key1, key2);
}

RedisReply* RedisServer::SInterStore(const char *destination, const KFList& keys) {
	return RedisCommand("sinterstore %s %s", destination, keys.GetList());
}

RedisReply* RedisServer::SUnion(const KFList& keys) {
	return RedisCommand("sunion %s", keys.GetList());
}

RedisReply* RedisServer::SUnionStore(const char *destination, const KFList& keys) {
	return RedisCommand("sunion %s %s", destination, keys.GetList());
}

RedisReply* RedisServer::SDiff(const KFList& keys) {
	return RedisCommand("sdiff %s", keys.GetList());
}

RedisReply* RedisServer::SDiffStore(const char *destination, const KFList& keys) {
	return RedisCommand("sdiff %s %s", destination, keys.GetList());
}

//RedisReply* RedisServer::ZAdd(const char *key, int score, const char *member) {
//	return RedisCommand("zadd %s %d %s", key, score, member);
//}
//
//RedisReply* RedisServer::ZAdd(const char *key, double score, const char *member) {
//	return RedisCommand("zadd %s %f %s", key, score, member);
//}
//
//RedisReply* RedisServer::ZAdd(const char *key, const Pairs& pairs) {
//	return RedisCommand("zadd %s %s", key, pairs.GetPairs());
//}
//
//RedisReply* RedisServer::ZRem(const char *key, const char *member) {
//	return RedisCommand("zrem %s \"%s\"", key, member);
//}
//
//RedisReply* RedisServer::ZRem(const char *key, const KFList& member) {
//	return RedisCommand("zrem %s %s", key, member.GetList());
//}
//
//RedisReply* RedisServer::ZCard(const char *key) {
//	return RedisCommand("zcard %s", key);
//}
//
//RedisReply* RedisServer::ZCount(const char *key, int min, int max) {
//	return RedisCommand("zcount %s %d %d", key, min, max);
//}
//
//RedisReply* RedisServer::ZScore(const char *key, const char *member) {
//	return RedisCommand("zscore %s %s", key, member);
//}
//
//RedisReply* RedisServer::ZIncrBy(const char *key, int increment, const char *member) {
//	return RedisCommand("zincrby %s %d %s", key, increment, member);
//}
//
//RedisReply* RedisServer::ZIncrBy(const char *key, double increment, const char *member) {
//	return RedisCommand("zincrby %s %f %s", key, increment, member);
//}
//
//RedisReply* RedisServer::ZRange(const char *key, int start, int stop) {
//	return RedisCommand("zrange %s %d %d", key, start, stop);
//}
//
//RedisReply* RedisServer::ZRangeWithScores(const char *key, int start, int stop) {
//	return RedisCommand("zrange %s %d %d withscores", key, start, stop);
//}
//
//RedisReply* RedisServer::ZRevRange(const char *key, int start, int stop) {
//	return RedisCommand("zrevrange %s %d %d", key, start, stop);
//}
//
//RedisReply* RedisServer::ZRevRangeWithScores(const char *key, int start, int stop) {
//	return RedisCommand("zrevrange %s %d %d withscores", key, start, stop);
//}
//
//RedisReply* RedisServer::ZRangeByScore(const char *key, int min, int max, const SortCondition& sc) {
//	return RedisCommand("zrangebyscore %s %d %d %s", key, min, max, sc.getCondition());
//}
//
//RedisReply* RedisServer::ZRevRangeByScore(const char *key, int max, int min, const SortCondition& sc) {
//	return RedisCommand("zrevrangebyscore %s %d %d %s", key, max, min, sc.getCondition());
//}
//
//RedisReply* RedisServer::ZRank(const char *key, const char *member) {
//	return RedisCommand("zrank %s %s", key, member);
//}
//
//RedisReply* RedisServer::ZRevRank(const char *key, const char *member) {
//	return RedisCommand("zrevrank %s %s", key, member);
//}
//
//RedisReply* RedisServer::ZRemRangeByRank(const char *key, int start, int stop) {
//	return RedisCommand("zremrangebyrank %s %d %d", key, start, stop);
//}
//
//RedisReply* RedisServer::ZRemRangeByScore(const char *key, int min, int max) {
//	return RedisCommand("zremrangebyscore %s %d %d", key, min, max);
//}
//
//RedisReply* RedisServer::Publish(const char *channel, const char *message) {
//	return RedisCommand("publish %s \"%s\"", channel, message);
//}
//
//RedisReply* RedisServer::Subscribe(const char *channel) {
//	return RedisCommand("subscribe %s", channel);
//}
//
//RedisReply* RedisServer::Subscribe(const KFList& channellist) {
//	return RedisCommand("subscribe %s", channellist.GetList());
//}
//
//RedisReply* RedisServer::PSubscribe(const char *pattern) {
//	return RedisCommand("psubscribe %s", pattern);
//}
//
//RedisReply* RedisServer::PSubscribe(const KFList& patternlist) {
//	return RedisCommand("psubscribe %s", patternlist.GetList());
//}
//
//RedisReply* RedisServer::Unsubscribe(const char *channel) {
//	return RedisCommand("unsubscribe %s", channel);
//}
//
//RedisReply* RedisServer::Unsubscribe(const KFList& channellist) {
//	return RedisCommand("unsubscribe %s", channellist.GetList());
//}
//
//RedisReply* RedisServer::PUnsubscribe(const char *pattern) {
//	return RedisCommand("punsubscribe %s", pattern);
//}
//
//RedisReply* RedisServer::PUnsubscribe(const KFList& patternlist) {
//	return RedisCommand("punsubscribe %s", patternlist.GetList());
//}
//
void RedisServer::Watch(const char *key) {
	RedisCommand("watch %s", key);
}

void RedisServer::Watch(const KFList& keylist) {
	RedisCommand("watch %s", keylist.GetList());
}

void RedisServer::Unwatch() {
	RedisCommand("unwatch");
}

void RedisServer::Multi() {
	RedisCommand("multi");
}

void RedisServer::Discard() {
	RedisCommand("discard");
}

RedisReply* RedisServer::Exec() {
	return RedisCommand("exec");
}
