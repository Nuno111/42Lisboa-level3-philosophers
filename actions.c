#include "philosophers.h"

void	try_to_kill_philo(t_philo *philo) {
	update_curr_time(&philo->clock);
	if(philo->clock.curr - philo->last_eaten >= philo->stats->time_to_die) {
		if(pthread_mutex_lock(&philo->grim_reaper->scythe) == -1) return;

		if(philo->grim_reaper->someone_died == true) return;

		philo->grim_reaper->someone_died = true;

		pthread_mutex_unlock(&philo->grim_reaper->scythe);

		print_action(philo, SOMEONE_DIED);
	}
}

bool	forks_taken(t_philo *philo) {
	if (philo->id % 2 != 0) {
		if (take_fork(philo->left_fork)) {
			print_action(philo, FORK_TAKEN);
			if(take_fork(philo->right_fork)) {
				print_action(philo, FORK_TAKEN);
				print_action(philo, STARTED_EATING);
				return (true);
			}
			else
				release_fork(philo->left_fork);
		}
	}
	else {
		usleep(100);
		if (take_fork(philo->right_fork)) {
			print_action(philo, FORK_TAKEN);
			if(take_fork(philo->left_fork)) {
				print_action(philo, FORK_TAKEN);
				print_action(philo, STARTED_EATING);
				return (true);
			}
			else
				release_fork(philo->right_fork);
		}
	}

	return (false);
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

	if(pthread_mutex_lock(philo->talking) == -1) return;
	update_curr_time(&philo->clock);
	if(action_code == STARTED_EATING) {
		printf("%ld philosopher %d is eating\n", philo->clock.curr, philo->id);
		philo->last_eaten = philo->clock.curr;
	}
	else if(action_code == FORK_TAKEN)
		printf("%ld philosopher %d has taken a fork\n", philo->clock.curr, philo->id);
	else if(action_code == SOMEONE_DIED)
		printf("%ld philosopher  %d died\n", philo->clock.curr, philo->id);

	pthread_mutex_unlock(philo->talking);
}