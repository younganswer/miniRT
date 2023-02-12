#include "../../libs/libft/incs/libft.h"
#include "../../libs/libgnl/incs/get_next_line.h"
#include "../../incs/parse.h"
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
	parse_lights,
	parse_sphere,
	parse_plane,
	parse_cylinder,
};

t_bool			parse(t_var *var, char *file);
char			*get_next_line_not_empty(int fd);
t_bool			parse_vec3(t_vec3 *vec, char *line);
static t_bool	parse_each_var(t_var *var, char **splited);
static t_bool	all_var_set_successfully(t_var *var);

t_bool	parse(t_var *var, char *file)
{
	const int	fd = open(file, O_RDONLY);
	char		**splited;
	char		*line;

	if (fd == -1)
		return (FALSE);
	while (TRUE)
	{
		line = get_next_line_not_empty(fd);
		if (line == NULL)
			break ;
		splited = ft_split(line, g_delim);
		free(line);
		if (splited == NULL)
			return (FALSE);
		if (ft_strslen(splited) <= 1)
			return (ft_strsfree(&splited) && FALSE);
		if (parse_each_var(var, splited) == FALSE)
			return (ft_strsfree(&splited) && FALSE);
		ft_strsfree(&splited);
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
	char **const	splited = ft_split(line, ",");

	if (splited == NULL)
		return (FALSE);
	if (ft_strslen(splited) != 3)
		return (ft_strsfree((char ***) &splited) && FALSE);
	vec->x = ft_atof(splited[0]);
	vec->y = ft_atof(splited[1]);
	vec->z = ft_atof(splited[2]);
	return (ft_strsfree((char ***) &splited) == TRUE);
}

static t_bool	parse_each_var(t_var *var, char **splited)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (ft_strncmp(splited[0], g_identifier[i], ft_strlen(splited[0])) == 0)
			return (g_parse_func[i](var, splited + 1));
		i++;
	}
	return (FALSE);
}

static t_bool	all_var_set_successfully(t_var *var)
{
	t_list	*tmp;
	int		shapes[3];

	if (var->camera == NULL)
		return (TRUE);
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
		return (FALSE);
	return (TRUE);
}
