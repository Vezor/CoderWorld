/*
 * GetProfileApi.cpp
 *
 *  Created on: 2012-10-27
 *      Author: root
 */

#include "GetProfileApi.h"

GetProfileApi::GetProfileApi() : Api("/user/profile/get.cgi", false, NULL) {}

GetProfileApi::~GetProfileApi() {}

BsonObj* GetProfileApi::Process(const BsonObj& paramMap) {
	const char *id = paramMap.getByKey("id");
	UserEntity *ue = UEFactory.GetEntity(id);
	return ue->GetHugeEntity();
}
