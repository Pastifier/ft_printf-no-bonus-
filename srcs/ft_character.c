#include "../ft_printf.h"

int	ft_print_character(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	if (!str)
		return (write(1, ("(null)"), 6));
	return (write(1, str, ft_strlen(str)));
}
