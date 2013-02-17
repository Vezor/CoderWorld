/*
 * UpdateProfileApi.cpp
 *
 *  Created on: 2012-10-27
 *      Author: root
 */

#include "UpdateProfileApi.h"

UpdateProfileApi::UpdateProfileApi() : Api("/user/profile/update.cgi", false, NULL) {}

UpdateProfileApi::~UpdateProfileApi() {}

BsonObj* UpdateProfileApi::Process(const BsonObj& paramMap) {
	const char *id = paramMap.getByKey("id");
	UserEntity *ue = UEFactory.GetEntity(id);
	bool res = ue->SetHugeEntity(paramMap);
	BsonObj *bobj = new BsonObj();
	bobj->set("res", res);
	return bobj;
}


