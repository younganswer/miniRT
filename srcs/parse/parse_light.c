#include "../../incs/parse.h"
#include "../../incs/err.h"

t_bool			parse_light(t_var *var, char **splited);
static t_bool	parse_ratio(t_var *var, double *ratio, char *s_ratio);

t_bool	parse_light(t_var *var, char **splited)
{
	if (var->light != NULL)
		return (set_err(var, DUPLICATED_IDENTIFIER) && FALSE);
	if (ft_strslen(splited) != 3)
		return (set_err(var, INVALID_ARG) && FALSE);
	var->light = ft_calloc(sizeof(t_light), 1, "Error: Fail to init light");
	return (
		parse_vec3(&var->light->origin, splited[0]) && \
		parse_ratio(var, &var->light->ratio, splited[1]) && \
		parse_vec3(&var->light->color, splited[2])
	);
}

static t_bool	parse_ratio(t_var *var, double *ratio, char *s_ratio)
{
	*ratio = ft_atof(s_ratio);
	if (*ratio < 0 || *ratio > 1)
		return (set_err(var, INVALID_RANGE) && FALSE);
	return (TRUE);
}
