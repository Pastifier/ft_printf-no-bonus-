#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h" // For libft access, and some types
# include <stdarg.h>      // For va_{list, arg, start, end}
# include <stdio.h>       // For testing against the original printf

/*------ft_printf------*/

int	ft_printf(const char *format, ...);

/*--------String--------*/

int	ft_print_str(char *str);

/*------Character------*/

int	ft_print_character(int c);

/*-------Address-------*/

int	ft_print_ptr(unsigned long long x);

/*------Integers------*/

int	ft_print_int(int nbr);
int	ft_print_uint(unsigned int nbr);

/*-----Hexadecimal-----*/

int	ft_print_hex(unsigned long x, bool is_lower);
#endif // !FT_PRINTF_H
