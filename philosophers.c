#include "philosophers.h"

void	init_philos(t_data *data) {
	int i;

	i = -1;
	while (++i < data->stats.philo_count) {
		data->philos[i].id = i + 1;
		data->philos[i].last_eaten = 0;
		data->philos[i].left_fork = &data->forks[data->philos[i].id - 1];
		data->philos[i].talking = &data->talking;
		data->philos[i].grim_reaper = &data->grim_reaper;
		data->philos[i].stats = &data->stats;
		if (data->philos[i].id == 1)
			data->philos[i].right_fork = &data->forks[data->stats.philo_count - 1];
		else
			data->philos[i].right_fork = &data->forks[data->philos[i].id - 2];
	}
}

static	int	validate_input(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (!ft_str_is_numeric(argv[i]) || ft_atoi(argv[i]) < 0)
			return (WRONG_ARGUMENT_TYPE);
		i++;
	}

	return (0);
}

static	void init_data(t_data *data)
{
	data->stats.philo_count = 0;
	data->stats.time_to_die = 0;
	data->stats.time_to_eat = 0;
	data->stats.time_to_sleep = 0;
	data->stats.must_eat_count = 0;
	data->threads = NULL;
	data->forks = NULL;
	data->philos = NULL;
}

static	int	set_data(int argc, char **argv, t_data *data)
{
	int i;

	i = -1;
	data->stats.philo_count = ft_atoi(argv[1]);
	data->stats.time_to_die = ft_atoi(argv[2]);
	data->stats.time_to_eat = ft_atoi(argv[3]);
	data->stats.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->stats.must_eat_count = ft_atoi(argv[5]);
	else
		data->stats.must_eat_count = 0;
	data->threads = malloc(sizeof(pthread_t) * data->stats.philo_count);
	data->forks = malloc(sizeof(t_forks) * data->stats.philo_count);
	data->philos = malloc(sizeof(t_philo) * data->stats.philo_count);
	if (!data->threads || !data->forks || !data->philos)
		return (MEMORY_FAIL);
	while (++i < data->stats.philo_count) {
		if (pthread_mutex_init(&data->forks[i].fork, NULL) != 0)
			return (MUTEX_FAIL);
		data->forks[i].taken = false;
	}
	if (pthread_mutex_init(&data->talking, NULL) != 0)
		return (MUTEX_FAIL); 
	if (pthread_mutex_init(&data->grim_reaper.scythe, NULL) != 0)
		return (MUTEX_FAIL); 
	init_philos(data);
	
	return (0);
}

int main(int argc, char **argv)
{
	t_data data;

	init_data(&data);
	if (argc < 5 || argc > 6)
		return ft_exit(NULL, WRONG_ARGUMENT_NB);
	data.error_code = validate_input(argc, argv);
	if (data.error_code)
		return ft_exit(NULL, data.error_code);
	data.error_code = set_data(argc, argv, &data);
	if (data.error_code)
		return ft_exit(&data, data.error_code);
	start_program(&data);
	return ft_exit(&data, SUCCESS);
}
