#include "philosophers.h"

void *start_dining(void *arg) {
	t_philo *philo;

	philo = (t_philo *)arg;

	while (!philo->grim_reaper->someone_died) {
		//try_to_kill_philo(philo);
		forks_taken(philo);

		/*
		while (!philo->grim_reaper->someone_died && !forks_taken(philo))
			try_to_kill_philo(philo);
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
	data->stats.start_time = get_time_in_miliseconds();
	while (++i < data->stats.philo_count)
		if (pthread_create(&data->threads[i], NULL, start_dining, &data->philos[i]) != 0)
			return (data->error_code = THREAD_CREATE_FAIL);
	i = -1;
	while (++i < data->stats.philo_count) 
		if (pthread_join(data->threads[i], NULL) != 0)
			return (data->error_code = THREAD_JOIN_FAIL);
	return i;
}