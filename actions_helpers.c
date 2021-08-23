
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

bool	take_fork(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex) == 0)	
		return (true);	
	return (false);
}

int	assign_forks_index(t_stats *stats)
{
	if (stats->id == 1)
	{
		stats->first_fork = 0;
		stats->second_fork = stats->data->philo_count - 1;
	}
	else 
	{
		stats->first_fork = stats->id - 1;
		stats->second_fork = stats->id - 2;
	}
}

void try_to_eat(t_stats *stats)
{
	assign_forks_index(stats);
	should_die(stats);
	while (stats->alive)
	{
		if (take_fork(&stats->data->fork[stats->first_fork]))
		{
			if (take_fork(&stats->data->fork[stats->second_fork]))
			{
				print_status(clock, stats->id, "has taken a fork");
				print_status(clock, stats->id, "has taken a fork");
				eat();
				break;
			}
			else
				pthread_mutex_unlock(&stats->data->fork[stats->first_fork]);
		}
		else 
			usleep(10 * 1000);
	}
}