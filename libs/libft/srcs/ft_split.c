#include "../incs/libft.h"
#include <stdlib.h>

char			**ft_split(char const *s, char c);
static char		*get_word(char const *s, char c, size_t *s_idx);
static size_t	cnt_words(char const *s, char c);
static size_t	cnt_word_len(char const *s, char c);
static char		**force_quit(char **res);

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	words_len;
	size_t	words_idx;
	size_t	s_idx;

	words_len = cnt_words(s, c);
	res = (char **) malloc(sizeof(char *) * (words_len + 1));
	if (!res || !s)
		return (0);
	words_idx = 0;
	s_idx = 0;
	while (s[s_idx] && words_idx < words_len)
	{
		while (s[s_idx] && s[s_idx] == c)
			s_idx++;
		if (s[s_idx])
			res[words_idx++] = get_word(s, c, &s_idx);
		if (!res[words_idx - 1])
			return (force_quit(res));
	}
	res[words_idx] = 0;
	return (res);
}

static char	*get_word(char const *s, char c, size_t *s_idx)
{
	char	*res;
	size_t	word_len;

	word_len = cnt_word_len(&s[*s_idx], c);
	res = (char *) malloc(sizeof(char) * (word_len + 1));
	if (!res)
		return (0);
	ft_strlcpy(res, &s[*s_idx], word_len + 1);
	*s_idx += word_len;
	return (res);
}

static size_t	cnt_words(char const *s, char c)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			cnt++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (cnt);
}

static size_t	cnt_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
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
