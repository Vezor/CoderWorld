/*
 * EntityFactory.h
 *
 *  Created on: 2013-2-5
 *      Author: root
 */

#ifndef ENTITYFACTORY_H_
#define ENTITYFACTORY_H_

#include "BaseEntity.h"

typedef str_equal_to<const char*> en_equal;

typedef __gnu_cxx::hash_map< const char*, BaseEntity*, __gnu_cxx::hash<const char*>, en_equal> EntityMap;

extern std::vector<void*> EFArray;

template<class Type> class EntityFactory {
public:

	EntityFactory();

	~EntityFactory();

	Type* GetEntity(const char *id);

	void Clear(void);

private:

	EntityMap m_EntityMap;


};

template<class Type> EntityFactory<Type>::EntityFactory() {
	EFArray.push_back(this);
}

template<class Type> EntityFactory<Type>::~EntityFactory() {}

template<class Type> Type* EntityFactory<Type>::GetEntity(const char *id) {
	EntityMap::iterator it = this->m_EntityMap.find(id);
	if (it != this->m_EntityMap.end()) {
		it->second->SetLastUseTime();
		return (Type*)it->second;
	}
	Type *entity = new Type(id);
	this->m_EntityMap[id] = entity;
	entity->SetLastUseTime();
	return entity;
}

template<class Type> void EntityFactory<Type>::Clear(void) {
	EntityMap::iterator it = this->m_EntityMap.begin();
	time_t curtime;
	time(&curtime);
	curtime = curtime - 600;
	for (; it != this->m_EntityMap.end(); it++) {
		BaseEntity* be = it->second;
		if (be->GetLastUseTime() < curtime) {
			this->m_EntityMap.erase(it);
			delete be;
		}
	}
	sleep(3600);
}

#endif /* ENTITYFACTORY_H_ */
