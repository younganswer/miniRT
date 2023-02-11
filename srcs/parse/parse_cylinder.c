#include "../../incs/parse.h"

t_bool			parse_cylinder(t_var *var, char **splited);
static t_bool	parse_radius_and_height(double *target, char *value);

t_bool	parse_cylinder(t_var *var, char **splited)
{
	t_shape		*shape;
	t_cylinder	*cylinder;

	if (ft_strslen(splited) != 5)
		return (FALSE);
	shape = ft_calloc(sizeof(t_shape), 1, "Error: Fail to init shape");
	cylinder = ft_calloc(sizeof(t_cylinder), 1, "Error: Fail to init cylinder");
	if (parse_vec3(&cylinder->center, splited[0]) == FALSE || \
		parse_vec3(&cylinder->normal, splited[1]) == FALSE || \
		parse_radius_and_height(&cylinder->radius, splited[2]) == FALSE || \
		parse_radius_and_height(&cylinder->height, splited[3]) == FALSE || \
		parse_vec3(&cylinder->color, splited[4]) == FALSE)
		return (FALSE);
	cylinder->normal = vec3_unit(cylinder->normal);
	shape->shape = cylinder;
	shape->type = CYLINDER;
	ft_lstadd_back(&var->shapes, ft_lstnew(shape));
	return (TRUE);
}

static t_bool	parse_radius_and_height(double *target, char *value)
{
	*target = ft_atof(value);
	if (*target <= 0)
		return (FALSE);
	return (TRUE);
}
