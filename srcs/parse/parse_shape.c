#include "../../incs/parse.h"
#include <stdlib.h>

t_bool	parse_shape(t_var *var, int fd);

t_bool	parse_shape(t_var *var, int fd)
{
	t_bool	ret;
	char	*line;

	line = get_next_line_not_empty(fd);
	while (line != NULL)
	{
		if (ft_strncmp(line, "sp", 2) == 0)
			ret = parse_sphere(var, line);
		else if (ft_strncmp(line, "pl", 2) == 0)
			ret = parse_plane(var, line);
		else if (ft_strncmp(line, "cy", 2) == 0)
			ret = parse_cylinder(var, line);
		else
			ret = FALSE;
		free(line);
		if (ret == FALSE)
			return (FALSE);
		line = get_next_line_not_empty(fd);
	}
	return (TRUE);
}
