#include "../../incs/parse.h"
#include "../../incs/err.h"

t_bool			parse_plane(t_var *var, char **splited);
static t_bool	normal_to_camera(t_var *var, t_vec3 *point, t_vec3 *normal);

t_bool	parse_plane(t_var *var, char **splited)
{
	t_object	*object;
	t_plane		*plane;

	if (ft_strslen(splited) != 3 || ft_strslen(splited) != 4)
		return (set_err(var, INVALID_ARG) && FALSE);
	object = ft_calloc(sizeof(t_object), 1, "Error: Fail to init object");
	plane = ft_calloc(sizeof(t_plane), 1, "Error: Fail to init plane");
	if (parse_vec3(&plane->point, splited[0]) == FALSE || \
		parse_vec3(&plane->normal, splited[1]) == FALSE || \
		parse_vec3(&plane->color, splited[2]) == FALSE || \
		parse_type(&plane->type, splited[3]) == FALSE)
		return (set_err(var, INVALID_ARG) && FALSE);
	plane->normal = vec3_unit(plane->normal);
	if (normal_to_camera(var, &plane->point, &plane->normal) == FALSE)
		return (FALSE);
	object->object = plane;
	object->shape = PLANE;
	ft_lstadd_back(&var->objects, ft_lstnew(object));
	return (TRUE);
}

static t_bool	normal_to_camera(t_var *var, t_vec3 *point, t_vec3 *normal)
{
	const t_vec3	point_to_camera
		= vec3_unit(vec3_sub(var->camera->ray.origin, *point));
	const double	dot = vec3_dot(point_to_camera, *normal);

	if (dot < 0)
		*normal = vec3_reverse(*normal);
	return (TRUE);
}
