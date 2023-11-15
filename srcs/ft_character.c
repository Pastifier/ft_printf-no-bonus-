#include "../ft_printf.h"

int	ft_print_character(int c, int *errno)
{
	int	fetch;

	fetch = write(1, &c, 1);
	if (fetch < 0)
	{
		*errno = fetch;
		return (0);
	}
	return (fetch);
}

int	ft_print_str(char *str, int *errno)
{
	int	fetch;

	if (!str)
	{
		fetch = write(1, ("(null)"), 6);
		if (fetch < 0)
		{
			*errno = fetch;
			return (0);
		}
		return (fetch);
	}
	return (write(1, str, ft_strlen(str)));
}
