#include "../incs/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;

	if (!dest && !src)
		return (0);
	dest_tmp = (unsigned char *) dest;
	src_tmp = (unsigned char *) src;
	while (n--)
		*dest_tmp++ = *src_tmp++;
	return (dest);
}
