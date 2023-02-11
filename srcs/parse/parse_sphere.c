#include "../../incs/parse.h"

t_bool			parse_sphere(t_var *var, char **splited);
static t_bool	parse_radius(double *radius, char *s_radius);

t_bool	parse_sphere(t_var *var, char **splited)
{
	t_shape		*shape;
	t_sphere	*sphere;

	if (ft_strslen(splited) != 3)
		return (FALSE);
	shape = ft_calloc(sizeof(t_shape), 1, "Error: Fail to init shape");
	sphere = ft_calloc(sizeof(t_sphere), 1, "Error: Fail to init sphere");
	if (parse_vec3(&sphere->center, splited[0]) == FALSE || \
		parse_radius(&sphere->radius, splited[1]) == FALSE || \
		parse_vec3(&sphere->color, splited[2]) == FALSE)
		return (FALSE);
	shape->shape = sphere;
	shape->type = SPHERE;
	ft_lstadd_back(&var->shapes, ft_lstnew(shape));
	return (TRUE);
}

static t_bool	parse_radius(double *radius, char *s_radius)
{
	*radius = ft_atof(s_radius);
	if (*radius <= 0)
		return (FALSE);
	return (TRUE);
}
