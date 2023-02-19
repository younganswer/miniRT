#include "../../incs/parse.h"
#include "../../incs/err.h"

t_bool			parse_sphere(t_var *var, char **splited);
static t_bool	parse_radius(t_var *var, double *radius, char *s_radius);

t_bool	parse_sphere(t_var *var, char **splited)
{
	t_object	*object;
	t_sphere	*sphere;

	if (ft_strslen(splited) != 3 && ft_strslen(splited) != 4)
		return (set_err(var, INVALID_ARG) && FALSE);
	object = ft_calloc(sizeof(t_object), 1, "Error: Fail to init object");
	sphere = ft_calloc(sizeof(t_sphere), 1, "Error: Fail to init sphere");
	if (parse_vec3(&sphere->center, splited[0]) == FALSE || \
		parse_radius(var, &sphere->radius, splited[1]) == FALSE || \
		parse_vec3(&sphere->color, splited[2]) == FALSE || \
		parse_type(&sphere->type, splited[3]) == FALSE)
		return (set_err(var, INVALID_ARG) && FALSE);
	object->object = sphere;
	object->shape = SPHERE;
	ft_lstadd_back(&var->objects, ft_lstnew(object));
	return (TRUE);
}

static t_bool	parse_radius(t_var *var, double *radius, char *s_radius)
{
	*radius = ft_atof(s_radius);
	if (*radius <= 0)
		return (set_err(var, INVALID_RANGE) && FALSE);
	return (TRUE);
}
