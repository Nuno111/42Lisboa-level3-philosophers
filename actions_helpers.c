
#include "philosophers.h"

void	should_die(t_stats *stats)
{
	update_curr_time(&stats->clock);

	if (stats->clock.curr - stats->last_eaten >= stats->data->time_to_die)
		stats->alive = false;
}

void	print_status(t_clock *clock, int id, char *msg)
{
	update_curr_time(clock);

	if (!will_die())
	  printf("%ld %d %s\n", clock->curr, id, msg);
	else
	{
		printf("%ld %d has died\n");
		ft_exit(threads, )
	}


}

bool	take_fork(pthread_mutex_t *mutex,  t_clock *clock, int id)
{
	if (pthread_mutex_lock(mutex) == 0)
	{
		print_status(clock, id, "has taken a fork");
		return (true);
	}
	return (false);
}

void	drop_fork(pthread_mutex_t *mutex)
{

}

int	assign_forks_index(int id, int *first_fork, int *second_fork, t_data *data)
{
	if (id == 1)
	{
		*first_fork = 0;
		*second_fork = data->philo_count - 1;
	}
	else 
	{
		*first_fork = id - 1;
		*second_fork = id - 2;
	}
}

void try_to_eat(t_data *data, t_clock *clock, int id)
{
	int first_fork;
	int second_fork;

	assign_forks_index(id, &first_fork, &second_fork, data);
	while (true)
	{
		if (take_fork(&data->fork[first_fork], clock, id))
		{
			if (take_fork(&data->fork[second_fork], clock, id))
			{
				eat();
				break;
			}
			else
				drop_fork(&data->fork[first_fork]);
		}
		else 
			usleep(10 * 1000);
	}
}