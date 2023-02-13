#include "../../incs/parse.h"
#include "../../incs/err.h"

t_bool	parse_plane(t_var *var, char **splited);

t_bool	parse_plane(t_var *var, char **splited)
{
	t_object	*object;
	t_plane		*plane;

	if (ft_strslen(splited) != 3)
		return (set_err(var, INVALID_ARG) && FALSE);
	object = ft_calloc(sizeof(t_object), 1, "Error: Fail to init object");
	plane = ft_calloc(sizeof(t_plane), 1, "Error: Fail to init plane");
	if (parse_vec3(&plane->point, splited[0]) == FALSE || \
		parse_vec3(&plane->normal, splited[1]) == FALSE || \
		parse_vec3(&plane->color, splited[2]) == FALSE)
		return (FALSE);
	plane->normal = vec3_unit(plane->normal);
	object->object = plane;
	object->shape = PLANE;
	ft_lstadd_back(&var->objects, ft_lstnew(object));
	return (TRUE);
}
