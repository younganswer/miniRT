#include "../incs/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t sz_)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	if (sz_ < dest_len + 1 || !dest || !src)
		return (sz_ + src_len);
	while (src[i] && dest_len + 1 + i < sz_)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
