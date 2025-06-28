/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 08:42:41 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/12 18:41:02 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_move(int keysym, t_gato *gato,
	t_gen *general, t_position *prev)
{
	prev->x = gato->x;
	prev->y = gato->y;
	if ((keysym == XK_w || keysym == XK_Up)
		&& !collision(general->g_data->collision,
			gato->x, gato->y - 1, general))
		gato->y -= 1;
	else if ((keysym == XK_a || keysym == XK_Left)
		&& !collision(general->g_data->collision,
			gato->x - 1, gato->y, general))
		gato->x -= 1;
	else if ((keysym == XK_s || keysym == XK_Down)
		&& !collision(general->g_data->collision,
			gato->x, gato->y + 1, general))
		gato->y += 1;
	else if ((keysym == XK_d || keysym == XK_Right)
		&& !collision(general->g_data->collision,
			gato->x + 1, gato->y, general))
		gato->x += 1;
}

void	redraw_map_tiles(t_gen *general, t_position prev, t_gato *gato)
{
	t_create_map	map_info;

	map_info.map_width = prev.x;
	map_info.map_height = prev.y;
	if (general->g_data->collision[prev.y][prev.x] == 'E')
		draw_map(general->g_data, &map_info, HOUSE);
	else
		draw_map(general->g_data, &map_info, CARPET);
	map_info.map_width = gato->x;
	map_info.map_height = gato->y;
	draw_map(general->g_data, &map_info, GATINHO);
}
