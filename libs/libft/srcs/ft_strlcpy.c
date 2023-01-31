#include "../incs/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t sz_)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (!dest || !src || !sz_)
		return (src_len);
	i = 0;
	while (src[i] && i < (sz_ - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
