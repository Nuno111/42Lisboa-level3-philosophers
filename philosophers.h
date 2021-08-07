#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <pthread.h>
# include <time.h>
# include "libft.h"

typedef struct s_clock
{
	struct timeval saved_time;
	long start;
	long curr;
}				t_clock;

typedef struct s_philos
{
	int			curr;
	long		count;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		must_eat_count;
	pthread_t	*threads;
}				t_philos;

void	ft_exit(pthread_t *threads, char *msg);
void	update_curr_time(t_clock *clock);
void	create_threads(t_philos *philos, t_clock *clock);

#endif
