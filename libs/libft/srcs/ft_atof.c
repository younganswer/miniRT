/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:57:54 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 14:57:55 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

double	ft_atof(const char *str);
int		get_integer_part(const char **str);
double	get_decimal_part(const char **str);

double	ft_atof(const char *str)
{
	double	ret;
	int		sign;

	if (str == NULL)
		return (0);
	ft_skip_space(&str);
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	ret = get_integer_part(&str);
	if (*str == '.')
	{
		str++;
		ret += get_decimal_part(&str);
	}
	return (ret * sign);
}

int	get_integer_part(const char **str)
{
	int	ret;

	if (str == NULL || *str == NULL)
		return (0);
	ret = 0;
	while (ft_isdigit(**str))
		ret = ret * 10 + (*(*str)++ - '0');
	return (ret);
}

double	get_decimal_part(const char **str)
{
	double	ret;
	double	dec;

	if (str == NULL || *str == NULL)
		return (0);
	ret = 0;
	dec = 0.1;
	while (ft_isdigit(**str))
	{
		ret += (*(*str)++ - '0') * dec;
		dec *= 0.1;
	}
	return (ret);
}
