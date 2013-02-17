/*
 * BsonObj.h
 *
 *  Created on: 2012-12-8
 *      Author: root
 */

#ifndef BSONOBJ_H_
#define BSONOBJ_H_

#include <bson.h>
#include "../Exception/BaseException.h"

class BsonObj {
public:

	BsonObj();

	BsonObj(bson* bobj);

	~BsonObj();

	bool set(const char *key, const char *value);

	bool set(const char *key, int value);

	bool set(const char *key, bool value);

	const bson* get() const;

	const char* getByKey(const char *key) const;

	const char* getData() const;

	const char* GetValue(const char *key) const;

private:

	bson* obj;

	BsonObj(const BsonObj&);

	BsonObj& operator=(const BsonObj&);

};



#endif /* BSONOBJ_H_ */
