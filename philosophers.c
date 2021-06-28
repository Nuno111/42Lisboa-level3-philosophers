#include "philosophers.h"

static	void	init_threads(t_philos *philos, int argc)
{
	int i;

	i = -1;
	philos->philo = malloc(sizeof(pthread_t *) * argc);
	if (!philos->philo)
		ft_exit(philos->philo, "Unable to allocate memory for threads\n");
	while (++i < argc - 1)
	{
		philos->philo[i] = malloc(sizeof(pthread_t));
		if (!philos->philo[i])
			ft_exit(philos->philo, "Unable to allocate memory for thread\n");
	}
	philos->philo[i] = NULL;
}

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
	return (0);
}

int main(int argc, char **argv)
{
	t_clock clock;
	t_philos philos;

	if (argc < 5 || argc > 6 || init_params(argc, argv, &philos) != 0)
	{
		printf("Error. Invalid arguments input.\n");
		exit (1);
	}
	init_threads(&philos, argc);
	create_threads(&philos, &clock);
	ft_exit(philos.philo, NULL);
	
	return (0);
}
