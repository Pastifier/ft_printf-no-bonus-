#include "../ft_printf.h"
#include <stddef.h>

static size_t	ft_xlen(unsigned long x)
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

static char	*ft_xtostr(unsigned long x)
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

static char	*ft_xtoa(unsigned long x, bool is_lower)
{
	char	*self;

	(void)is_lower; // for now
	self = ft_xtostr(x);
	if (!self)
		return (NULL);
	if (is_lower)
		return (self);
	while (*self++)
		*self = ft_toupper(*self);
	return (self);
}

int	ft_print_hex(unsigned long x, bool is_lower)
{
	char	*xstr;
	int		count;

	if (is_lower)
		xstr = ft_xtoa(x, 1);
	else
	 	xstr = ft_xtoa(x, 0);
	if (!xstr)
		return (0);
	count = write(1, xstr, ft_strlen(xstr));
	free(xstr);
	return (count);
}
