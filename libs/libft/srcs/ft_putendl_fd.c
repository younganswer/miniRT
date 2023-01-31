#include "../incs/libft.h"

int	ft_putendl_fd(const char *s, int fd)
{
	int	printed;

	printed = ft_putstr_fd(s, fd);
	printed += ft_putchar_fd('\n', fd);
	return (printed);
}
