/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_with_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:58:05 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 14:58:06 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"
#include <stdlib.h>

void	ft_exit_with_error(const char *err_msg, int exit_status)
{
	if (err_msg)
		ft_putendl_fd(err_msg, 2);
	exit(exit_status);
}
