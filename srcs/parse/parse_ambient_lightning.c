#include "../../incs/parse.h"

t_bool			parse_ambient_lightning(t_var *var, char **splited);
static t_bool	parse_ratio(double *ratio, char *s_ratio);

t_bool	parse_ambient_lightning(t_var *var, char **splited)
{
	if (ft_strslen(splited) != 2)
		return (FALSE);
	var->alight = ft_calloc(sizeof(t_alight), 1, "Error: Fail to init alight");
	return (
		parse_ratio(&var->alight->ratio, splited[0]) && \
		parse_vec3(&var->alight->color, splited[1])
	);
}

static t_bool	parse_ratio(double *ratio, char *s_ratio)
{
	*ratio = ft_atof(s_ratio);
	if (*ratio < 0 || *ratio > 1)
		return (FALSE);
	return (TRUE);
}
