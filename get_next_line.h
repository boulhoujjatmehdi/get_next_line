#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char *get_next_line(int fd);


#endif  