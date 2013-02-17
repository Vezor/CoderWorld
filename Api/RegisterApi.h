/*
 * RegisterApi.h
 *
 *  Created on: 2012-10-27
 *      Author: root
 */

#ifndef REGISTERAPI_H_
#define REGISTERAPI_H_

#include "Api.h"
#include "../Entity/UserEntity.h"

class RegisterApi : public Api {
public:

	RegisterApi();

	~RegisterApi();

	BsonObj* Process(const BsonObj& paramMap);

};


#endif /* REGISTERAPI_H_ */
