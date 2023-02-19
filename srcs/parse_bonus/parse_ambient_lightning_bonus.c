#include "../../incs/parse.h"
#include "../../incs/err.h"

t_bool			parse_ambient_lightning(t_var *var, char **splited);
static t_bool	parse_ratio(t_var *var, double *ratio, char *s_ratio);

t_bool	parse_ambient_lightning(t_var *var, char **splited)
{
	if (var->alight != NULL)
		return (set_err(var, DUPLICATED_IDENTIFIER) && FALSE);
	if (ft_strslen(splited) != 2)
		return (set_err(var, INVALID_ARG) && FALSE);
	var->alight = ft_calloc(sizeof(t_alight), 1, "Error: Fail to init alight");
	return (
		parse_ratio(var, &var->alight->ratio, splited[0]) && \
		parse_vec3(&var->alight->color, splited[1])
	);
}

static t_bool	parse_ratio(t_var *var, double *ratio, char *s_ratio)
{
	*ratio = ft_atof(s_ratio);
	if (*ratio < 0 || *ratio > 1)
		return (set_err(var, INVALID_RANGE) && FALSE);
	return (TRUE);
}
