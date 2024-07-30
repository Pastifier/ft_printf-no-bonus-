#include "../ft_printf.h"

static int	ft_print_conversion(char specifier, va_list ap, int *errno)
{
	if (specifier == '%')
	  return (ft_print_character('%', errno));
	if (specifier == 'c')
		return (ft_print_character(va_arg(ap, int), errno));
	if (specifier == 's')
		return (ft_print_str(va_arg(ap, char *), errno));
	if (specifier == 'd' || specifier == 'i')
		return (ft_print_int(va_arg(ap, int), errno));
	if (specifier == 'u')
		return (ft_print_uint(va_arg(ap, unsigned int), errno));
	if (specifier == 'x')
		return (ft_print_hex(va_arg(ap, unsigned long), 1, errno));
	if (specifier == 'X')
		return (ft_print_hex(va_arg(ap, unsigned long), 0, errno));
	if (specifier == 'p')
		return (ft_print_ptr(va_arg(ap, unsigned long long), errno));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;
	int		err;

	count = 0;
	err = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			count += ft_print_conversion(*++format, ap, &err);
			if (err < 0)
				return (va_end(ap), err);
			++format;
		}
		else
		count += write(1, format++, 1);
	}
	va_end(ap);
	return (count);
}
