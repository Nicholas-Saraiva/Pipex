/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 04:07:16 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/08/15 12:43:19 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_print_strlen(const char *s);
int	condition_for_c(va_list args);
int	condition_for_s(va_list args);
int	condition_for_p(va_list arg);
int	condition_for_decimal(va_list arg);
int	condition_for_udecimal(va_list arg);
int	condition_for_hex(va_list arg, char fmt);
int	ft_printf(const char *fstring, ...);

#endif
