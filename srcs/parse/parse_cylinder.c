#include "../../incs/parse.h"

t_bool			parse_cylinder(t_var *var, char *line);
static t_bool	set_radius_height(t_cylinder *cylinder, char **line);

t_bool	parse_cylinder(t_var *var, char *line)
{
	t_shape *const	shape
		= ft_calloc(sizeof(t_shape), 1, "Error: Fail to init shape");
	t_cylinder *const	cylinder
		= ft_calloc(sizeof(t_cylinder), 1, "Error: Fail to init cylinder");
	if (parse_vec3(&cylinder->center, &line) == FALSE || \
		parse_vec3(&cylinder->normal, &line) == FALSE || \
		set_radius_height(cylinder, &line) == FALSE || \
		parse_vec3(&cylinder->color, &line) == FALSE)
		return (FALSE);
	cylinder->normal = vec3_unit(cylinder->normal);
	shape->shape = cylinder;
	shape->type = CYLINDER;
	ft_lstadd_back(&var->shapes, ft_lstnew(shape));
	return (TRUE);
}

static t_bool	set_radius_height(t_cylinder *cylinder, char **line)
{
	ft_skip_space((const char **)line);
	cylinder->radius = ft_atof(*line);
	while (**line && **line != ' ')
		(*line)++;
	ft_skip_space((const char **)line);
	cylinder->height = ft_atof(*line);
	while (**line && **line != ' ')
		(*line)++;
	return (TRUE);
}
