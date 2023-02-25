/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:59:15 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 14:59:15 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	src;

	tmp = (unsigned char *) dest;
	src = (unsigned char) c;
	while (n--)
		*tmp++ = src;
	return (dest);
}
