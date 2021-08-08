#include "philosophers.h"

static	int validate_input(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc - 1)
	{
		if (!ft_str_is_numeric(argv[i]) || ft_atoi(argv[i]) < 0)
			return (1);
		i++;
	}
	return (0);
}

static	int	init_params(int argc, char **argv, t_data *data)
{
	data->philo_count = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat_count = ft_atoi(argv[5]);
	else
		data->must_eat_count = 0;
	data->threads = malloc(sizeof(pthread_t) * data->philo_count);
	if (!data->threads)
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	t_data data;

	if (argc < 5 || argc > 6 || 
	(init_params(argc, argv, &data) && validate_input(argc, argv)) != 0)
	{
		printf("Error. Invalid arguments input.\n");
		exit(1);
	}
	create_threads(&data);
	ft_exit(data.threads, NULL);
	
	return (0);
}
