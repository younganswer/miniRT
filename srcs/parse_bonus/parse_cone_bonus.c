/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:56:20 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 14:56:21 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parse.h"
#include "../../incs/err.h"

t_bool			parse_cone(t_var *var, char **splited);
static t_bool	parse_radius(t_var *var, double *radius, char *s_radius);
static t_bool	parse_height(t_var *var, double *height, char *s_height);

t_bool	parse_cone(t_var *var, char **splited)
{
	t_object	*object;
	t_cone		*cone;

	if (ft_strslen(splited) != 5 && ft_strslen(splited) != 6)
		return (set_err(var, INVALID_ARG) && FALSE);
	object = ft_calloc(sizeof(t_object), 1, "Error: Fail to init object");
	cone = ft_calloc(sizeof(t_cone), 1, "Error: Fail to init cone");
	if (parse_vec3(var, &cone->center, splited[0]) == FALSE || \
		parse_vec3(var, &cone->normal, splited[1]) == FALSE || \
		dir_range_is_valid(var, cone->normal) == FALSE || \
		parse_radius(var, &cone->radius, splited[2]) == FALSE || \
		parse_height(var, &cone->height, splited[3]) == FALSE || \
		parse_vec3(var, &cone->color, splited[4]) == FALSE || \
		color_range_is_valid(var, cone->color) == FALSE || \
		parse_type(var, &cone->type, splited[5]) == FALSE)
		return (FALSE);
	cone->normal = vec3_unit(cone->normal);
	object->object = cone;
	object->shape = CONE;
	ft_lstadd_back(&var->objects, ft_lstnew(object));
	return (TRUE);
}

static t_bool	parse_radius(t_var *var, double *radius, char *s_radius)
{
	*radius = (ft_atof(s_radius) / 2);
	if (*radius <= 0)
		return (set_err(var, INVALID_RANGE) && FALSE);
	return (TRUE);
}

static t_bool	parse_height(t_var *var, double *height, char *s_height)
{
	*height = ft_atof(s_height);
	if (*height <= 0)
		return (set_err(var, INVALID_RANGE) && FALSE);
	return (TRUE);
}
