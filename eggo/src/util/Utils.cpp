#include "util/Utils.h"

const char* Utils::strclone(const char* src) {
	int size = strlen(src) + 1;
	char* dest = (char*) malloc(sizeof(char) * size);

	if(dest != 0) {
		memcpy(dest, src, size);
	}
	return dest;
}
