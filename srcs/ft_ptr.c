#include "../ft_printf.h"
#include <stddef.h>

static size_t	ft_xlen(unsigned long long x)
{
	int	fetch;

	fetch = 0;
	if (!x)
		return (1);
	while (x)
	{
		++fetch;
		x /= 16;
	}
	return (fetch);
}

static char	*ft_xtostr(unsigned long long x)
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

int	ft_print_ptr(unsigned long long x, int *errno)
{
	char	*xstr;
	int		fetch;

	xstr = ft_xtostr(x);
	if (!xstr)
	{
		*errno = -1;
		return (0);
	}
	fetch = write(1, "0x", 2);
	if (fetch < 0)
	{
		*errno = fetch;
		return (0);
	}
	fetch += write(1, xstr, ft_strlen(xstr));
	if (fetch < 0)
	{
		*errno = fetch;
		return (0);
	}
	free(xstr);
	return (fetch);
}
