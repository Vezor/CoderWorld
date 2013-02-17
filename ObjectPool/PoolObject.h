/*
 * PoolObject.h
 *
 *  Created on: 2012-12-14
 *      Author: root
 */

#ifndef POOLOBJECT_H_
#define POOLOBJECT_H_

#include <time.h>

class PoolObject {
public:

	PoolObject();

	virtual ~PoolObject();

	void LinkNextObject(PoolObject *next);

	PoolObject* GetNextObject();

	void SetLastUseTime(const time_t& time);

	const time_t& GetLastUseTime();

	virtual bool IsAvailable() = 0;

private:

	PoolObject *m_Next;

	time_t m_LastUseTime;

	PoolObject(const PoolObject& po);

	PoolObject& operator=(const PoolObject& po);

};



#endif /* POOLOBJECT_H_ */
