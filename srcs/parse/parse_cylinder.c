#include "../../incs/parse.h"
#include "../../incs/err.h"

t_bool			parse_cylinder(t_var *var, char **splited);
static t_bool	parse_height(t_var *var, double *target, char *value);
static t_bool	parse_radius(t_var *var, double *radius, char *s_radius);
t_bool	parse_cylinder(t_var *var, char **splited)
{
	t_object	*object;
	t_cylinder	*cylinder;

	if (ft_strslen(splited) != 5)
		return (set_err(var, INVALID_ARG) && FALSE);
	object = ft_calloc(sizeof(t_object), 1, "Error: Fail to init object");
	cylinder = ft_calloc(sizeof(t_cylinder), 1, "Error: Fail to init cylinder");
	if (parse_vec3(&cylinder->center, splited[0]) == FALSE || \
		parse_vec3(&cylinder->normal, splited[1]) == FALSE || \
		dir_range_is_valid(var, cylinder->normal) == FALSE || \
		parse_radius(var, &cylinder->radius, splited[2]) == FALSE || \
		parse_height(var, &cylinder->height, splited[3]) == FALSE || \
		parse_vec3(&cylinder->color, splited[4]) == FALSE || \
		color_range_is_valid(var, cylinder->color) == FALSE)
		return (FALSE);
	cylinder->normal = vec3_unit(cylinder->normal);
	object->object = cylinder;
	object->shape = CYLINDER;
	ft_lstadd_back(&var->objects, ft_lstnew(object));
	return (TRUE);
}

static t_bool	parse_height(t_var *var, double *target, char *value)
{
	*target = ft_atof(value);
	if (*target <= 0)
		return (set_err(var, INVALID_RANGE) && FALSE);
	return (TRUE);
}

static t_bool	parse_radius(t_var *var, double *radius, char *s_radius)
{
	*radius = (ft_atof(s_radius) / 2);
	if (*radius <= 0)
		return (set_err(var, INVALID_RANGE) && FALSE);
	return (TRUE);
}
