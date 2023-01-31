#include "../incs/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	target;
	char	*res;

	target = (char) c;
	res = 0;
	while (*s)
	{
		if (*s == target)
			res = (char *) s;
		s++;
	}
	if (*s == target)
		res = (char *) s;
	if (res)
		return (res);
	return (0);
}
