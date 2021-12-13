#include "philosophers.h"

void	try_to_kill_philo(t_philo *philo) {
	update_curr_time(&philo->clock);
	if(philo->clock.curr - philo->last_eaten >= philo->stats->time_to_die) {
		if(pthread_mutex_lock(&philo->grim_reaper->scythe) == -1) return;

		philo->grim_reaper->someone_died = true;

		pthread_mutex_unlock(&philo->grim_reaper->scythe);

		print_action(philo, SOMEONE_DIED);
	}
}

bool	fighting_for_forks(t_philo *philo) {
	if (philo->id % 2 != 0) {
		if (take_fork(philo->left_fork)) {
			if(take_fork(philo->right_fork))
				return (false);
			else
				release_fork(philo->left_fork);
		}
	}
	else {
		if (take_fork(philo->right_fork)) {
			if(take_fork(philo->left_fork))
				return (false);
			else
				release_fork(philo->right_fork);
		}
	}

	return (true);
}

bool	take_fork(t_forks *fork) {
	bool took_fork;

	if(pthread_mutex_lock(&fork->fork) == -1) return false;

	if(!fork->taken)
	{
		fork->taken = true;
		took_fork = true;
	}
	else
		took_fork = false;

	pthread_mutex_unlock(&fork->fork);

	return took_fork;
}

void	release_fork(t_forks *fork) {
	if(pthread_mutex_lock(&fork->fork) == -1) return;

	fork->taken = false;

	pthread_mutex_unlock(&fork->fork);
}

void	print_action(t_philo *philo, int action_code) {
	update_curr_time(&philo->clock);

	if(pthread_mutex_lock(philo->talking) == -1) return;
	if(action_code == FORKS_TAKEN) {
		printf("%ld %d has taken a fork\n", philo->clock.curr, philo->id);
		printf("%ld %d has taken a fork\n", philo->clock.curr, philo->id);
	}
	else if(action_code == SOMEONE_DIED)
		printf("%ld %d died\n", philo->clock.curr, philo->id);

	pthread_mutex_unlock(philo->talking);

}