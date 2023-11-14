/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:59:17 by ebinjama          #+#    #+#             */
/*   Updated: 2023/11/09 16:35:08 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*self;
	char	*dummy;
	size_t	len;

	len = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	self = malloc(sizeof(char) * (len + 1));
	if (!self)
		return (NULL);
	dummy = self;
	while (*s1)
		*dummy++ = *s1++;
	while (*s2)
		*dummy++ = *s2++;
	*dummy = 0;
	return (self);
}
