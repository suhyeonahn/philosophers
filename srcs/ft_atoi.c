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

unsigned int ft_atoi(const char *str)
{
	int					i;
	unsigned long long	num;

	i = 0;
	num = 0;
	if (ft_strlen(str) > 11 || !str[i])
        return (-1);    
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
            return (-1);
		num = num * 10 + str[i] - '0';
		i++;
	}
	if (num > 4294967295)
		return (-1);
	return (num);
}