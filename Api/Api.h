/*
 * Service.h
 *
 *  Created on: 2012-10-14
 *      Author: root
 */

#ifndef API_H_
#define API_H_

#include "../Util/CoreHead.h"

class Api {
public:

	Api(const char *url, bool filtrate, const char **respNames);

	virtual ~Api();

	virtual BsonObj* Process(const BsonObj& paramMap) = 0;

	const char* GetUrl() const ;

	bool Filtrate();

	const char** GetRespNames() const ;

protected:

	const char* m_Url;

	bool m_Filtrate;

	const char **m_RespNames;

	Api(const Api& api);

	Api& operator=(const Api& api);

};

#endif /* API_H_ */
