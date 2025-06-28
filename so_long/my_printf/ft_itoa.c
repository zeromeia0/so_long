/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:23:43 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/26 17:13:12 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static size_t	ft_putnbr_fake(int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	digits;
	size_t	i;
	char	*str;
	long	num;

	num = n;
	digits = ft_putnbr_fake(n);
	str = (char *)malloc(digits + 1);
	if (!str)
		return (NULL);
	str[digits] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	i = digits - 1;
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[i--] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
