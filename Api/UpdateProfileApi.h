/*
 * UpdateProfileApi.h
 *
 *  Created on: 2012-10-27
 *      Author: root
 */

#ifndef UPDATEPROFILEAPI_H_
#define UPDATEPROFILEAPI_H_

#include "Api.h"
#include "../Entity/UserEntity.h"

class UpdateProfileApi : public Api {
public:

	UpdateProfileApi();

	~UpdateProfileApi();

	virtual BsonObj* Process(const BsonObj& paramMap);

};


#endif /* UPDATEPROFILEAPI_H_ */
