#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <pthread.h>
# include <time.h>
# include "libft.h"

typedef enum e_exit_code
{
	SKIP_PRINTING,
	WRONG_ARGUMENT_NB,
	WRONG_ARGUMENT_TYPE,
	MEMORY_FAIL,
	TIMEVAL_ERROR,
	MUTEX_FAIL,
	MUTEX_DESTROY_FAIL,
	THREAD_CREATE_FAIL,
	THREAD_JOIN_FAIL,
	MUTEX_LOCK_FAIL,
	MUTEX_UNLOCK_FAIL
}			t_exit_code;

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
	pthread_t		*threads;
	pthread_mutex_t *fork;
	pthread_mutex_t	can_talk;

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

void	ft_exit(pthread_t *threads, t_exit_code exit_code);
void	update_curr_time(t_clock *clock);
void	*init_thread(void *arg);
void	create_join_threads(t_data *data);
void	ft_exit(pthread_t *threads, t_exit_code exit_code);
void	ft_thread_create(pthread_t *thread, t_data *data);
void	ft_thread_join(pthread_t *thread, t_data *data);
void	ft_init_mutex(pthread_mutex_t *mutex);
void	ft_lock_mutex(pthread_mutex_t *mutex);
void	ft_unlock_mutex(pthread_mutex_t *mutex);
void	ft_destroy_mutex(pthread_mutex_t *mutex);

#endif
