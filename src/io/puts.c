#include "unistd.h"
#include "stdio.h"
#include "string.h"

int puts(const char *input)
{
    //  unistd.h is used for write syscall
    //  stdio.h is used for eof symbol
    int value = write(1, input, strlen(input));
    if (value > 0) {
		char newline[] = "\n";
        return(write(1, newline, 1));
    }
    return -1;
}
