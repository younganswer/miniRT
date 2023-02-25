#include "../incs/libft.h"

int	ft_putstr_fd(const char *s, int fd)
{
	int	printed;

	printed = 0;
	while (s && *s)
		printed += ft_putchar_fd(*s++, fd);
	return (printed);
}
