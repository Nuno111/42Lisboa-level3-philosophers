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
	t_clock clock;
	int		id;
	t_data	*data;

	data = arg;
	id = data->counter++;


}

void	create_threads(t_data *data)
{
	pthread_t *threads;

	threads = malloc(sizeof(pthread_t) * data->philo_count);
	if (!threads)
		ft_exit(NULL, "Unable to allocate memory for threads\n");
	data->counter = 0;
	while (data->counter < data->philo_count - 1)
	{
		pthread_create(&threads[data->counter], NULL, init_thread, data);
		data->counter++;
	}
	data->counter= 0;
	while (data->counter < data->philo_count - 1)
	{
		pthread_join(threads[data->counter], NULL);
		data->counter++;
	}
	free(threads);
}
