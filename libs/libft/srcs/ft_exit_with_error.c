#include "../incs/libft.h"
#include <stdlib.h>

void	ft_exit_with_error(const char *err_msg, int exit_status)
{
	if (err_msg)
		ft_putendl_fd(err_msg, 2);
	exit(exit_status);
}
