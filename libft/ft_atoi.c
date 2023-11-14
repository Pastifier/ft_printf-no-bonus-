/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:39:03 by ebinjama          #+#    #+#             */
/*   Updated: 2023/11/10 21:11:20 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Returns true if a character is whitespace.
*/
static bool	is_white(int c);

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	result;

	while (is_white(*str))
		str++;
	sign = 1;
	result = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	while (ft_isdigit(*str))
	{
		result = (result * 10) + ((char)(*str) - '0');
		++str;
	}
	if (result >= 9223372036854775808ULL && sign < 0)
		return (0);
	else if (result >= 9223372036854775808ULL && sign > 0)
		return (-1);
	return (result * sign);
}

bool	is_white(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}
