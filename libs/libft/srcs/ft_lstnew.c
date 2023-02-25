/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:58:50 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 14:58:51 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list *const	new = ft_calloc(sizeof(t_list), 1, "");

	new->content = content;
	new->next = NULL;
	return (new);
}
