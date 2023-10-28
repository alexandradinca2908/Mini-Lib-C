#ifndef __TIME_H__
#define __TIME_H__	1

struct timespec {
    unsigned int tv_sec;
    unsigned long tv_nsec;
};

unsigned int sleep(unsigned int seconds);
int nanosleep(const struct timespec *req, struct timespec *rem);

#endif
