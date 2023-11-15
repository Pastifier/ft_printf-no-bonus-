#include "../ft_printf.h"
#include <stddef.h>

static size_t	ft_xlen(unsigned long long x)
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

int	ft_print_ptr(unsigned long long x)
{
	char	*xstr;
	int		count;

	xstr = ft_xtostr(x);
	if (!xstr)
		return (0);
	count = write(1, "0x", 2);
	count += write(1, xstr, ft_strlen(xstr));
	return (count);
}
