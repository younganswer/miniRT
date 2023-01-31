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
