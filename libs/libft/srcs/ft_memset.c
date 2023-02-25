#include "../incs/libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	src;

	tmp = (unsigned char *) dest;
	src = (unsigned char) c;
	while (n--)
		*tmp++ = src;
	return (dest);
}
