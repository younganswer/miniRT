#include "../incs/libft.h"
#include <unistd.h>

int	ft_putchar_fd(const char c, int fd)
{
	return (write(fd, &c, 1));
}
