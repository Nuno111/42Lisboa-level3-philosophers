#include "philosophers.h"

static void	ft_print_err(int error_code)
{
	if (error_code == WRONG_ARGUMENT_NB)
		printf("Error: Wrong number of arguments\n");
	else if (error_code == WRONG_ARGUMENT_TYPE)
		printf("Error: Arguments must be positive integers\n");
	else if (error_code == MEMORY_FAIL)
		printf("Error: Can't allocate memory\n");
	else if (error_code == TIMEVAL_ERROR)
		printf("Error: Can't get time value\n");
	else if (error_code == MUTEX_FAIL)
		printf("Error: Can't initialize forks with mutex\n");
	else if (error_code == MUTEX_DESTROY_FAIL)
		printf("Error: Can't destroy forks with mutex\n");
	else if (error_code == THREAD_CREATE_FAIL)
		printf("Error: Can't create the threads\n");
	else if (error_code == THREAD_JOIN_FAIL)
		printf("Error: Can't join the threads\n");
	else if (error_code == MUTEX_LOCK_FAIL)
		printf("Error: Can't lock the mutex\n");
	else if (error_code == MUTEX_UNLOCK_FAIL)
		printf("Error: Can't unlock the mutex\n");
	else
		printf("Error: Unknown error\n");
}

int	ft_exit(t_data *data, int error_code)
{
	if (error_code != SUCCESS)
		ft_print_err(error_code);
	if(data) {
		if (data->threads)
			free(data->threads);
		if (data->forks)
			free(data->forks);
	}
	if (error_code)
		return (error_code);
	return (SUCCESS);
}