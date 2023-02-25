#include "../incs/libft.h"
#include <stdlib.h>

char			*ft_itoa(int n);
static void		convert(char *res, long nbr, size_t len);
static size_t	get_num_len(long nbr);

char	*ft_itoa(int n)
{
	char	*res;
	long	nbr;
	size_t	len;

	nbr = (long) n;
	len = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	len += get_num_len(nbr);
	res = (char *) malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	if (n < 0)
		*res = '-';
	convert(res, nbr, len);
	return (res);
}

static void	convert(char *res, long nbr, size_t len)
{
	if (!nbr)
	{
		*res = '0';
		*(res + 1) = '\0';
		return ;
	}
	res += len;
	*res-- = '\0';
	while (nbr)
	{
		*res-- = '0' + (nbr % 10);
		nbr /= 10;
	}
	return ;
}

static size_t	get_num_len(long nbr)
{
	size_t	len;

	if (!nbr)
		return (1);
	len = 0;
	while (nbr)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}
