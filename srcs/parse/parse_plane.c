#include "../../incs/parse.h"

t_bool	parse_plane(t_var *var, char *line);

t_bool	parse_plane(t_var *var, char *line)
{
	t_shape *const	shape
		= ft_calloc(sizeof(t_shape), 1, "Error: Fail to init shape");
	t_plane *const	plane
		= ft_calloc(sizeof(t_plane), 1, "Error: Fail to init plane");

	if (parse_vec3(&plane->point, &line) == FALSE || \
		parse_vec3(&plane->normal, &line) == FALSE || \
		parse_vec3(&plane->color, &line) == FALSE)
		return (FALSE);
	shape->shape = plane;
	shape->type = PLANE;
	ft_lstadd_back(&var->shapes, ft_lstnew(shape));
	return (TRUE);
}
