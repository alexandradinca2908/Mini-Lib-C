#include <internal/syscall.h>
#include <errno.h>
#include <stddef.h>
#include "time.h"

unsigned int sleep(unsigned int seconds)
{
	//  Using sleep to simplify nanosleep function call

    struct timespec waitingTime = {seconds, 0};
    nanosleep(&waitingTime, NULL);

    return 0;
}

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    int ret = syscall(__NR_nanosleep, req, rem);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}
