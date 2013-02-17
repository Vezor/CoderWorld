/*
 * EntityServer.h
 *
 *  Created on: 2013-2-3
 *      Author: root
 */

#ifndef ENTITYSERVER_H_
#define ENTITYSERVER_H_

#include "HugeEntityServer.h"
#include "ListLinkEntityServer.h"
#include "SetLinkEntityServer.h"
#include "SocialEntityServer.h"
#include "IDGenerator.h"
#include "../ObjectPool/ObjectPool.h"

static ObjectPool<HugeEntityServer> HEPool;
static ObjectPool<ListLinkEntityServer> LLEPool;
static ObjectPool<SetLinkEntityServer> SLEPool;
static ObjectPool<SocialEntityServer> SEPool;
static ObjectPool<IDGenerator> IDGPool;

#endif /* ENTITYSERVER_H_ */
