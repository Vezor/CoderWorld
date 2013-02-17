/*
 * RegisterApi.cpp
 *
 *  Created on: 2012-10-27
 *      Author: root
 */

#include "RegisterApi.h"

RegisterApi::RegisterApi() : Api("/register.cgi", false, NULL) {}

RegisterApi::~RegisterApi() {}

BsonObj* RegisterApi::Process(const BsonObj& paramMap) {
	IDGenerator *idg = IDGPool.ObtainObject();
	UserEntity *ue = UEFactory.GetEntity(idg->NextID(UserEntity::m_EntityName));
	IDGPool.ReturnObject(idg);
	bool res = ue->SetHugeEntity(paramMap);
	if (res) {
		BsonObj *bobj = new BsonObj();
		bobj->set("id", ue->GetID());
		return bobj;
	}
	BsonObj *bobj = new BsonObj();
	return bobj;
}

