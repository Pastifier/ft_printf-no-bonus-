#include "../ft_printf.h"
#include <stddef.h>

static size_t	ft_xlen(unsigned int x)
{
	int	count;

	count = 0;
	if (!x)
		return (1);
	while (x)
	{
		++count;
		x /= 16;
	}
	return (count);
}

static char	*ft_xtostr(unsigned int x)
{
	char	*self;
	size_t	xlen;
	size_t	mod;

	xlen = ft_xlen(x);
	self = ft_calloc(xlen + 1, sizeof(char));
	if (!self)
		return (NULL);
	while (--xlen != (size_t)-1)
	{
		mod = x % 16;
		if (mod < 10)
			self[xlen] = '0' + mod;
		else
			self[xlen] = 'a' + (mod - 10);
		x /= 16;
	}
	return (self);
}

static char	*ft_xtoa(unsigned int x, bool is_lower)
{
	char	*self;
	char	*dummy;

	self = ft_xtostr(x);
	dummy = self;
	if (!self)
		return (NULL);
	if (!is_lower)
	{
		while (*dummy)
		{
			*dummy = ft_toupper(*dummy);
			++dummy;
		}
	}
	return (self);
}

int	ft_print_hex(unsigned int x, bool is_lower, int *errno)
{
	char	*xstr;
	int		fetch;

	xstr = ft_xtoa(x, is_lower);
	if (!xstr)
	{
		*errno = -1;
		return (0);
	}
	fetch = write(1, xstr, ft_strlen(xstr));
	free(xstr);
	if (fetch < 0)
	{
		*errno = fetch;
		return (0);
	}
	return (fetch);
}
