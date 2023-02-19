#include "../../incs/parse.h"
#include "../../incs/err.h"
#include <stdio.h>
#include <stdlib.h>

t_bool			parse_light(t_var *var, char **splited);
static t_bool	parse_ratio(t_var *var, double *ratio, char *s_ratio);

t_bool	parse_light(t_var *var, char **splited)
{
	t_light	*light;

	if (ft_strslen(splited) != 3)
		return (set_err(var, INVALID_ARG) && FALSE);
	light = ft_calloc(sizeof(t_light), 1, "Failed to allocate memory");
	ft_lstadd_back(&var->lights, ft_lstnew(light));
	if (parse_vec3(&light->origin, splited[0]) == FALSE || \
		parse_ratio(var, &light->ratio, splited[1]) == FALSE || \
		parse_vec3(&light->color, splited[2]) == FALSE)
		return (set_err(var, INVALID_ARG) && FALSE);
	return (TRUE);
}

static t_bool	parse_ratio(t_var *var, double *ratio, char *s_ratio)
{
	*ratio = ft_atof(s_ratio);
	if (*ratio < 0 || *ratio > 1)
		return (set_err(var, INVALID_RANGE) && FALSE);
	return (TRUE);
}
