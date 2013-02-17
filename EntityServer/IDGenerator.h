/*
 * IDGenerator.h
 *
 *  Created on: 2013-2-5
 *      Author: root
 */

#ifndef IDGENERATOR_H_
#define IDGENERATOR_H_

#include "../SqlServer/RedisServer.h"

class IDGenerator : public PoolObject {
public:

	IDGenerator();

	~IDGenerator();

	const char *NextID(const char *ID);

	bool IsAvailable();

private:

	RedisServer m_Server;

	IDGenerator(const IDGenerator& eg);

	IDGenerator& operator=(const IDGenerator& eg);

};


#endif /* IDGENERATOR_H_ */
