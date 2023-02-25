/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:59:48 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 14:59:49 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t sz_)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	if (sz_ < dest_len + 1 || !dest || !src)
		return (sz_ + src_len);
	while (src[i] && dest_len + 1 + i < sz_)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
