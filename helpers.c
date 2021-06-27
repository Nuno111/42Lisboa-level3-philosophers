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
