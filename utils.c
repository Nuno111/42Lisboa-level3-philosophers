#include "philosophers.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

bool	ft_str_is_numeric(char *str)
{
	int	i;

	if (!str)
		return (false);
	i = 0;
	if (str[0] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '\0')
		return (true);
	return (false);
}

void	ft_freearrays(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	num;

	sign = 1;
	num = 0;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 45)
	{
		sign *= -1;
		str++;
	}
	else if (*str == 43)
		str++;
	while (*str >= 48 && *str <= 57)
	{
		num = num * 10;
		num += (sign * (*(str++) - '0'));
		if (num > 2147483647)
			return (-1);
		if (num < -2147483648)
			return (0);
	}
	return (num);
}