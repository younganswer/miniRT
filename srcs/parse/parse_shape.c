#include "../../incs/parse.h"

t_bool		parse_shape(t_var *var, int fd);
static void	*parse_sphere(char *line);

t_bool	parse_shape(t_var *var, int fd)
{
	void	*content;

	content = parse_sphere(NULL);
	ft_lstadd_back(&var->shapes, ft_lstnew(content));
	(void) fd;
	return (TRUE);
}

static void	*parse_sphere(char *line)
{
	t_sphere	*ret;

	ret = ft_calloc(sizeof(t_sphere), 1, "Error: Fail to init sphere");
	ret->center = (t_vec3){0, 0, -3};
	ret->radius = 1;
	(void) line;
	return (ret);
}
