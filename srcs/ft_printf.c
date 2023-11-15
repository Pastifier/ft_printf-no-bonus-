#include "../ft_printf.h"

static int	ft_print_conversion(char specifier, va_list ap)
{
	if (specifier == '%')
	  return (ft_print_character('%'));
	if (specifier == 'c')
		return (ft_print_character(va_arg(ap, int)));
	if (specifier == 's')
		return (ft_print_str(va_arg(ap, char *)));
	if (specifier == 'd' || specifier == 'i')
		return (ft_print_int(va_arg(ap, int)));
	if (specifier == 'u')
		return (ft_print_uint(va_arg(ap, unsigned int)));
	if (specifier == 'x')
		return (ft_print_hex(va_arg(ap, unsigned long), 1));
	if (specifier == 'X')
		return (ft_print_hex(va_arg(ap, unsigned long), 0));
	if (specifier == 'p')
		return (ft_print_ptr(va_arg(ap, unsigned long long)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			count += ft_print_conversion(*++format, ap);
			++format;
		}
		else
			count += write(1, format++, 1);
	}
	va_end(ap);
	return (count);
}
