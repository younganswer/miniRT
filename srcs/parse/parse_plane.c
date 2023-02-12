#include "../../incs/parse.h"
#include "../../incs/err.h"

t_bool	parse_plane(t_var *var, char **splited);

t_bool	parse_plane(t_var *var, char **splited)
{
	t_shape	*shape;
	t_plane	*plane;

	if (ft_strslen(splited) != 3)
		return (set_err(var, INVALID_ARG) && FALSE);
	shape = ft_calloc(sizeof(t_shape), 1, "Error: Fail to init shape");
	plane = ft_calloc(sizeof(t_plane), 1, "Error: Fail to init plane");
	if (parse_vec3(&plane->point, splited[0]) == FALSE || \
		parse_vec3(&plane->normal, splited[1]) == FALSE || \
		parse_vec3(&plane->color, splited[2]) == FALSE)
		return (FALSE);
	plane->normal = vec3_unit(plane->normal);
	shape->shape = plane;
	shape->type = PLANE;
	ft_lstadd_back(&var->shapes, ft_lstnew(shape));
	return (TRUE);
}
