#include "../incs/libft.h"

void	ft_bzero(void *b, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *) b;
	while (n--)
		*tmp++ = 0;
	return ;
}
