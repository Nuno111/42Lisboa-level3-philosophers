#include "philosophers.h"

void *hello(void *arg) {
	t_philo *philo;

	philo = (t_philo *)arg;

	gettimeofday(&philo->clock.start, NULL);


	if (philo->id % 2 != 0) {
		if (take_fork(philo->left_fork)) {
			if(take_fork(philo->right_fork))
				print_action(philo, FORKS_TAKEN);
			else
				release_fork(philo->left_fork);
		}
	}
	else {
		if (take_fork(philo->right_fork)) {
			if(take_fork(philo->left_fork))
				print_action(philo, FORKS_TAKEN);
			else
				release_fork(philo->right_fork);
		}
	}
	
	return (NULL);
}

int	start_program(t_data *data) {
	int i;

	i = -1;
	while(++i < data->philo_count) {
		if(pthread_create(&data->threads[i], NULL, hello, &data->philos[i]) != 0)
			return(THREAD_CREATE_FAIL);
	}

	i = -1;
	while(++i < data->philo_count) {
		if(pthread_join(data->threads[i], NULL) != 0)
			return(THREAD_JOIN_FAIL);
	}
	return i;
}