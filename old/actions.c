#include "philosophers.h"

void eat(t_stats *stats)
{
	should_die(stats);
	assign_forks_index(stats);
	while (true)
	{
		ft_lock_mutex(&stats->data->fork[stats->first_fork])
			ft_lock_mutex(&stats->data->fork[stats->second_fork])
				print_status(stats, "has taken a fork");
				print_status(stats, "has taken a fork");
				break;
			else
				pthread_mutex_unlock(&stats->data->fork[stats->first_fork]);
			should_die(stats);
	}
}

void sleep() {

}

void think() {

}