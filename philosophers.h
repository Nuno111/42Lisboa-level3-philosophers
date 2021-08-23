#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <pthread.h>
# include <time.h>
# include "libft.h"

typedef struct s_clock
{
	struct timeval saved_time;
	struct timeval start;
	long curr;
}				t_clock;


typedef struct s_data
{
	int			counter;
	long		philo_count;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		must_eat_count;
	pthread_mutex_t *fork;

}				t_data;

typedef struct s_stats
{
	t_clock clock;
	t_data	*data;
	bool	alive;
	long	last_eaten;
	int		id;
	int		first_fork;
	int		second_fork;
}				t_stats;

void	ft_exit(pthread_t *threads, char *msg);
void	update_curr_time(t_clock *clock);
void	create_threads(t_data *data);

#endif
