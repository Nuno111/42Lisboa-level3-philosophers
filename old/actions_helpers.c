
#include "philosophers.h"

void	should_die(t_stats *stats)
{
	update_curr_time(&stats->clock);
	if (stats->clock.curr - stats->last_eaten >= stats->data->time_to_die)
	{
		print_status(stats, "has died", 1000);
		ft_exit(&stats->data->fork, NULL);
	}
}

void	print_status(t_stats *stats, char *msg, long delay)
{
	ft_lock_mutex(&stats->data->can_talk);
	printf("%ld %d %s\n", stats->clock.curr, stats->id, msg);
	usleep(delay);
	ft_unlock_mutex(&stats->data->can_talk);
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
