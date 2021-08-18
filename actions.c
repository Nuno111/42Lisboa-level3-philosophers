#include "philosophers.h"

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

void eat(t_data *data, t_clock *clock, int id)
{
	int first_fork;
	int second_fork;

	assign_forks_index(id, &first_fork, &second_fork, data);
	while (true)
	{
		if (take_fork(first_fork))
		{
			if (take_fork(second_fork))
			{
				eat();
				break;
			}
			else
				drop(first_fork);
		}
		else 
			usleep(100 * 1000);
	}
}

void sleep() {

}

void think() {

}