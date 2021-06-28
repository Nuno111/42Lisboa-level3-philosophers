#include "philosophers.h"

static	int	init_params(int argc, char **argv, t_philos *philos)
{
	int i;

	i = 1;
	while (i < argc - 1)
	{
		if (!ft_str_is_numeric(argv[i]) || ft_atoi(argv[i]) < 0)
			return (1);
		i++;
	}
	philos->count = ft_atoi(argv[1]);
	philos->time_to_die = ft_atoi(argv[2]);
	philos->time_to_eat = ft_atoi(argv[3]);
	philos->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philos->must_eat_count = ft_atoi(argv[5]);
	else
		philos->must_eat_count = 0;
	philos->threads = malloc(sizeof(pthread_t) * philos->count);
	if (!philos->threads)
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	t_clock clock;
	t_philos philos;

	if (argc < 5 || argc > 6 || init_params(argc, argv, &philos) != 0)
	{
		printf("Error. Invalid arguments input.\n");
		exit(1);
	}
	create_threads(&philos, &clock);
	ft_exit(philos.threads, NULL);
	
	return (0);
}
