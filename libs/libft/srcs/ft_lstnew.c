#include "../incs/libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list *const	new = ft_calloc(sizeof(t_list), 1, "");

	new->content = content;
	new->next = NULL;
	return (new);
}
