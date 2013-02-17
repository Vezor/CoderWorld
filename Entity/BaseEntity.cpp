/*
 * BaseEntity.cpp
 *
 *  Created on: 2013-2-3
 *      Author: root
 */

#include "BaseEntity.h"

BaseEntity::BaseEntity(const char *entity, const char *id) :
	m_ID(id),
	m_Entity(StrCat(entity, id)),
	m_HugeEntity(StrCat("CodeWorld.", entity)),
	m_SocialEntity(StrCat("social", m_Entity)),
	m_ListLinkEntity(StrCat("listlink", m_Entity)),
	m_SetLinkEntity(StrCat("setlink", m_Entity)),
	m_LastUseTime(0) {}

BaseEntity::~BaseEntity() {
	delete this->m_Entity;
	delete this->m_ID;
	delete this->m_HugeEntity;
	delete this->m_ListLinkEntity;
	delete this->m_SetLinkEntity;
	delete this->m_SocialEntity;
}

void BaseEntity::SetLastUseTime() {
	time_t curtime;
	time(&curtime);
	this->m_LastUseTime = curtime;
}

const time_t& BaseEntity::GetLastUseTime() {
	return this->m_LastUseTime;
}

bool BaseEntity::Create() {
	HugeEntityServer *hes = HEPool.ObtainObject();
	BsonObj entity;
	entity.set("id", this->m_ID);
	hes->Insert(this->m_HugeEntity, entity);
	HEPool.ReturnObject(hes);
	SocialEntityServer *ses = SEPool.ObtainObject();
	ses->Create(this->m_SocialEntity);
	SEPool.ReturnObject(ses);
	return true;
}

const char* BaseEntity::GetID() const {
	return this->m_ID;
}

const char* BaseEntity::GetSetLinkEntity() const {
	return this->m_SetLinkEntity;
}

BsonObj* BaseEntity::GetHugeEntity() {
	HugeEntityServer *hes = HEPool.ObtainObject();
	BsonObj query;
	query.set("id", this->m_ID);
	BsonObj* res = hes->Select(this->m_HugeEntity, query);
	HEPool.ReturnObject(hes);
	return res;
}

bool BaseEntity::SetHugeEntity(const BsonObj& props) {
	HugeEntityServer *hes = HEPool.ObtainObject();
	BsonObj query;
	query.set("id", this->m_ID);
	bool res = hes->Update(this->m_HugeEntity, query, props);
	HEPool.ReturnObject(hes);
	return res;
}

BsonObj* BaseEntity::GetSocialEntity() {
	SocialEntityServer *ses = SEPool.ObtainObject();
	BsonObj* res = ses->GetAll(this->m_SocialEntity);
	SEPool.ReturnObject(ses);
	return res;
}

char** BaseEntity::GetPartialSocialEntity(const KFList& proplist) {
	SocialEntityServer *ses = SEPool.ObtainObject();
	char** res = ses->GetSome(this->m_SocialEntity, proplist);
	SEPool.ReturnObject(ses);
	return res;
}

BsonObj* BaseEntity::GetLitSocialEntity(const char *prop) {
	SocialEntityServer *ses = SEPool.ObtainObject();
	BsonObj* res = ses->GetOne(this->m_SocialEntity, prop);
	SEPool.ReturnObject(ses);
	return res;
}

bool BaseEntity::Link(BaseEntity* other, const char *relation) {
	ListLinkEntityServer *lles = LLEPool.ObtainObject();
	SetLinkEntityServer *sles = SLEPool.ObtainObject();
	SocialEntityServer *ses = SEPool.ObtainObject();
	lles->Link(StrCat(this->m_ListLinkEntity, relation), other->GetID());
	sles->Link(StrCat(this->m_SetLinkEntity, relation), other->GetID());
	ses->IncrProp(this->m_SocialEntity, relation);
	other->BeLink(this->GetID(), relation, lles, sles, ses);
	LLEPool.ReturnObject(lles);
	SLEPool.ReturnObject(sles);
	SEPool.ReturnObject(ses);
	return true;
}

bool BaseEntity::BeLink(const char *otherid, const char *relation, ListLinkEntityServer *lles, SetLinkEntityServer *sles, SocialEntityServer *ses) {
	lles->Link(StrCat(this->m_ListLinkEntity, relation), otherid);
	sles->Link(StrCat(this->m_SetLinkEntity, relation), otherid);
	ses->IncrProp(this->m_SocialEntity, relation);
	return true;
}

bool BaseEntity::Unlink(BaseEntity* other, const char *relation) {
	ListLinkEntityServer *lles = LLEPool.ObtainObject();
	SetLinkEntityServer *sles = SLEPool.ObtainObject();
	SocialEntityServer *ses = SEPool.ObtainObject();
	lles->Unlink(StrCat(this->m_ListLinkEntity, relation), other->GetID());
	sles->Unlink(StrCat(this->m_SetLinkEntity, relation), other->GetID());
	ses->DecrProp(this->m_SocialEntity, relation);
	other->BeUnlink(this->m_ID, relation, lles, sles, ses);
	LLEPool.ReturnObject(lles);
	SLEPool.ReturnObject(sles);
	SEPool.ReturnObject(ses);
	return true;
}

bool BaseEntity::BeUnlink(const char *otherid, const char *relation, ListLinkEntityServer *lles, SetLinkEntityServer *sles, SocialEntityServer *ses) {
	lles->Unlink(StrCat(this->m_ListLinkEntity, relation), otherid);
	sles->Unlink(StrCat(this->m_SetLinkEntity, relation), otherid);
	ses->DecrProp(this->m_SocialEntity, relation);
	return true;
}

char** BaseEntity::GetTimelineRelate(const char *relation, int start, int end) {
	ListLinkEntityServer *lles = LLEPool.ObtainObject();
	char **res = lles->GetLinkedList(StrCat(this->m_ListLinkEntity, relation), start, end);
	LLEPool.ReturnObject(lles);
	return res;
}

bool BaseEntity::IsRelated(const char *relation, const char *id) {
	SetLinkEntityServer *sles = SLEPool.ObtainObject();
	bool res = sles->IsLink(StrCat(this->m_SetLinkEntity, relation), id);
	SLEPool.ReturnObject(sles);
	return res;
}

char** BaseEntity::GetRandomRelate(const char *relation, int count) {
	SetLinkEntityServer *sles = SLEPool.ObtainObject();
	char **res = sles->GetLinkSet(StrCat(this->m_SetLinkEntity, relation), count);
	SLEPool.ReturnObject(sles);
	return res;
}

char** BaseEntity::MutualOf(const char *myrelation, const BaseEntity& other, const char *itsrelation, int count) {
	SetLinkEntityServer *sles = SLEPool.ObtainObject();
	char **res = sles->GetMutualLinkSet(StrCat(this->m_SetLinkEntity, myrelation), StrCat(other.GetSetLinkEntity(), itsrelation), count);
	SLEPool.ReturnObject(sles);
	return res;
}

