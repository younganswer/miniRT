/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:00:11 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 15:00:11 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	target;
	char	*res;

	target = (char) c;
	res = 0;
	while (*s)
	{
		if (*s == target)
			res = (char *) s;
		s++;
	}
	if (*s == target)
		res = (char *) s;
	if (res)
		return (res);
	return (0);
}
