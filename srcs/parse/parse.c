#include "../../incs/parse.h"
#include <fcntl.h>

t_bool	parse(t_var *var, char *file);

t_bool	parse(t_var *var, char *file)
{
	const int	fd = open(file, O_RDONLY);

	if (fd == -1)
		return (FALSE);
	return (parse_camera(var, fd));
}
