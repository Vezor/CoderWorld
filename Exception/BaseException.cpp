/*
 * BaseException.cpp
 *
 *  Created on: 2012-12-1
 *      Author: root
 */

#include "BaseException.h"

BaseException::BaseException(int exceptionCode, const char* exceptionDesc)
	: m_ExceptionCode(exceptionCode),
	  m_ExceptionDesc(exceptionDesc){
}

BaseException::BaseException(const BaseException& be) {
	this->m_ExceptionCode = be.m_ExceptionCode;
	this->m_ExceptionDesc = be.m_ExceptionDesc;
}

BaseException& BaseException::operator=(const BaseException& be) {
	this->m_ExceptionCode = be.m_ExceptionCode;
	this->m_ExceptionDesc = be.m_ExceptionDesc;
	return *this;
}

BaseException::~BaseException() {
	delete this->m_ExceptionDesc;
}

int BaseException::GetExceptionCode() const {
	return this->m_ExceptionCode;
}

const char* BaseException::GetExceptionDesc() const {
	return this->m_ExceptionDesc;
}



