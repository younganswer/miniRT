/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:00:08 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 15:00:09 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strnstr(const char *s, const char *target, size_t n)
{
	size_t	s_len;
	size_t	target_len;

	if (!(*target))
		return ((char *) s);
	s_len = ft_strlen(s);
	target_len = ft_strlen(target);
	if (s_len < target_len || n < target_len)
		return (0);
	while (target_len <= n--)
	{
		if (!ft_memcmp(s, target, target_len))
			return ((char *) s);
		s++;
	}
	return (0);
}
