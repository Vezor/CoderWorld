/*
 * BaseException.h
 *
 *  Created on: 2012-11-30
 *      Author: root
 */

#ifndef BASEEXCEPTION_H_
#define BASEEXCEPTION_H_

#include <string>
#include <cstdlib>

enum {
	REQUEST_URL_UNFIND = 101,
	REQUEST_PARAMETER_ERROR,

	USER_NOT_EXIST = 201,

	PROGRAM_RUNTIMEERROR_TIMEOUT = 301,

	BSON_KEY_NOT_EXIST = 401,

	REDIS_SERVER_ERROR = 501,

};

class BaseException {
public:

	BaseException(int exceptionCode, const char* exceptionDesc);

	BaseException(const BaseException& be);

	BaseException& operator=(const BaseException& be);

	virtual ~BaseException();

	int GetExceptionCode() const;

	const char* GetExceptionDesc() const;

private:

	int m_ExceptionCode;

	const char* m_ExceptionDesc;
};




#endif /* BASEEXCEPTION_H_ */
