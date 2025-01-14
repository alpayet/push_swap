/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 03:45:22 by alpayet           #+#    #+#             */
/*   Updated: 2025/01/12 17:59:44 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putnbr_base_ul(unsigned long nbr, char *base);
int	ft_conversions_s(va_list args);
int	ft_conversions_d_or_i(va_list args);
int	ft_conversions_u(va_list args);
int	ft_conversions_x_or_upperx(char format_char, va_list args);
int	ft_conversions_p(va_list args);
#endif