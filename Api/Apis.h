/*
 * Apis.h
 *
 *  Created on: 2012-10-17
 *      Author: root
 */

#ifndef APIS_H_
#define APIS_H_

#include "RegisterApi.h"
#include "LoginApi.h"
#include "UpdateProfileApi.h"
#include "GetProfileApi.h"

RegisterApi registerApi;
LoginApi loginApi;
UpdateProfileApi updateProfileApi;
GetProfileApi getProfileApi;

Api* apis[] = {
		&registerApi,
		&loginApi,
		&updateProfileApi,
		&getProfileApi
};



#endif /* APIS_H_ */
