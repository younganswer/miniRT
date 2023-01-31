#include "../incs/libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	start;
	size_t	end;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (0 < end && ft_strchr(set, s1[end]))
		end--;
	if (!*s1 || end < start)
		return (ft_strdup(""));
	res = (char *) malloc(sizeof(char) * (end - start + 2));
	if (!res)
		return (0);
	ft_strlcpy(res, &s1[start], end - start + 2);
	return (res);
}
