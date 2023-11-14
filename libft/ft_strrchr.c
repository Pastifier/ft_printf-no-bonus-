/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:00:56 by ebinjama          #+#    #+#             */
/*   Updated: 2023/11/08 14:00:42 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*store;

	ptr = (char *)s;
	store = NULL;
	while (*ptr)
	{
		if (*ptr == (char)c)
			store = ptr;
		ptr++;
	}
	if (!(char)c)
		return (ptr);
	return (store);
}
