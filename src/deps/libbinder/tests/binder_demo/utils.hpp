#ifndef __DK_UTILS__
#define __DK_UTILS__

#include <stdlib.h>

#define LOGD(fmt, ...) fprintf(stderr, "%s:%d:%s: " fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__)

#endif
