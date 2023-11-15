#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h" // For libft access, and some types
# include <stdarg.h>      // For va_{list, arg, start, end}
# include <stdio.h>       // For testing against the original printf

/*------ft_printf------*/

int	ft_printf(const char *format, ...);

/*--------String--------*/

int	ft_print_str(char *str, int *errno);

/*------Character------*/

int	ft_print_character(int c, int *errno);

/*-------Address-------*/

int	ft_print_ptr(unsigned long long x, int *errno);

/*------Integers------*/

int	ft_print_int(int nbr, int *errno);
int	ft_print_uint(unsigned int nbr, int *errno);

/*-----Hexadecimal-----*/

int	ft_print_hex(unsigned int x, bool is_lower, int *errno);
#endif // !FT_PRINTF_H
