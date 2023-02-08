#include "../../incs/render.h"

t_bool	render_shape(t_var *var);

t_bool	render_shape(t_var *var)
{
	t_list	*tmp;
	t_shape	*shape;

	tmp = var->shapes;
	while (tmp)
	{
		shape = tmp->content;
		if (shape->type == SPHERE &&
			render_sphere(var, shape->shape) == FALSE)
			return (FALSE);
		if (shape->type == PLANE &&
			render_plane(var, shape->shape) == FALSE)
			return (FALSE);
		if (shape->type == CYLINDER &&
			render_cylinder(var, shape->shape) == FALSE)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}
