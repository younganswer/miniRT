/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:44:27 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 15:44:28 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl_node
{
	char				buff[BUFFER_SIZE];
	size_t				idx;
	struct s_gnl_node	*next;
}	t_gnl_node;

typedef struct s_gnl_list
{
	int					fd;
	t_gnl_node			*head;
	t_gnl_node			*tail;
	struct s_gnl_list	*next;
}	t_gnl_list;

// get_next_line_bonus.c
char		*get_next_line(int fd);
int			ft_read_fd(int fd, t_gnl_list *fd_list);
char		*ft_get_line_from_fd_list(int fd, t_gnl_list **fd_list);
int			ft_remove_line_from_fd_list(t_gnl_list **cur_list, \
										t_gnl_list **fd_list);
int			ft_keep_reading(t_gnl_list *cur_list);

// get_next_line_utils_bonus.c
t_gnl_list	*ft_get_fd_list(int fd, t_gnl_list *fd_list);
t_gnl_node	*ft_insert_node_to_cur_list(t_gnl_list *cur_list);
size_t		ft_strlcat_gnl(char **dest, t_gnl_node *cur_node);
size_t		ft_strncpy_gnl(char *dest, const char *src, size_t n);
size_t		ft_strlen_gnl(const char *str);

#endif