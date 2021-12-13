#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <pthread.h>
# include <time.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

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
# define FORKS_TAKEN 11
# define THINKING 12
# define SLEEPING 13
# define SOMEONE_DIED 14

typedef struct s_forks
{
	pthread_mutex_t	fork;
	bool			taken;
}				t_forks;

typedef struct s_grim_reaper
{
	pthread_mutex_t	scythe;
	bool			someone_died;

}				t_grim_reaper;

typedef struct s_stats {
	long		philo_count;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		must_eat_count;
}				t_stats;

typedef struct s_clock
{
	struct timeval saved_time;
	struct timeval start;
	long curr;
}				t_clock;

typedef struct s_philo
{
	t_clock clock;
	long	last_eaten;
	int		id;
	t_forks		*left_fork;
	t_forks		*right_fork;
	pthread_mutex_t	*talking;
	t_grim_reaper	*grim_reaper;
	t_stats			*stats;
}				t_philo;

typedef struct s_data
{
	int			error_code;
	t_stats			stats;
	pthread_t		*threads;
	t_forks			*forks;
	t_philo			*philos;
	pthread_mutex_t	talking;
	t_grim_reaper	grim_reaper;
}				t_data;

int		ft_exit(t_data *data, int error_code);
void	ft_freearrays(char **array);
bool	ft_str_is_numeric(char *str);
int		ft_atoi(const char *str);
int		start_program(t_data *data);
void	update_curr_time(t_clock *clock);
bool	take_fork(t_forks *fork);
void	print_action(t_philo *philo, int action_code);
void	release_fork(t_forks *fork);
void	try_to_kill_philo(t_philo *philo);
bool	fighting_for_forks(t_philo *philo);

#endif
