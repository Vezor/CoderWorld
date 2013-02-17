/*
 * UserEntity.cpp
 *
 *  Created on: 2013-2-4
 *      Author: root
 */

#include "UserEntity.h"

UserEntity::UserEntity(const char *id) : BaseEntity("user", id) {};

UserEntity::~UserEntity() {}

const char *UserEntity::BaseEntity::m_EntityName = "user";
