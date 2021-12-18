#include "philosophers.h"

void *start_dining(void *arg) {
	t_philo *philo;

	philo = (t_philo *)arg;

	gettimeofday(&philo->clock.start, NULL);

	usleep(600 * 1000); //sleep for 600 microseconds

	//someone should die at 600 miliseconds when doing 4 590 400 400

	while (!philo->grim_reaper->someone_died) {
		try_to_kill_philo(philo);
		while (!philo->grim_reaper->someone_died && fighting_for_forks(philo))
			try_to_kill_philo(philo);
		if (!philo->grim_reaper->someone_died) {
			print_action(philo, FORKS_TAKEN);
			philo->last_eaten = philo->clock.curr;
		}
		/*
		while (!philo->grim_reaper->someone_died && eating(philo))
			try_to_kill_philo();
		if (!philo->grim_reaper->someone_died)
			print_action(philo, SLEEPING);
		while (!philo->grim_reaper->someone_died && sleeping(philo))
			try_to_kill_philo();
		if (!philo->grim_reaper->someone_died)
			print_action(philo, THINKING);
		while (!philo->grim_reaper->someone_died && thinking(philo))
			try_to_kill_philo();
		*/
	}
	
	return (NULL);
}

int	start_program(t_data *data) {
	int i;

	i = -1;
	while (++i < data->stats.philo_count) {
		if (pthread_create(&data->threads[i], NULL, start_dining, &data->philos[i]) != 0)
			return(THREAD_CREATE_FAIL);
	}

	i = -1;
	while (++i < data->stats.philo_count) {
		if (pthread_join(data->threads[i], NULL) != 0)
			return(THREAD_JOIN_FAIL);
	}
	return i;
}