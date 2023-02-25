#include "../incs/libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*res;
	size_t	len;

	len = ft_strlen(str);
	res = (char *) ft_calloc(sizeof(char), len + 1, "");
	ft_strlcpy(res, str, len + 1);
	return (res);
}
