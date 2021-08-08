#include "philosophers.h"

void	update_curr_time(t_clock *clock)
{
	gettimeofday(&clock->saved_time, NULL);
	clock->curr = (((clock->saved_time.tv_sec - clock->start.tv_sec) * 1000) +
	((clock->saved_time.tv_usec - clock->start.tv_usec) / 1000));
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
	t_data *data = arg;
	update_curr_time(&data->clock);
	printf("%ld %d has taken a fork\n", data->clock.curr, data->counter);
	update_curr_time(&data->clock);
	printf("%ld %d has taken a fork\n", data->clock.curr, data->counter);
	update_curr_time(&data->clock);
	printf("%ld %d is eating\n", data->clock.curr, data->counter);
	usleep(data->time_to_eat * 1000);
	update_curr_time(&data->clock);
	printf("%ld %d is sleeping\n", data->clock.curr, data->counter);
	
	return (NULL);
}

void	create_threads(t_data *data)
{
	gettimeofday(&data->clock.start, NULL);
	data->counter = 0;
	while (data->counter < data->philo_count - 1)
	{
		pthread_create(&data->threads[data->counter], NULL, init_thread, data);
		data->counter++;
	}
	data->counter= 0;
	while (data->counter < data->philo_count - 1)
	{
		pthread_join(data->threads[data->counter], NULL);
		data->counter++;
	}
}
