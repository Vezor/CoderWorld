/*
 * LoginApi.h
 *
 *  Created on: 2012-10-27
 *      Author: root
 */

#ifndef LOGINAPI_H_
#define LOGINAPI_H_

#include "Api.h"
#include "../Entity/UserEntity.h"
#include "../Util/Util.h"

class LoginApi : public Api {
public:

	LoginApi();

	~LoginApi();

	virtual BsonObj* Process(const BsonObj& paramMap);

};


#endif /* LOGINAPI_H_ */
