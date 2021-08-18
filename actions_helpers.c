
#include "philosophers.h"

bool	take_fork(pthread_mutex_t *mutex,  t_clock *clock, int id)
{
	if (pthread_mutex_init(mutex, NULL) == 0)
	{
		update_curr_time(clock);
		printf("%ld %d has taken a fork\n", clock->curr, id);
		return (true);
	}
	return (false);
}

void	drop_fork(pthread_mutex_t *mutex)
{

}

int	assign_forks_index(int id, int *first_fork, int *second_fork, t_data *data)
{
	if (id == 1)
	{
		*first_fork = 0;
		*second_fork = data->philo_count - 1;
	}
	else 
	{
		*first_fork = data->philo_count - 1;
		*second_fork = data->philo_count - 2;
	}
}

void try_to_eat(t_data *data, t_clock *clock, int id)
{
	int first_fork;
	int second_fork;

	assign_forks_index(id, &first_fork, &second_fork, data);
	while (true)
	{
		if (take_fork(&data->fork[first_fork], clock, id))
		{
			if (take_fork(&data->fork[second_fork], clock, id))
			{
				eat();
				break;
			}
			else
				drop_fork(&data->fork[first_fork]);
		}
		else 
			usleep(10 * 1000);
	}
}