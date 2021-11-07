#include "philosophers.h"

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
	data->philo_count = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->must_eat_count = 0;
	data->must_eat_count = 0;
	data->threads = NULL;
	data->forks = NULL;
}

static	int	set_data(int argc, char **argv, t_data *data)
{
	int i;

	i = -1;
	data->philo_count = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat_count = ft_atoi(argv[5]);
	else
		data->must_eat_count = 0;
	data->threads = malloc(sizeof(pthread_t) * data->philo_count);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->threads || !data->forks)
		return (MEMORY_FAIL);
	while (++i < data->philo_count - 1) {
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (MUTEX_FAIL);
	}
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
	//create_threads(&data);
	return ft_exit(&data, SUCCESS);
}
