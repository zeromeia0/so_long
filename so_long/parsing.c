/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:52:54 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/12 18:54:48 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_shape(char **map, t_parse *parse)
{
	int	current_len;

	if (!map || !map[0])
		return (ft_printf(MAP_EXIST), 0);
	parse->width = ft_strlen(map[0]);
	if (map[0][parse->width - 1] == '\n')
		parse->width--;
	parse->y = 0;
	while (map[parse->y])
	{
		current_len = ft_strlen(map[parse->y]);
		if (map[parse->y][current_len - 1] == '\n')
			current_len--;
		if (current_len != parse->width)
			return (ft_printf(RECTANGLE), 0);
		parse->y++;
	}
	return (1);
}

int	check_edges(char **map, t_parse *parse)
{
	int	i;
	int	len;
	int	map_line;

	map_line = 0;
	while (map[map_line])
	{
		len = ft_strlen(map[map_line]);
		if (map[map_line][len - 1] == '\n')
			len--;
		if (map[map_line][0] != '1' || map[map_line][len - 1] != '1')
			return (ft_printf(SIDES_CLOSED),
				0);
		map_line++;
	}
	i = 0;
	while (i < parse->width)
	{
		if (map[0][i] != '1')
			return (ft_printf(UPPER_WALL), 0);
		if (map[map_line - 1][i] != '1')
			return (ft_printf(LOWER_WALL), 0);
		i++;
	}
	return (1);
}

int	check_map(char **map, t_parse *parse)
{
	char	c;

	parse->exit = 0;
	parse->start = 0;
	parse->collect = 0;
	parse->y = 0;
	while (map[parse->y])
	{
		parse->x = 0;
		while (map[parse->y][parse->x] && map[parse->y][parse->x] != '\n')
		{
			c = map[parse->y][parse->x];
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
				return (ft_printf("Caractere inválido: %c\n", c), 0);
			if (c == 'E')
				parse->exit++;
			if (c == 'P')
				parse->start++;
			if (c == 'C')
				parse->collect++;
			parse->x++;
		}
		parse->y++;
	}
	return (1);
}

int	valid_params(char **map, t_parse *parse)
{
	check_map(map, parse);
	if (!check_shape(map, parse) || !check_edges(map, parse)
		|| parse->exit != 1 || parse->start != 1 || parse->collect < 1)
		return (ft_printf(BAD_MAP), 0);
	return (1);
}
