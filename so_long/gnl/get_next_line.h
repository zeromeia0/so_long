/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:25:24 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/26 15:38:19 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int b);
char	*full_line(char *full_line, char *file_str);
char	*ft_strjoin(char *s1, char *s2);

#endif