#include "../../incs/render.h"

t_bool	render_shape(t_var *var);

t_bool	render_shape(t_var *var)
{
	t_list	*tmp;

	tmp = var->shapes;
	while (tmp)
	{
		if (((t_shape *) tmp->content)->type == SPHERE &&
			render_sphere(var, tmp->content) == FALSE)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}
