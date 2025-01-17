#include "../cub3d.h"

long long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

int	int_abs(int value)
{
	if (value < 0)
		return (-value);
	else
		return (value);
}

int	close_window(t_data *data)
{
	free_data(data);
	exit(0);
}
