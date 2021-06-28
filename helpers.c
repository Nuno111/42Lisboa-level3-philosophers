#include "philosophers.h"

void	get_curr_time(t_clock *clock)
{
	gettimeofday(&clock->saved_time, NULL);
	clock->curr = (clock->saved_time.tv_sec - clock->start) * 1000;
}

void	ft_exit(pthread_t **philo, char *msg)
{
	int i;

	i = -1;
	if (philo)
	{
		while (philo[++i])
		{
			free(philo[i]);
			philo[i] = NULL;
		}
	}
	free(philo);
	philo = NULL;
	if (msg)
	{
		printf("%s", msg);
		exit(1);
	}
	exit(0);
}

void	*init_thread(void *arg)
{
	t_philos *philos;

	philos = (t_philos *)arg;
	printf("This thread id is %ld, curr %d\n",  *(long *)philos->philo[philos->curr], philos->curr);;

	return NULL;
}

void	create_threads(t_philos *philos, t_clock *clock)
{
	struct timeval cur_time;

	gettimeofday(&cur_time, NULL);
	clock->start = cur_time.tv_sec;
	philos->curr = 0;
	while (philos->curr < philos->count / 2)
	{
		pthread_create(philos->philo[philos->curr], NULL, init_thread, (void *)philos);
		philos->curr += 2;
	}
	philos->curr = 0;
	while (philos->curr < philos->count / 2)
	{
		pthread_join(*philos->philo[philos->curr], NULL);
		philos->curr += 2;
	}
}
