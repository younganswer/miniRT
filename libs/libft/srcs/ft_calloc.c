/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:58:03 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 14:58:04 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"
#include <stdlib.h>
#include <errno.h>

void			*ft_calloc(size_t sz_, size_t count, const char *error_msg);
static t_bool	is_invalid_input(size_t sz_, size_t count);

void	*ft_calloc(size_t sz_, size_t count, const char *error_msg)
{
	void	*res;

	if (is_invalid_input(sz_, count))
		ft_exit_with_error(error_msg, errno);
	res = malloc(sz_ * count);
	if (!res)
		ft_exit_with_error(error_msg, errno);
	ft_bzero(res, (sz_ * count));
	return (res);
}

static t_bool	is_invalid_input(size_t sz_, size_t count)
{
	if (SIZE_MAX <= sz_ || SIZE_MAX <= count)
		return (TRUE);
	if (sz_ && SIZE_MAX / sz_ <= count)
		return (TRUE);
	return (FALSE);
}
