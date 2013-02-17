/*
 * UserEntity.h
 *
 *  Created on: 2013-2-4
 *      Author: root
 */

#ifndef USERENTITY_H_
#define USERENTITY_H_

#include "BaseEntity.h"
#include "EntityFactory.h"

class UserEntity : public BaseEntity {
public:

	UserEntity(const char *id);

	~UserEntity();

};

static EntityFactory<UserEntity> UEFactory;


#endif /* USERENTITY_H_ */
