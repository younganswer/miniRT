#include "../incs/libft.h"

t_bool	ft_is_space(const int c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (TRUE);
	return (FALSE);
}
