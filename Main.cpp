/*
 * Main.cpp
 *
 *  Created on: 2012-10-14
 *      Author: root
 */

#include "RpcServer/Server.h"
#include "Api/Apis.h"
#include "Exception/BaseException.h"

int apiCount = sizeof(apis)/sizeof(apis[0]);

std::vector<void*> EFArray = std::vector<void*>();

void* Clear(void*) {
	while(1) {
		std::vector<void*>::iterator it = EFArray.begin();
		for (; it != EFArray.end(); it++) {
			EntityFactory<BaseEntity> *ef = (EntityFactory<BaseEntity>*)*it;
			ef->Clear();
		}
		sleep(3600);
	}
	return 0;
}

int main(){
	std::cout<<"start main ......"<<std::endl;
	Server *s = new Server();
	s->InitApiMap(apis, apiCount);
	pthread_t id;
	pthread_create(&id, NULL, Clear, NULL);
	while (s->Accept() >= 0){
		try {
			s->Process();
		} catch(const BaseException &ex) {
			ExceptionHandle(ex);
		}
	}
}



