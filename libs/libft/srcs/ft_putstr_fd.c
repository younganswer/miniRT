/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:59:25 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 14:59:25 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

int	ft_putstr_fd(const char *s, int fd)
{
	int	printed;

	printed = 0;
	while (s && *s)
		printed += ft_putchar_fd(*s++, fd);
	return (printed);
}
