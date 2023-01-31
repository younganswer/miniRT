#include "../incs/libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	unsigned long long	nbr;
	int					sign;
	size_t				i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && ('0' <= str[i] && str[i] <= '9'))
	{
		nbr = 10 * nbr + (str[i] - '0');
		if (sign == 1 && __LONG_LONG_MAX__ < nbr)
			return (-1);
		if (sign == -1 && (unsigned long long) __LONG_LONG_MAX__ + 1 < nbr)
			return (0);
		i++;
	}
	return ((int) nbr * sign);
}
