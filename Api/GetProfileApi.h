/*
 * GetProfileApi.h
 *
 *  Created on: 2012-10-27
 *      Author: root
 */

#ifndef GETPROFILEAPI_H_
#define GETPROFILEAPI_H_

#include "Api.h"
#include "../Entity/UserEntity.h"

class GetProfileApi : public Api {
public:

	GetProfileApi();

	~GetProfileApi();

	virtual BsonObj* Process(const BsonObj& paramMap);

};


#endif /* GETPROFILEAPI_H_ */
