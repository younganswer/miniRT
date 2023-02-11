#include "../incs/libft.h"
#include <stdlib.h>

char			**ft_split(char const *s, const char *delim);
static size_t	cnt_strs(char const *s, const char *delim);
static t_bool	get_str(char **dest, char const **s, const char *delim);
static size_t	get_str_len(char const *s, const char *delim);
static char		**force_quit(char **res);

char	**ft_split(char const *s, const char *delim)
{
	char	**res;
	size_t	strs_len;
	size_t	strs_idx;

	strs_len = cnt_strs(s, delim);
	res = (char **) malloc(sizeof(char *) * (strs_len + 1));
	if (!res || !s)
		return (0);
	strs_idx = 0;
	while (*s && strs_idx < strs_len)
	{
		while (*s && ft_strchr(delim, *s))
			s++;
		if (*s)
			if (get_str(&res[strs_idx], &s, delim) == FALSE)
				return (force_quit(res));
		strs_idx++;
	}
	res[strs_idx] = 0;
	return (res);
}

static t_bool	get_str(char **dest, char const **s, const char *delim)
{
	const size_t	str_len = get_str_len(*s, delim);

	*dest = (char *) malloc(sizeof(char) * (str_len + 1));
	if (*dest == NULL)
		return (FALSE);
	ft_strlcpy((char *) *dest, *s, str_len + 1);
	*s += str_len;
	return (TRUE);
}

static size_t	cnt_strs(char const *s, const char *delim)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		while (*s && ft_strchr(delim, *s))
			s++;
		if (*s)
			cnt++;
		while (*s && ft_strchr(delim, *s) == 0)
			s++;
	}
	return (cnt);
}

static size_t	get_str_len(char const *s, const char *delim)
{
	size_t	len;

	len = 0;
	while (s[len] && ft_strchr(delim, s[len]) == 0)
		len++;
	return (len);
}

static char	**force_quit(char **res)
{
	size_t	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
	return (0);
}
