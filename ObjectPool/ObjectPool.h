/*
 * ObjectPool.h
 *
 *  Created on: 2012-12-14
 *      Author: root
 */

#ifndef OBJECTPOOL_H_
#define OBJECTPOOL_H_

#include <time.h>

const time_t IDELTIME = 3600;

template<class Type> class ObjectPool {
public:

	ObjectPool();

	~ObjectPool();

	Type* ObtainObject();

	void ReturnObject(Type *object);

private:

	Type *m_ObjectList;

	int m_ObjectCount;

	ObjectPool(const ObjectPool<Type>& op);

	ObjectPool& operator=(const ObjectPool<Type>& op);

};

template<class Type> ObjectPool<Type>::ObjectPool() : m_ObjectList(NULL), m_ObjectCount(0) {}

template<class Type> ObjectPool<Type>::~ObjectPool() {
	delete this->m_ObjectList;
}

template<class Type> Type* ObjectPool<Type>::ObtainObject() {
	if (this->m_ObjectList) {
		Type *rt = this->m_ObjectList;
		this->m_ObjectList = (Type*)this->m_ObjectList->GetNextObject();
		rt->LinkNextObject(NULL);
		return rt;
	} else {
		Type *obj = new Type();
		return obj;
	}
}

template<class Type> void ObjectPool<Type>::ReturnObject(Type *object) {
	if (!object->IsAvailable()) {
		delete object;
		return ;
	}
	time_t curtime;
	time(&curtime);
	if (this->m_ObjectList && (curtime - this->m_ObjectList->GetLastUseTime()) > IDELTIME) {
		delete object;
		return ;
	}
	object->SetLastUseTime(curtime);
	object->LinkNextObject(this->m_ObjectList);
	this->m_ObjectList = object;
}

#endif /* OBJECTPOOL_H_ */
