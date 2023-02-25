/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:55:48 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 14:55:49 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parse.h"
#include "../../incs/err.h"

t_bool			parse_light(t_var *var, char **splited);
static t_bool	parse_ratio(t_var *var, double *ratio, char *s_ratio);
static t_bool	set_color(t_vec3 *color);

t_bool	parse_light(t_var *var, char **splited)
{
	t_light	*light;

	if (0 < ft_lstsize(var->lights))
		return (set_err(var, DUPLICATED_IDENTIFIER) && FALSE);
	if (ft_strslen(splited) != 2 && ft_strslen(splited) != 3)
		return (set_err(var, INVALID_ARG) && FALSE);
	light = ft_calloc(sizeof(t_light), 1, "Failed to allocate memory");
	ft_lstadd_back(&var->lights, ft_lstnew(light));
	if (parse_vec3(var, &light->origin, splited[0]) == FALSE || \
		parse_ratio(var, &light->ratio, splited[1]) == FALSE || \
		set_color(&light->color) == FALSE)
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

static t_bool	set_color(t_vec3 *color)
{
	*color = (t_vec3){256, 256, 256};
	return (TRUE);
}
