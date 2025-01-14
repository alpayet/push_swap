/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:11:58 by alpayet           #+#    #+#             */
/*   Updated: 2024/12/18 21:44:32 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversions_s(va_list args)
{
	char	*str;

	str = va_arg(args, void *);
	if (str == NULL)
		return (ft_putstr_fd("(null)", 1));
	return (ft_putstr_fd(str, 1));
}

int	ft_conversions_d_or_i(va_list args)
{
	long	nbr;

	nbr = va_arg(args, int);
	if (nbr < 0)
	{
		if (ft_putchar_fd('-', 1) == -1)
			return (-1);
		return (ft_putnbr_base_ul(-nbr, "0123456789") + 1);
	}
	return (ft_putnbr_base_ul(nbr, "0123456789"));
}

int	ft_conversions_u(va_list args)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	return (ft_putnbr_base_ul(nbr, "0123456789"));
}

int	ft_conversions_x_or_upperx(char format_char, va_list args)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	if (format_char == 'x')
		return (ft_putnbr_base_ul(nbr, "0123456789abcdef"));
	return (ft_putnbr_base_ul(nbr, "0123456789ABCDEF"));
}

int	ft_conversions_p(va_list args)
{
	void	*addr;

	addr = va_arg(args, void *);
	if (addr == NULL)
		return (ft_putstr_fd("(nil)", 1));
	if (ft_putstr_fd("0x", 1) == -1)
		return (-1);
	return (ft_putnbr_base_ul((unsigned long)addr, "0123456789abcdef") + 2);
}
