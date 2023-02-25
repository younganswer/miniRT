#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

// Part 1 - Libc functions
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
size_t			ft_strlen(const char *str);
void			*ft_memset(void *dest, int c, size_t n);
void			ft_bzero(void *b, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
size_t			ft_strlcpy(char *dest, const char *src, size_t sz_);
size_t			ft_strlcat(char *dest, const char *src, size_t sz_);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnstr(const char *s, const char *target, size_t n);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t sz_, size_t count, const char *error_msg);
char			*ft_strdup(const char *str);

// Part 2 - Additional functions
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, const char *delim);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
int				ft_putchar_fd(const char c, int fd);
int				ft_putstr_fd(const char *s, int fd);
int				ft_putendl_fd(const char *s, int fd);
int				ft_putnbr_fd(int n, int fd);

// Bonus
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(
					t_list *lst, void *(*f)(void *), void (*del)(void *));

// Custom types
typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

// Custom functions to use
void			ft_exit_with_error(const char *err_msg, int exit_status);
t_bool			ft_is_space(const int c);
int				ft_strcmp(const char *s1, const char *s2);
t_bool			ft_strcat(char **dest, const char *src);
t_bool			ft_strncat(char **dest, const char *src, size_t n);
t_bool			ft_strappend(char ***dest, const char *src);
t_bool			ft_swap(void **a, void **b);
int				ft_lstindex(t_list *lst, void *content);
size_t			ft_strslen(char **strs);
t_bool			ft_strsfree(char ***strs);
t_bool			ft_skip_space(const char **str);
double			ft_atof(const char *str);

#endif