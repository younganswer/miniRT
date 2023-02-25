/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:00:18 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 15:00:19 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"
#include <stdlib.h>

t_bool	ft_strsfree(char ***strs)
{
	char	**tmp;

	if (strs == NULL || *strs == NULL)
		return (TRUE);
	tmp = *strs;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(*strs);
	*strs = NULL;
	return (TRUE);
}
