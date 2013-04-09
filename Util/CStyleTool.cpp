/*
 * CStyleTool.cpp
 *
 *  Created on: 2012-12-8
 *      Author: root
 */

#include "CStyleTool.h"

const char* StrCat(const char* str1, const char* str2) {
	if (str1 == NULL || str2 == NULL)
		return NULL;
	char *result;
	const char *ls = str1;
	const char *rs = str2;
	result = new char[strlen(ls) + strlen(rs) + 1];
	while (*ls != '\0')
		*result++ = *ls++;
	while ((*result++ = *rs++) != '\0');
	return result;
}

void strcatt(int catcount, char *dest, ...) {
	if (dest == NULL)
		return ;
	char *temp = dest;
	while(*temp)
		temp++;
	va_list args;
	va_start(args, dest);
	for (int i = 0; i < catcount; i++) {
		const char *src = va_arg(args, const char*);
		while(*src) {
			*temp++ = *src++;
		}
	}
}
