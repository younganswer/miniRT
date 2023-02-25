/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:58:40 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 14:58:40 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

int	ft_lstindex(t_list *lst, void *content)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		if (lst->content == content)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}
