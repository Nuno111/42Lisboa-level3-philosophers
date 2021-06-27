#include "philosophers.h"

void	get_curr_time(t_clock *clock)
{
	gettimeofday(&clock->saved_time, NULL);
	clock->curr = (clock->saved_time.tv_sec - clock->start) * 1000;
}

static	void	init_params(int argc, char **argv)
{

}
int main(int argc, char **argv)
{
	struct timeval cur_time;
	t_clock clock;

	init_params(argc, argv);
	gettimeofday(&cur_time, NULL);
	clock.start = cur_time.tv_sec;
	sleep(3);
	get_curr_time(&clock);
	printf("%ld\n", clock.curr);

	return (0);
}
