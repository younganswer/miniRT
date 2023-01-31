#include "../incs/libft.h"

t_bool	ft_swap(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return (TRUE);
}
