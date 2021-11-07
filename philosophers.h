#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <pthread.h>
# include <time.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

# define SUCCESS 0
# define WRONG_ARGUMENT_NB 1
# define WRONG_ARGUMENT_TYPE 2
# define MEMORY_FAIL 3
# define TIMEVAL_ERROR 4
# define MUTEX_FAIL 5
# define MUTEX_DESTROY_FAIL 6
# define THREAD_CREATE_FAIL 7
# define THREAD_JOIN_FAIL 8
# define MUTEX_LOCK_FAIL 9
# define MUTEX_UNLOCK_FAIL 10
# define SKIP_PRINTING 99

typedef struct s_clock
{
	struct timeval saved_time;
	struct timeval start;
	long curr;
}				t_clock;

typedef struct s_data
{
	int			error_code;
	int			counter;
	long		philo_count;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		must_eat_count;
	pthread_t		*threads;
	pthread_mutex_t *forks;
}				t_data;

typedef struct s_stats
{
	t_clock clock;
	t_data	*data;
	long	last_eaten;
	int		id;
	int		first_fork;
	int		second_fork;
}				t_stats;

int		ft_exit(t_data *data, int error_code);
void	ft_freearrays(char **array);
bool	ft_str_is_numeric(char *str);
int		ft_atoi(const char *str);

#endif
