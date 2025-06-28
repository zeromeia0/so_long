/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:51:18 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/24 18:41:41 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

# define MAX_UNSIGNED 4294967295
# define HEXA_LOWER_STR "0123456789abcdef"
# define HEXA_UPPER_STR "0123456789ABCDEF"
# define NULL_STR "(null)"
# define NIL_STR "(nil)"

typedef struct s_hexa
{
	int				i;
	int				a;
	int				len;
	int				rem;
	int				count;
	char			buffer1[20];
	char			buffer2[16];
	char			hexa_index[17];
	unsigned int	convert_hexa;
	unsigned int	num_to_unsigned;
	unsigned long	address;
}	t_hexa;

char			*ft_itoa(int n);
size_t			ft_strlen(const char *str);
void			ft_putchar_fd(int a, int fd);
void			ft_putstr_fd(const char *str);
size_t			ft_strlcpy(char *dst, const char *src, size_t dsize);
char			*ft_strdup(const char *s);
int				ft_print_dec_int_number(int nb);
int				ft_print_char(int c);
int				ft_low_hexa(unsigned int num);
int				ft_up_hexa(unsigned int num);
int				ft_print_ptr(void *ptr);
int				ft_print_str(const char *str);
unsigned int	ft_print_unsigned_int(int nb);
int				ft_printf(const char *format, ...);

#endif