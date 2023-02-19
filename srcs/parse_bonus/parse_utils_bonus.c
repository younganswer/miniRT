#include "../../libs/libgnl/incs/get_next_line.h"
#include "../../incs/parse.h"
#include "../../incs/err.h"
#include <stdlib.h>

const static char		*g_type[] = {
	"LAMBERTIAN",
	"DIELECTRIC"
};

char	*get_next_line_not_empty(int fd);
t_bool	parse_vec3(t_vec3 *vec, char *line);
t_bool	parse_type(t_type *type, char *line);

char	*get_next_line_not_empty(int fd)
{
	char	*ret;

	ret = get_next_line(fd);
	while (ret && *ret == '\n')
	{
		free(ret);
		ret = get_next_line(fd);
	}
	return (ret);
}

t_bool	parse_vec3(t_vec3 *vec, char *line)
{
	char **const	split = ft_split(line, ",");

	if (split == NULL)
		return (FALSE);
	if (ft_strslen(split) != 3)
		return (ft_strsfree((char ***) &split) && FALSE);
	vec->x = ft_atof(split[0]);
	vec->y = ft_atof(split[1]);
	vec->z = ft_atof(split[2]);
	return (ft_strsfree((char ***) &split) == TRUE);
}

t_bool	parse_type(t_type *type, char *line)
{
	int	i;

	if (line == NULL)
	{
		*type = LAMBERTIAN;
		return (TRUE);
	}
	ft_putendl_fd(line, 2);
	i = 0;
	while (i < 2)
	{
		if (ft_strcmp(line, g_type[i]) == 0)
		{
			*type = i;
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}
