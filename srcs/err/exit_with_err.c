#include "../../libs/libft/incs/libft.h"
#include "../../incs/err.h"
#include <stdlib.h>

int	exit_with_err(t_var *var);

int	exit_with_err(t_var *var)
{
	if (var->err == 0)
		exit(0);
	ft_putendl_fd("Error", 2);
	if (var->err == GENERIC_ERR)
		ft_exit_with_error("Generic error", GENERIC_ERR);
	else if (var->err == INVALID_FILENAME)
		ft_exit_with_error("Invalid filename", INVALID_FILENAME);
	else if (var->err == FAIL_TO_OPEN_FILE)
		ft_exit_with_error("Fail to open file", FAIL_TO_OPEN_FILE);
	else if (var->err == INVALID_IDENTIFIER)
		ft_exit_with_error("Invalid identifier", INVALID_IDENTIFIER);
	else if (var->err == INVALID_ARG)
		ft_exit_with_error("Invalid argument", INVALID_ARG);
	else if (var->err == INVALID_RANGE)
		ft_exit_with_error("Invalid range", INVALID_RANGE);
	else if (var->err == DUPLICATED_IDENTIFIER)
		ft_exit_with_error("Duplicated identifier", DUPLICATED_IDENTIFIER);
	else
		ft_exit_with_error("Unknown error", GENERIC_ERR);
	return (0);
}
