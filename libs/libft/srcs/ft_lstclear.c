/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:58:33 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 14:58:33 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*to_del;

	if (lst == NULL)
		return ;
	tmp = *lst;
	while (tmp)
	{
		to_del = tmp;
		tmp = tmp->next;
		ft_lstdelone(to_del, del);
	}
	*lst = 0;
	return ;
}
