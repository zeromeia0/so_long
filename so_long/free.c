/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:22:18 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/12 18:41:02 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	super_duper_hiper_free(void)
{
	t_gen	*gen;

	gen = so_long_tudo();
	if (!gen)
		exit(EXIT_FAILURE);
	if (gen->g_mk_map->new_map)
		free_map(gen->g_mk_map->new_map);
	if (gen->g_data)
	{
		if (gen->g_data->win_ptr && gen->g_data->mlx_ptr)
			mlx_destroy_window(gen->g_data->mlx_ptr,
				gen->g_data->win_ptr);
		if (gen->g_data->mlx_ptr)
		{
			mlx_destroy_display(gen->g_data->mlx_ptr);
			free(gen->g_data->mlx_ptr);
		}
	}
	free(gen->g_parse);
	free(gen->g_mk_map);
	free(gen->g_data);
	exit (EXIT_SUCCESS);
}

int	handle_exit(int keysym)
{
	if (keysym == XK_Escape)
		super_duper_hiper_free();
	return (0);
}
