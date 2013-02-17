/*
 * CoreHead.h
 *
 *  Created on: 2012-10-13
 *      Author: root
 */

#ifndef COREHEAD_H_
#define COREHEAD_H_

#include <iostream>
#include <cstdlib>
#include <fcgi_stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <json/json.h>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <hash_map>
#include <functional>
#include <mongo.h>
#include <md5.h>
#include <hiredis/hiredis.h>
#include <fstream>
#include <exception>
#include <time.h>
#include <sys/time.h>
#include <signal.h>
#include "../ObjectPool/ObjectPool.h"
#include "../ObjectPool/PoolObject.h"
#include "../Exception/BaseException.h"
#include "CStyleTool.h"
#include "BsonObj.h"
#include "pthread.h"

template <class _Tp>
struct str_equal_to : public std::binary_function<_Tp, _Tp, bool>
{
    bool operator()(_Tp __x, _Tp __y) const {
    	return strcmp( __x, __y ) == 0;
    }
};


#endif /* COREHEAD_H_ */
