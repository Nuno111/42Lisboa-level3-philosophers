#include "philosophers.h"

void *hello(void *arg) {
	t_philo *philo;

	philo = (t_philo *)arg;

	gettimeofday(&philo->clock.start, NULL);


	if (philo->id % 2 == 0) usleep(1 * 1000000);

	update_curr_time(&philo->clock);

	printf("Philosopher number %d, started eating at %ld\n", philo->id, philo->clock.curr);
	
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