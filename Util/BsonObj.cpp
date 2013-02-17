/*
 * BsonObj.cpp
 *
 *  Created on: 2012-12-8
 *      Author: root
 */

#include "BsonObj.h"

BsonObj::BsonObj() {
	bson_init(this->obj);
	bson_finish(this->obj);
}

BsonObj::BsonObj(bson* bobj) {
	this->obj = bobj;
}

BsonObj::~BsonObj() {
	bson_destroy(this->obj);
	free(this->obj);
}

bool BsonObj::set(const char *key, const char *value) {
	bson_append_string(this->obj, key, value);
	return bson_finish(this->obj) == BSON_OK;
}

bool BsonObj::set(const char *key, int value) {
	bson_append_int(this->obj, key, value);
	return bson_finish(this->obj) == BSON_OK;
}

bool BsonObj::set(const char *key, bool value) {
	bson_append_bool(this->obj, key, value);
	return bson_finish(this->obj) == BSON_OK;
}

const bson* BsonObj::get() const {
	return this->obj;
}

const char* BsonObj::getByKey(const char *key) const {
	bson_iterator *i;
	bson_type type = bson_find(i, this->obj, key);
	if (type == BSON_EOO) {
		return "";
	}
	return bson_iterator_string(i);
}

const char* BsonObj::getData() const {
	return this->obj->data;
}

const char* BsonObj::GetValue(const char *key) const {
	bson_iterator *i;
	bson_find(i, this->obj, key);
	const char *value = bson_iterator_value(i);
	return value;
}



