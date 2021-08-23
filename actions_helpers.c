
#include "philosophers.h"

void	should_die(t_stats *stats)
{
	update_curr_time(&stats->clock);
	if (stats->clock.curr - stats->last_eaten >= stats->data->time_to_die)
	{
		print_status(stats, "has died");
		ft_exit(&stats->data->fork, NULL);
	}
}

void	print_status(t_stats *stats, char *msg)
{
	if (controls_mutex(&stats->data->can_talk))
	  printf("%ld %d %s\n", stats->clock.curr, stats->id, msg);
	else
		ft_exit(&stats->data->fork, "An error has occured when trying to lock the mutex\n");
}

bool	controls_mutex(pthread_mutex_t *mutex)
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
		if (controls_mutex(&stats->data->fork[stats->first_fork]))
		{
			if (controls_mutex(&stats->data->fork[stats->second_fork]))
			{
				print_status(stats, "has taken a fork");
				print_status(stats, "has taken a fork");
				eat();
				break;
			}
			else
				pthread_mutex_unlock(&stats->data->fork[stats->first_fork]);
		}
		else 
			should_die(stats);
	}
}