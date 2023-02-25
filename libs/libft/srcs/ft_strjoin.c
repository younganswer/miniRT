#include "../incs/libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*res;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = ft_calloc(sizeof(char), len_s1 + len_s2 + 1, "Error: ft_strjoin");
	ft_strlcpy(res, s1, len_s1 + 1);
	ft_strlcat(res + len_s1, s2, len_s2 + 1);
	return (res);
}
