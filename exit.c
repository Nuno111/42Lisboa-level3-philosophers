#include "philosophers.h"

static void	ft_print_err(t_exit_code exit_code);

void	ft_exit(pthread_t *threads, t_exit_code exit_code)
{
	if (exit_code != SKIP_PRINTING)
		ft_print_err(exit_code);
	if (threads)
		ft_free_data(threads);
	if (exit_code)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

static void	ft_print_err(t_exit_code exit_code)
{
	if (exit_code == WRONG_ARGUMENT_NB)
		printf("Error: Wrong number of arguments\n");
	else if (exit_code == WRONG_ARGUMENT_TYPE)
		printf("Error: Arguments must be positive integers\n");
	else if (exit_code == MEMORY_FAIL)
		printf("Error: Can't allocate memory\n");
	else if (exit_code == TIMEVAL_ERROR)
		printf("Error: Can't get time value\n");
	else if (exit_code == MUTEX_FAIL)
		printf("Error: Can't initialize forks with mutex\n");
	else if (exit_code == MUTEX_DESTROY_FAIL)
		printf("Error: Can't destroy forks with mutex\n");
	else if (exit_code == THREAD_CREATE_FAIL)
		printf("Error: Can't create the threads\n");
	else if (exit_code == THREAD_JOIN_FAIL)
		printf("Error: Can't join the threads\n");
	else if (exit_code == MUTEX_LOCK_FAIL)
		printf("Error: Can't lock the mutex\n");
	else if (exit_code == MUTEX_UNLOCK_FAIL)
		printf("Error: Can't unlock the mutex\n");
	else
		printf("Error: Unknown error\n");
}