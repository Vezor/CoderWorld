/*
 * BaseEntity.h
 *
 *  Created on: 2013-2-3
 *      Author: root
 */

#ifndef BASEENTITY_H_
#define BASEENTITY_H_

#include "../EntityServer/EntityServer.h"

class BaseEntity {
public:

	BaseEntity(const char *entity, const char *id);

	virtual ~BaseEntity();

	void SetLastUseTime();

	const time_t& GetLastUseTime();

	bool Create();

	const char* GetID() const;

	const char* GetSetLinkEntity() const;

	BsonObj* GetHugeEntity();

	bool SetHugeEntity(const BsonObj& props);

	BsonObj* GetSocialEntity();

	char** GetPartialSocialEntity(const KFList& proplist);

	BsonObj* GetLitSocialEntity(const char *prop);

	bool Link(BaseEntity* other, const char *relation);

	bool BeLink(const char *otherid, const char *relation, ListLinkEntityServer *lles, SetLinkEntityServer *sles, SocialEntityServer *ses);

	bool Unlink(BaseEntity* other, const char *relation);

	bool BeUnlink(const char *otherid, const char *relation, ListLinkEntityServer *lles, SetLinkEntityServer *sles, SocialEntityServer *ses);

	char** GetTimelineRelate(const char *relation, int start=0, int end=-1);

	bool IsRelated(const char *relation, const char *id);

	char** GetRandomRelate(const char *relation, int count);

	char** MutualOf(const char *myrelation, const BaseEntity& other, const char *itsrelation, int count);

	static const char *m_EntityName;

private:

	const char *m_ID;

	const char *m_Entity;

	const char *m_HugeEntity;

	const char *m_SocialEntity;

	const char *m_ListLinkEntity;

	const char *m_SetLinkEntity;

	time_t m_LastUseTime;

	BaseEntity(const BaseEntity& be);

	BaseEntity& operator=(const BaseEntity& be);

};

#endif /* BASEENTITY_H_ */
