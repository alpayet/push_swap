/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:05:06 by alpayet           #+#    #+#             */
/*   Updated: 2025/01/12 21:05:18 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_ul(unsigned long nbr, char *base)
{
	int	nbr_printed;
	int	quotient_printed;

	nbr_printed = 0;
	quotient_printed = 0;
	if (nbr >= ft_strlen(base))
	{
		quotient_printed = ft_putnbr_base_ul(nbr / ft_strlen(base), base);
		if (quotient_printed == -1)
			return (-1);
		nbr_printed = quotient_printed + 1;
	}
	else
		return (ft_putchar_fd(base[nbr % ft_strlen(base)], 1));
	if (ft_putchar_fd(base[nbr % ft_strlen(base)], 1) == -1)
		return (-1);
	return (nbr_printed);
}

static int	ft_check_percent(char format_char, va_list args)
{
	if (format_char == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (format_char == '%')
		return (ft_putchar_fd('%', 1));
	if (format_char == 's')
		return (ft_conversions_s(args));
	if (format_char == 'p')
		return (ft_conversions_p(args));
	if (format_char == 'd' || format_char == 'i')
		return (ft_conversions_d_or_i(args));
	if (format_char == 'u')
		return (ft_conversions_u(args));
	if (format_char == 'x' || format_char == 'X')
		return (ft_conversions_x_or_upperx(format_char, args));
	return (-1);
}

static int	ft_iterate_over_format(const char *format, va_list args)
{
	int	i;
	int	chars_printed;
	int	check_var_printed;

	i = 0;
	chars_printed = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			check_var_printed = ft_check_percent(format[i + 1], args);
			if (check_var_printed == -1)
				return (-1);
			chars_printed = chars_printed + check_var_printed;
			i++;
		}
		else
		{
			if (ft_putchar_fd(format[i], 1) == -1)
				return (-1);
			chars_printed++;
		}
		i++;
	}
	return (chars_printed);
}

int	ft_printf(const char *format, ...)
{
	int		chars_printed;
	va_list	args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	chars_printed = ft_iterate_over_format(format, args);
	va_end(args);
	return (chars_printed);
}

/* int    main(void)
{
    int        i;
    char    *s;
    void    *ptr;

    i = -1;
    s = "prout";
    ptr = NULL;

  	printf("%d", ft_printf(0));
     	printf("int : %d\n\n", ft_printf("my oui p%a oui\n%"));
      printf("int : %d\n\n", printf("42 oui p%a oui\n%"));
    	printf("int : %d\n\n", ft_printf("my oui s%%%s oui\n", s));
     	printf("int : %d\n\n", printf("42 oui s%%%s oui\n", s));
     	printf("int : %d\n\n", ft_printf("my oui u :%%%u oui\n", i));
	printf("int : %d\n\n", printf("42 oui u :%%%u oui\n", i));
    	printf("int : %d\n\n", ft_printf("my oui d%%%d oui\n", i));
    	printf("int : %d\n\n", printf("42 oui d%%%d oui\n", i));
     	printf("int : %d\n\n", ft_printf("my oui d%%%d oui\n", i));
     	printf("int : %d\n\n", printf("42 oui i%%%i oui\n", i));
     	printf("int : %d\n\n", ft_printf("my oui x%%%x oui\n", i));
     	printf("int : %d\n\n", printf("42 oui x%%%x oui\n", i));
     	printf("int : %d\n\n", ft_printf("my oui X%%%X oui\n", i));
     	printf("int : %d\n\n", printf("42 oui X%%%X oui\n", i));
     	printf("int : %d\n\n", ft_printf("my oui %x oui\n", 35));
	printf("int : %d\n\n", printf("42 oui %x oui\n", 35));
     	printf("int : %d\n\n", ft_printf("my oui a : % \n", 35));
     	printf("int : %d\n\n", printf("42 oui a : % \n", 35));
} */