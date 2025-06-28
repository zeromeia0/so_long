/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:09:56 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/11 17:37:13 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(const char *str)
{
	int	count;

	if (!str)
		return (write(1, NULL_STR, 6));
	count = ft_strlen(str);
	ft_putstr_fd(str);
	return (count);
}

unsigned int	ft_print_unsigned_int(int nb)
{
	unsigned int	unb;
	unsigned int	count;
	int				digit;

	count = 0;
	if (nb < 0)
		unb = MAX_UNSIGNED + nb + 1;
	else
		unb = nb;
	if (unb >= 10)
		count += ft_print_unsigned_int(unb / 10);
	digit = (unb % 10) + '0';
	count += write(1, &digit, 1);
	return (count);
}

int	ft_count(int i, va_list args, const char *key)
{
	int	count;

	count = 0;
	if (key[i] == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (key[i] == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (key[i] == 'd' || key[i] == 'i')
		count += ft_print_dec_int_number(va_arg(args, int));
	else if (key[i] == 'u')
		count += ft_print_unsigned_int(va_arg(args, int));
	else if (key[i] == 'x')
		count += ft_low_hexa(va_arg(args, unsigned int));
	else if (key[i] == 'X')
		count += ft_up_hexa(va_arg(args, unsigned int));
	else if (key[i] == 'p')
		count += ft_print_ptr(va_arg(args, void *));
	else if (key[i] == '%')
		count += write(1, "%", 1);
	else
	{
		count += write(1, "%", 1);
		count += write(1, &key[i], 1);
	}
	return (count);
}

int	ft_printf_setup(const char *key, va_list args)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (key[++i])
	{
		if (key[i] == '%')
		{
			count += ft_count(i + 1, args, key);
			i++;
		}
		else
			count += write(1, &key[i], 1);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	if (!format)
		return (-1);
	count = ft_printf_setup(format, args);
	if (count < 0)
		return (-1);
	va_end(args);
	return (count);
}
