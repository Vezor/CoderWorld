/*
 * LoginApi.cpp
 *
 *  Created on: 2012-10-27
 *      Author: root
 */

#include "LoginApi.h"

LoginApi::LoginApi() : Api("/login.cgi", true, NULL) {
	const char *name = "id";
	this->m_RespNames = &name;
}

LoginApi::~LoginApi() {}

BsonObj* LoginApi::Process(const BsonObj& paramMap) {
	const char *account = paramMap.getByKey("account");
	const char *password = paramMap.getByKey("password");
	HugeEntityServer *hes = HEPool.ObtainObject();
	BsonObj query;
	query.set("account", account);
	query.set("password", (const char*)md5(password));
	BsonObj* res = hes->Select("CodeWorld.user", query);
	HEPool.ReturnObject(hes);
	return res;
}


