#include "philosophers.h"

void	ft_lock_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex) != 0)
		ft_exit_error(NULL, MUTEX_LOCK_FAIL);
}

void	ft_unlock_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex) != 0)
		ft_exit_error(NULL, MUTEX_LOCK_FAIL);
}

void	ft_destroy_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_destroy(mutex) != 0)
		ft_exit_error(NULL, MUTEX_DESTROY_FAIL);
}