#include "../incs/libft.h"
#include <stdlib.h>

t_bool	ft_strsfree(char ***strs)
{
	char	**tmp;

	if (strs == NULL || *strs == NULL)
		return (TRUE);
	tmp = *strs;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(*strs);
	*strs = NULL;
	return (TRUE);
}
