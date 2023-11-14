#include "../ft_printf.h"

int	ft_print_character(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	return (write(1, str, ft_strlen(str)));
}
