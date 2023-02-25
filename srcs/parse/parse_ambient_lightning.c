/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_lightning.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:55:41 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 14:55:41 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parse.h"
#include "../../incs/err.h"

t_bool			parse_ambient_lightning(t_var *var, char **splited);
static t_bool	parse_ratio(t_var *var, double *ratio, char *s_ratio);
static t_bool	set_color(t_vec3 *color);

t_bool	parse_ambient_lightning(t_var *var, char **splited)
{
	if (var->alight != NULL)
		return (set_err(var, DUPLICATED_IDENTIFIER) && FALSE);
	if (ft_strslen(splited) != 1 && ft_strslen(splited) != 2)
		return (set_err(var, INVALID_ARG) && FALSE);
	var->alight = ft_calloc(sizeof(t_alight), 1, "Error: Fail to init alight");
	return (
		parse_ratio(var, &var->alight->ratio, splited[0]) && \
		set_color(&var->alight->color)
	);
}

static t_bool	parse_ratio(t_var *var, double *ratio, char *s_ratio)
{
	*ratio = ft_atof(s_ratio);
	if (*ratio < 0 || *ratio > 1)
		return (set_err(var, INVALID_RANGE) && FALSE);
	return (TRUE);
}

static t_bool	set_color(t_vec3 *color)
{
	*color = (t_vec3){256, 256, 256};
	return (TRUE);
}
