#include "philosophers.h"

void	ft_thread_create(pthread_t *thread, t_data *data)
{
		if (pthread_create(thread, NULL, init_thread, data ) != 0)
			ft_exit(NULL, THREAD_CREATE_FAIL);
}

void	ft_thread_join(pthread_t *thread, t_data *data)
{
		if (pthread_join(thread, NULL ) != 0)
			ft_exit(NULL, THREAD_JOIN_FAIL);
}