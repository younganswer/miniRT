#include "../../libs/libft/incs/libft.h"
#include "../../libs/libgnl/incs/get_next_line.h"
#include "../../incs/parse.h"
#include "../../incs/err.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

const static char		*g_delim = " \t\v\f\r";

const static char		*g_identifier[] = {
	"A",
	"C",
	"L",
	"sp",
	"pl",
	"cy",
};

static t_bool (*const	g_parse_func[])(t_var *, char **) = {
	parse_ambient_lightning,
	parse_camera,
	parse_light,
	parse_sphere,
	parse_plane,
	parse_cylinder,
};

t_bool			parse(t_var *var, char *file);
char			*get_next_line_not_empty(int fd);
t_bool			parse_vec3(t_vec3 *vec, char *line);
static t_bool	parse_each_var(t_var *var, char **split);
static t_bool	all_var_set_successfully(t_var *var);

t_bool	parse(t_var *var, char *file)
{
	const int	fd = open(file, O_RDONLY);
	char		**split;
	char		*line;

	if (fd == -1)
		return (set_err(var, FAIL_TO_OPEN_FILE) && FALSE);
	while (TRUE)
	{
		line = get_next_line_not_empty(fd);
		if (line == NULL)
			break ;
		split = ft_split(line, g_delim);
		free(line);
		if (split == NULL)
			return (set_err(var, GENERIC_ERR) && FALSE);
		if ((ft_strslen(split) <= 1) && set_err(var, INVALID_ARG))
			return (ft_strsfree(&split) && FALSE);
		if (parse_each_var(var, split) == FALSE)
			return (ft_strsfree(&split) && FALSE);
		ft_strsfree(&split);
	}
	return (all_var_set_successfully(var));
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

static t_bool	parse_each_var(t_var *var, char **split)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (ft_strcmp(split[0], g_identifier[i]) == 0)
			return (g_parse_func[i](var, split + 1));
		i++;
	}
	return (set_err(var, INVALID_IDENTIFIER) && FALSE);
}

static t_bool	all_var_set_successfully(t_var *var)
{
	t_list	*tmp;
	int		shapes[3];

	if (var->alight == NULL || var->camera == NULL || var->light == NULL)
		return (set_err(var, INVALID_ARG) && FALSE);
	shapes[0] = 0;
	shapes[1] = 0;
	shapes[2] = 0;
	tmp = var->shapes;
	while (tmp)
	{
		shapes[((t_shape *)tmp->content)->type]++;
		tmp = tmp->next;
	}
	if (shapes[0] == 0 || shapes[1] == 0 || shapes[2] == 0)
		return (set_err(var, INVALID_ARG) && FALSE);
	return (TRUE);
}
