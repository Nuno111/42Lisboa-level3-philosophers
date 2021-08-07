#include "philosophers.h"

void	update_curr_time(t_clock *clock)
{
	gettimeofday(&clock->saved_time, NULL);
	clock->curr = (clock->saved_time.tv_sec - clock->start) * 1000;
}

void	ft_exit(pthread_t *threads, char *msg)
{
	if (threads)
		free(threads);
	if (msg)
	{
		printf("%s", msg);
		exit(1);
	}
	exit(0);
}

void	*init_thread(void *arg)
{
	int num;

	num = *(int *)arg;

	printf("I am thread %d, and I have started.\n", num);
	sleep(2);
	printf("I am doneeeeee %d\n",num);
	
	return (NULL);
}

void	create_threads(t_philos *philos, t_clock *clock)
{

	gettimeofday(&clock->saved_time, NULL);
	clock->start = clock->saved_time.tv_sec;
	philos->curr = 0;
	while (philos->curr < philos->count - 1)
	{
		pthread_create(&philos->threads[philos->curr], NULL, init_thread, &philos->curr);
		philos->curr++;
	}
	philos->curr = 0;
	while (philos->curr < philos->count - 1)
	{
		pthread_join(philos->threads[philos->curr], NULL);
		philos->curr += 2;
	}
}
