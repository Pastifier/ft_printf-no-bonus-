#include "../ft_printf.h"

static int	ft_print_conversion(const char *format, va_list ap)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += ft_print_character(va_arg(ap, int));
	else if (*format == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (*format == 'd' || *format == 'i')
		count += ft_print_int(va_arg(ap, long long));
	return (count);
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
			count += ft_print_conversion(++format, ap);
			++format;
		}
		else
			count += write(1, format++, 1);
	}
	va_end(ap);
	return (count);
}
