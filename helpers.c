#include "philosophers.h"

void	get_curr_time(t_clock *clock)
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
	t_philos *philos;

	philos = (t_philos *)arg;
	printf("This thread id is %ld, curr %d\n",
			*(long *)philos->threads[philos->curr], philos->curr);

	return NULL;
}

void	create_threads(t_philos *philos, t_clock *clock)
{
	struct timeval cur_time;

	gettimeofday(&cur_time, NULL);
	clock->start = cur_time.tv_sec;
	philos->curr = 0;
	while (philos->curr < philos->count - 1)
	{
		pthread_create(&philos->threads[philos->curr], NULL, init_thread, (void *)philos);
		philos->curr += 2;
	}
	philos->curr = 0;
	while (philos->curr < philos->count - 1)
	{
		pthread_join(philos->threads[philos->curr], NULL);
		philos->curr += 2;
	}
}
