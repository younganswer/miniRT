/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:55:57 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 14:55:57 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/libgnl/incs/get_next_line.h"
#include "../../incs/parse.h"
#include "../../incs/err.h"
#include <stdlib.h>

const static char		*g_type[] = {
	"LAMBERTIAN",
	"DIELECTRIC"
};

char	*get_next_line_not_empty(int fd);
t_bool	parse_vec3(t_var *var, t_vec3 *vec, char *line);
t_bool	parse_type(t_var *var, t_type *type, char *line);

char	*get_next_line_not_empty(int fd)
{
	char	*ret;
	char	*tmp;

	tmp = get_next_line(fd);
	while (tmp && *tmp == '\n')
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
	if (tmp == NULL)
		return (NULL);
	if (tmp[ft_strlen(tmp) - 1] == '\n')
	{
		ret = ft_substr(tmp, 0, ft_strlen(tmp) - 1);
		free(tmp);
	}
	else
		ret = tmp;
	return (ret);
}

t_bool	parse_vec3(t_var *var, t_vec3 *vec, char *line)
{
	size_t	number_of_comma;
	char	*tmp;
	char	**split;

	number_of_comma = 0;
	tmp = line;
	while (tmp && *tmp)
		number_of_comma += (*tmp++ == ',');
	if (number_of_comma != 2)
		return (set_err(var, INVALID_ARG) && FALSE);
	split = ft_split(line, ",");
	if (split == NULL)
		return (set_err(var, GENERIC_ERR) && FALSE);
	if (ft_strslen(split) != 3)
		return (
			set_err(var, INVALID_ARG) && \
			ft_strsfree((char ***) &split) && \
			FALSE
		);
	vec->x = ft_atof(split[0]);
	vec->y = ft_atof(split[1]);
	vec->z = ft_atof(split[2]);
	return (ft_strsfree((char ***) &split));
}

t_bool	parse_type(t_var *var, t_type *type, char *line)
{
	int	i;

	if (line == NULL)
	{
		*type = LAMBERTIAN;
		return (TRUE);
	}
	i = 0;
	while (i < 2)
	{
		if (ft_strcmp(line, g_type[i]) == 0)
		{
			*type = i;
			return (TRUE);
		}
		i++;
	}
	return (set_err(var, INVALID_IDENTIFIER) && FALSE);
}
