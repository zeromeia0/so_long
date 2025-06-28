/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:36:08 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/12 18:42:40 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_map(t_create_map *map, t_mlx_data *data)
{
	while (map->new_map[map->map_height])
	{
		map->map_width = 0;
		while (map->new_map[map->map_height][map->map_width])
		{
			if (map->new_map[map->map_height][map->map_width] == '1')
				draw_map(data, map, TIJOLO);
			else if (map->new_map[map->map_height][map->map_width] == '0')
				draw_map(data, map, CARPET);
			else if (map->new_map[map->map_height][map->map_width] == 'E')
				draw_map(data, map, HOUSE);
			else if (map->new_map[map->map_height][map->map_width] == 'P')
			{
				so_long()->x = map->map_width;
				so_long()->y = map->map_height;
			}
			else if (map->new_map[map->map_height][map->map_width] == 'C')
				draw_map(data, map, RATO);
			map->map_width++;
		}
		map->map_height++;
	}
}

char	**ft_open_map(char *file)
{
	t_create_map	*map;
	char			**result;

	map = ft_calloc(1, sizeof(t_create_map));
	if (!map)
		return (NULL);
	map->lines = 0;
	map->map_fd = open(file, O_RDONLY);
	if (map->map_fd < 3)
		return (free(map), NULL);
	map->new_map = ft_calloc(1, sizeof(char *));
	if (!map->new_map)
		return (close(map->map_fd), free(map), NULL);
	map->get_gnl_null = get_next_line(map->map_fd);
	while (map->get_gnl_null)
	{
		map->new_map = realloc_map(map->new_map, map->lines, map->lines + 1);
		if (!map->new_map)
			return (free(map->get_gnl_null),
				close(map->map_fd), free(map), NULL);
		map->new_map[map->lines++] = map->get_gnl_null;
		map->get_gnl_null = get_next_line(map->map_fd);
	}
	result = map->new_map;
	return (close(map->map_fd), free(map), result);
}

unsigned int	*get_sprite_pixel(t_sprite_data *data, int x, int y)
{
	return ((unsigned int *)(data->address
		+ (y * data->line_len + x * (data->bpp / 8))));
}

void	draw_map(t_mlx_data *data, t_create_map *draw_map, char	*type)
{
	t_sprite_data	*texture;

	(void)draw_map;
	texture = ft_calloc(sizeof(t_sprite_data), 1);
	texture->address = mlx_xpm_file_to_image(data->mlx_ptr,
			type,
			&texture->width,
			&texture->height);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr,
		texture->address,
		draw_map->map_width * 80,
		draw_map->map_height * 80);
	mlx_destroy_image(data->mlx_ptr, texture->address);
	free(texture);
}
