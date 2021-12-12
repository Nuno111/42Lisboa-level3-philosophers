#include "philosophers.h"

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

	if(action_code == FORKS_TAKEN) {
		if(pthread_mutex_lock(philo->can_talk) == -1) return;

		printf("%ld %d has taken a fork\n", philo->clock.curr, philo->id);
		printf("%ld %d has taken a fork\n", philo->clock.curr, philo->id);

		pthread_mutex_unlock(philo->can_talk);
	}

}