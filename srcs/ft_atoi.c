#include "../includes/philo.h"

size_t ft_strlen(const char *str)
{
	int	size;

	size = 0;
	if (!str)
		return (0);
	while (str[size])
	{
		size++;
	}
	return (size);
}

int ft_atoi(const char *str)
{
	int					i;
	unsigned int		num;

	i = 0;
	num = 0;
	if (!str[i])
        return (-1);    
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
            return (-1);
		num = num * 10 + str[i] - '0';
		i++;
	}
	if (num > 2147483647)
		return (-1);
	return (num);
}