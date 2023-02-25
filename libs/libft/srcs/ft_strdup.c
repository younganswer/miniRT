/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:59:41 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 14:59:42 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*res;
	size_t	len;

	len = ft_strlen(str);
	res = (char *) ft_calloc(sizeof(char), len + 1, "");
	ft_strlcpy(res, str, len + 1);
	return (res);
}
