/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 08:44:43 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/11 08:46:19 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_height(char **map)
{
	t_create_map	*map_data;
	int				height;

	map_data = ft_calloc(1, sizeof(t_create_map));
	if (!map_data)
		return (0);
	while (map[map_data->map_height])
		map_data->map_height++;
	height = map_data->map_height;
	free(map_data);
	return (height);
}

int	get_map_width(char **map)
{
	t_create_map	*map_data;
	int				width;

	map_data = ft_calloc(1, sizeof(t_create_map));
	if (!map_data)
		return (0);
	while (map[0][map_data->map_width])
		map_data->map_width++;
	map_data->map_width--;
	width = map_data->map_width;
	free(map_data);
	return (width);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
	return (0);
}

char	**realloc_map(char **old_map, int old_size, int new_size)
{
	char	**new_map;
	int		i;

	new_map = ft_calloc(sizeof(char *), (new_size + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < old_size)
	{
		new_map[i] = old_map[i];
		i++;
	}
	new_map[i] = NULL;
	free(old_map);
	return (new_map);
}
