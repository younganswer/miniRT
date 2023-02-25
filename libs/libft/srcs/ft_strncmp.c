/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:00:04 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 15:00:05 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (0 - (int) *s2);
	if (!s2)
		return (*s1);
	us1 = (unsigned char *) s1;
	us2 = (unsigned char *) s2;
	while (n--)
	{
		if (*us1 - *us2)
			return (*us1 - *us2);
		if (!(*us1) || !(*us2))
			break ;
		us1++;
		us2++;
	}
	return (0);
}
