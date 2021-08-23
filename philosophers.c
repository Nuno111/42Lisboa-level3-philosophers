#include "philosophers.h"

static	void validate_input(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc - 1)
	{
		if (!ft_str_is_numeric(argv[i]) || ft_atoi(argv[i]) < 0)
			ft_exit(NULL, WRONG_ARGUMENT_TYPE);
		i++;
	}
}

static	void init_params(int argc, char **argv, t_data *data)
{
	data->philo_count = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat_count = ft_atoi(argv[5]);
	else
		data->must_eat_count = 0;
	data->fork= malloc(sizeof(pthread_mutex_t) * (data->philo_count));
	if (!data->fork)
		ft_exit(NULL, MEMORY_FAIL);
	ft_memset(data->fork, 1, data->philo_count / 2);
}

int main(int argc, char **argv)
{
	t_data data;

	if (argc < 5 || argc > 6 )
		ft_exit(NULL, WRONG_ARGUMENT_NB);
	init_params(argc, argv, &data);
	validate_input(argc, argv);
	create_threads(&data);
	return (0);
}
