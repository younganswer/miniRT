#include "../incs/libft.h"

t_bool	ft_skip_space(const char **str)
{
	if (str == NULL || *str == NULL)
		return (TRUE);
	while (ft_is_space(**str))
		(*str)++;
	return (TRUE);
}
