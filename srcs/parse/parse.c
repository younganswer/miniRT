#include "../../libs/libft/incs/libft.h"
#include "../../libs/libgnl/incs/get_next_line.h"
#include "../../incs/parse.h"
#include <fcntl.h>
#include <unistd.h>

t_bool	parse(t_var *var, char *file);
char	*get_next_line_not_empty(int fd);
t_bool	parse_vec3(t_vec3 *vec, char **line);

t_bool	parse(t_var *var, char *file)
{
	const int	fd = open(file, O_RDONLY);

	if (fd == -1)
		return (FALSE);
	return (
		parse_ambient_lightning(var, fd) &&
		parse_camera(var, fd) &&
		parse_light(var, fd) &&
		parse_shape(var, fd) &&
		(close(fd) != -1)
	);
}

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

t_bool	parse_vec3(t_vec3 *vec, char **line)
{
	char	**split;

	split = ft_split(*line, ',');
	if (split == NULL)
		return (FALSE);
	if (ft_strslen(split) != 3)
		return (ft_strsfree(&split) == FALSE);
	vec->x = ft_atof(split[0]);
	vec->y = ft_atof(split[1]);
	vec->z = ft_atof(split[2]);
	return (ft_strsfree(&split) == TRUE);
}
