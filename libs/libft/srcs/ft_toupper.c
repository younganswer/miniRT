/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:00:40 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 15:00:41 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

int			ft_toupper(int c);
static int	ft_islower(int c);

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	return (c);
}

static int	ft_islower(int c)
{
	return (97 <= c && c <= 122);
}
