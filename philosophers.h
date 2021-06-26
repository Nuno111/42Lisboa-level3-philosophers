#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include "libft.h"
# include <pthread.h>
#include <time.h>

typedef struct s_clock
{
	struct timeval saved_time;
	long start;
	long curr;
}				t_clock;

#endif
