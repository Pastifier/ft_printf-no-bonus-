/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:45:14 by ebinjama          #+#    #+#             */
/*   Updated: 2023/11/10 21:32:22 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// Calculates the amount of words in the string.
// (A word is a sequence of characters preceding the delimiter: `c`).
// @param str: The string to split.
// @param c: The delimiter character.
static int	wordcount(const char *str, char c);

// Calculates the length of the first word in the string.
// (A word is a sequence of characters preceding the delimiter: `c`).
// @param str: The string to split.
// @param c: The delimiter character.
static int	wordlen(const char *str, char c);

// Takes care of all the allocations. Returns `true` if
// something went wrong; false otherwise.
// `true` was chosen for failure to make ft_split more readable.
// @param self_ptr: The address of the string array.
// @param str: The string to split.
// @param success: The address of the variable storing the
// 				   number of successful string allocations.
static bool	ealloc(char **self_ptr, const char *str, char c, size_t *success);

// Frees everything. Called upon failure (`allocate_each(...) == true`).
// @param self_ptr: The address of the string array.
// @param successes: The number of successful allocations,
// 					 i.e. the number of times to call `free`.
static void	free_all(char **self_ptr, size_t successes);

char	**ft_split(const char *s, char c)
{
	char	**self;
	size_t	successes;
	bool	abort;

	if (!s)
		return (NULL);
	self = malloc((wordcount(s, c) + 1) * sizeof(char *));
	if (!self)
		return (NULL);
	successes = 0;
	abort = ealloc(self, s, c, &successes);
	if (abort)
	{
		free_all(self, successes);
		return (NULL);
	}
	return (self);
}

int	wordcount(const char *str, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (*str)
	{
		if (*str == c)
			flag = 0;
		else if (*str != c && !flag)
		{
			flag = 1;
			count++;
		}
		str++;
	}
	return (count);
}

int	wordlen(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		++i;
	return (i);
}

bool	ealloc(char **self_ptr, const char *str, char c, size_t *success)
{
	int	i;
	int	j;
	int	wordnum;

	while (*str && *str == c)
		++str;
	i = -1;
	wordnum = wordcount(str, c);
	while (++i < wordnum)
	{
		j = -1;
		self_ptr[i] = malloc((wordlen(str, c) + 1) * sizeof(char));
		if (!self_ptr[i])
			return (true);
		while (*str && *str != c)
			self_ptr[i][++j] = *str++;
		self_ptr[i][++j] = 0;
		while (*str == c && *str)
			++str;
		*success += 1;
	}
	self_ptr[i] = 0;
	return (false);
}

void	free_all(char **self_ptr, size_t successes)
{
	char	**dummy;

	dummy = self_ptr;
	while (successes--)
	{
		free(*dummy);
		dummy++;
	}
	free(self_ptr);
}
