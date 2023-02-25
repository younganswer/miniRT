#include "../incs/libft.h"
#include <stdlib.h>

t_bool			ft_strappend(char ***dest, const char *src);
static size_t	get_num_of_strs(char **strs);

t_bool	ft_strappend(char ***dest, const char *src)
{
	char **const	res = ft_calloc(sizeof(char *), get_num_of_strs(*dest), "");
	size_t			i;

	i = 0;
	while ((*dest)[i] != NULL)
	{
		res[i] = (*dest)[i];
		i++;
	}
	res[i] = ft_strdup(src);
	res[i + 1] = NULL;
	if (*dest != NULL)
		free(*dest);
	*dest = res;
	return (TRUE);
}

static size_t	get_num_of_strs(char **strs)
{
	size_t	ret;

	ret = 0;
	while (strs[ret])
		ret++;
	return (ret + 1);
}
