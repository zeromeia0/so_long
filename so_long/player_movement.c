/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:11:05 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/14 12:18:13 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_gato	*so_long(void)
{
	static t_gato	gato_instance;

	return (&gato_instance);
}

bool	collision(char **map, int x, int y, t_gen *general)
{
	if (map[y][x] == 'C')
	{
		general->g_parse->collected++;
		map[y][x] = '0';
	}
	if (map[y][x] == 'E')
	{
		if (general->g_parse->collected
			== general->g_parse->collect)
			super_duper_hiper_free();
		else
			ft_printf("Falta coletar as cenas\n");
	}
	return (map[y][x] == '1');
}

int	keypress_to_walk(int keysym, void *param)
{
	t_gen		*general;
	t_gato		*gato;
	t_position	prev;
	static int	i;

	general = (t_gen *)param;
	gato = so_long();
	handle_move(keysym, gato, general, &prev);
	redraw_map_tiles(general, prev, gato);
	if (prev.x != gato->x || prev.y != gato->y)
		ft_printf("Steps: %d\n", i++);
	handle_exit(keysym);
	return (0);
}

int	loop(void *param)
{
	t_mlx_data		*data;
	t_sprite_data	*sprite;

	sprite = ft_calloc(sizeof(t_sprite_data), 1);
	data = param;
	sprite->sprite_address = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/gatinho.xpm", &sprite->width, &sprite->height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		sprite->sprite_address, so_long()->x * 80, so_long()->y * 80);
	mlx_destroy_image(data->mlx_ptr, sprite->sprite_address);
	free(sprite);
	return (1);
}
