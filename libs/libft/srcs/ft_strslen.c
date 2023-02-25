/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strslen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:00:24 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 15:00:24 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

size_t	ft_strslen(char **strs)
{
	size_t	len;

	if (strs == NULL)
		return (0);
	len = 0;
	while (strs[len])
		len++;
	return (len);
}
