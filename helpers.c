#include "philosophers.h"

void	update_curr_time(t_clock *clock)
{
	gettimeofday(&clock->saved_time, NULL);
	clock->curr = (((clock->saved_time.tv_sec - clock->start.tv_sec) * 1000) +
	((clock->saved_time.tv_usec - clock->start.tv_usec) / 1000));
}

void	*init_thread(void *arg)
{
	t_stats stats;

	stats.data = arg;
	stats.id = stats.data->counter++;
	should_die(&stats);
	while (true)
	{
		eat(stats);
		sleep();
		think();
	}
}

void	create_join_threads(t_data *data)
{
	data->counter = -1;
	while (++data->counter < data->philo_count - 1)
		ft_thread_create(&data->threads[data->counter], data);
	data->counter= -1;
	while (++data->counter < data->philo_count - 1)
		ft_thread_join(&data->threads[data->counter], NULL);
}
