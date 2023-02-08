#include "../../incs/parse.h"

t_bool			parse_sphere(t_var *var, char *line);
static t_bool	parse_radius(double *radius, char **line);

t_bool	parse_sphere(t_var *var, char *line)
{
	t_shape *const	shape
		= ft_calloc(sizeof(t_shape), 1, "Error: Fail to init shape");
	t_sphere *const	sphere
		= ft_calloc(sizeof(t_sphere), 1, "Error: Fail to init sphere");
	if (parse_vec3(&sphere->center, &line) == FALSE ||
		parse_radius(&sphere->radius, &line) == FALSE ||
		parse_vec3(&sphere->color, &line) == FALSE)
		return (FALSE);
	shape->shape = sphere;
	shape->type = SPHERE;
	ft_lstadd_back(&var->shapes, ft_lstnew(shape));
	return (TRUE);
}

static t_bool	parse_radius(double *radius, char **line)
{
	ft_skip_space((const char **)line);
	*radius = ft_atof(*line);
	while (**line && **line != ' ')
		(*line)++;
	return (TRUE);
}
