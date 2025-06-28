/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:08:34 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/11 17:36:36 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	unsigned char	a;

	a = (unsigned char)c;
	return (write(1, &a, 1));
}

int	ft_print_dec_int_number(int nb)
{
	char	*str;
	int		len;

	str = ft_itoa(nb);
	if (!str)
		return (0);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}

int	ft_low_hexa(unsigned int num)
{
	t_hexa	*v;
	int		count;

	v = malloc(sizeof(t_hexa));
	if (!v)
		return (-1);
	v->i = 0;
	v->count = 0;
	ft_strlcpy(v->hexa_index, HEXA_LOWER_STR, 17);
	v->convert_hexa = num;
	if (v->convert_hexa == 0)
		v->buffer2[v->i++] = v->hexa_index[v->convert_hexa % 16];
	while (v->convert_hexa > 0)
	{
		v->buffer2[v->i++] = v->hexa_index[v->convert_hexa % 16];
		v->convert_hexa /= 16;
	}
	v->i--;
	while (v->i >= 0)
		v->count += write(1, &v->buffer2[v->i--], 1);
	count = v->count;
	free(v);
	return (count);
}

int	ft_up_hexa(unsigned int num)
{
	t_hexa	*v;
	int		count;

	v = malloc(sizeof(t_hexa));
	if (!v)
		return (-1);
	v->i = 0;
	v->count = 0;
	ft_strlcpy(v->hexa_index, HEXA_UPPER_STR, 17);
	v->convert_hexa = num;
	if (v->convert_hexa == 0)
		v->buffer2[v->i++] = v->hexa_index[v->convert_hexa % 16];
	while (v->convert_hexa > 0)
	{
		v->buffer2[v->i++] = v->hexa_index[v->convert_hexa % 16];
		v->convert_hexa /= 16;
	}
	v->i--;
	while (v->i >= 0)
		v->count += write(1, &v->buffer2[v->i--], 1);
	count = v->count;
	free(v);
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	t_hexa	*var;
	int		count;

	if (!ptr)
		return (write(1, NIL_STR, 5));
	var = malloc(sizeof(t_hexa));
	if (!var)
		return (-1);
	var->i = 0;
	var->count = 0;
	ft_strlcpy(var->hexa_index, HEXA_LOWER_STR, 17);
	var->address = (unsigned long)ptr;
	while (var->address > 0)
	{
		var->buffer2[var->i++] = var->hexa_index[var->address % 16];
		var->address /= 16;
	}
	var->count += write(1, "0x", 2);
	while (--var->i >= 0)
		var->count += write(1, &var->buffer2[var->i], 1);
	count = var->count;
	free (var);
	return (count);
}
