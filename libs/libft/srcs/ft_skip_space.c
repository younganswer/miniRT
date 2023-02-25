/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:59:27 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 14:59:27 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

t_bool	ft_skip_space(const char **str)
{
	if (str == NULL || *str == NULL)
		return (TRUE);
	while (ft_is_space(**str))
		(*str)++;
	return (TRUE);
}
