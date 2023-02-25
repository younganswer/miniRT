/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:59:13 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 14:59:13 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;

	if (dest == src || !n)
		return (dest);
	if (dest < src)
	{
		dest_tmp = (unsigned char *) dest;
		src_tmp = (unsigned char *) src;
		while (n--)
			*dest_tmp++ = *src_tmp++;
	}
	else
	{
		dest_tmp = (unsigned char *) dest + n;
		src_tmp = (unsigned char *) src + n;
		while (n--)
			*--dest_tmp = *--src_tmp;
	}
	return (dest);
}
