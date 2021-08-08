#include "philosophers.h"

void	update_curr_time(t_clock *clock)
{
	gettimeofday(&clock->saved_time, NULL);
	clock->curr = (((clock->saved_time.tv_sec - clock->start.tv_sec) * 1000) + ((clock->saved_time.tv_usec - clock->start.tv_usec) / 1000));
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
	t_clock* clock = arg;

	update_curr_time(clock);
	printf("I am thread %ld, and I have started.\n", clock->curr);
	usleep(2500000);
	update_curr_time(clock);
	printf("I am doneeeeee %ld\n",clock->curr);
	
	return (NULL);
}

void	create_threads(t_philos *philos, t_clock *clock)
{
	gettimeofday(&clock->start, NULL);
	philos->curr = 0;
	while (philos->curr < philos->count - 1)
	{
		pthread_create(&philos->threads[philos->curr], NULL, init_thread, clock);
		philos->curr++;
	}
	philos->curr = 0;
	while (philos->curr < philos->count - 1)
	{
		pthread_join(philos->threads[philos->curr], NULL);
		philos->curr ++;
	}
}
