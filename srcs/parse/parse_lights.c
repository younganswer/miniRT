#include "../../incs/parse.h"

t_bool			parse_lights(t_var *var, char **splited);
static t_bool	parse_ratio(double *ratio, char *s_ratio);

t_bool	parse_lights(t_var *var, char **splited)
{
	t_light	*light;

	if (ft_strslen(splited) != 3)
		return (FALSE);
	light = ft_calloc(sizeof(t_light), 1, "Error: Fail to init light");
	if (parse_vec3(&light->origin, splited[0]) == FALSE || \
		parse_ratio(&light->ratio, splited[1]) == FALSE || \
		parse_vec3(&light->color, splited[2]) == FALSE)
		return (FALSE);
	ft_lstadd_back(&var->lights, ft_lstnew(light));
	return (TRUE);
}

static t_bool	parse_ratio(double *ratio, char *s_ratio)
{
	*ratio = ft_atof(s_ratio);
	if (*ratio < 0 || *ratio > 1)
		return (FALSE);
	return (TRUE);
}
