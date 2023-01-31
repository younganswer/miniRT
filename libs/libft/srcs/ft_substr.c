#include "../incs/libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	res = ft_calloc(sizeof(char), len + 1, "Error: ft_substr");
	ft_strlcpy(res, &s[start], len + 1);
	return (res);
}
