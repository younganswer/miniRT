#include "../incs/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	target;

	target = (char) c;
	while (*s)
	{
		if (*s == target)
			return ((char *) s);
		s++;
	}
	if (*s == target)
		return ((char *) s);
	return (0);
}
