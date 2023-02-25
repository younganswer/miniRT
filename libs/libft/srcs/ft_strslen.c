#include "../incs/libft.h"

size_t	ft_strslen(char **strs)
{
	size_t	len;

	if (strs == NULL)
		return (0);
	len = 0;
	while (strs[len])
		len++;
	return (len);
}
