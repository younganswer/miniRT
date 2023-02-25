/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:59:20 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 14:59:21 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

int	ft_putendl_fd(const char *s, int fd)
{
	int	printed;

	printed = ft_putstr_fd(s, fd);
	printed += ft_putchar_fd('\n', fd);
	return (printed);
}
