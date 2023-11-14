#include "../ft_printf.h"

static size_t	digitnum(unsigned int nbr)
{
	int	count;

	count = 0;
	if (!nbr)
		return (1);
	while (nbr >= 1)
	{
		++count;
		nbr /= 10;
	}
	return (count);
} /*-------CHECK--------*/

static char	*ft_utoa(unsigned int nbr)
{
	char	*self;
	size_t	digits;

	digits = digitnum(nbr);
	self = ft_calloc(digits + 1, sizeof(char));
	if (!self)
		return (NULL);
	while (--digits)
	{
		self[digits] = '0' + (nbr % 10);
		nbr /= 10;
	}
	self[digits] = '0' + (nbr % 10);
	return (self);
}

int	ft_print_int(int nbr)
{
	char	*nbstr;
	int		count;

	nbstr = ft_itoa(nbr);
	if (!nbstr)
		return (0);
	count = write(1, nbstr, ft_strlen(nbstr));
	free(nbstr);
	return (count);
}

int	ft_print_uint(unsigned int nbr)
{
	char	*nbstr;
	int		count;

	nbstr = ft_utoa(nbr);
	if (!nbstr)
		return (0);
	count = write(1, nbstr, ft_strlen(nbstr));
	free(nbstr);
	return (count);
}
