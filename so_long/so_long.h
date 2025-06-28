/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:24:46 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/14 12:31:43 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "./gnl/get_next_line.h"
# include "mlx.h"
# include <stdbool.h>
# include "./my_printf/ft_printf.h"
// Defines for sprites
# define HOUSE "./textures/house.xpm"
# define CARPET "./textures/carpet.xpm"
# define GATINHO "./textures/gatinho.xpm"
# define TIJOLO "./textures/tijolinho.xpm"
# define RATO "./textures/rato.xpm"
// Defines for error messages
# define COPY_ERROR "Error\nFalha ao copiar o mapa.\n"
# define B0 "Error\nOcorreu um problema ao criar o mapa.\n"
# define MEM_ISSUE "Error\nFalha de alocação de memória.\n"
# define ERROR_OPEN_MAP "Error\nNão foi possível abrir o arquivo do mapa.\n"
# define BER "Error\nO mapa deve ter a extensão .ber.\n"
# define WIN_ERROR "Error\nNão foi possível criar a janela gráfica.\n"
# define MAP_EXIST "Error\nO mapa tem que existir\n"
# define RECTANGLE "Error\nMapa não é retangular\n"
# define SIDES_CLOSED "Error\nMapa não está cercado por '1' nas laterais\n"
# define UPPER_WALL "Error\nParede de cima não está fechada com '1'\n"
# define LOWER_WALL "Error\nParede de baixo não está fechada com '1'\n"
# define BAD_MAP "Error\nEsse mapa tá mal cria\n"
# define INVALID "Error\nMapa inválido\n"
// Big defines
# define POR_MAPA "Error\nMapa ausente ou inválido. \
Verifique o arquivo informado.\n"
# define EXIT_COLECT_ERROR "Error\nNão foi possível coletar todos os \
itens ou a saída está inacessível.\n"
# define INUTIL "Error\nO programa encontrou vários \
problemas de configuração.\n"

typedef struct s_parsing
{
	int		exit;
	int		collect;
	int		collected;
	int		start;
	int		x;
	int		y;
	int		fill_y;
	int		fill_x;
	char	*valid_map_file;
	int		width;
}	t_parse;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**collision;
}	t_mlx_data;

typedef struct s_create_map
{
	char	**new_map;
	char	**result;
	int		map_fd;
	int		lines;
	char	*get_gnl_null;
	int		map_height;
	int		map_width;
}	t_create_map;

typedef struct s_sprite_data
{
	void	*address;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	void	*final_map;
	char	*sprite_address;
	void	*parede;
}	t_sprite_data;

typedef struct s_gato
{
	int	prev_x;
	int	prev_y;
	int	x;
	int	y;
	int	gen_prev_x;
	int	gen_prev_y;
}	t_gato;

typedef struct s_general
{
	t_parse			*g_parse;
	t_create_map	*g_mk_map;
	t_mlx_data		*g_data;
	t_gato			*gen_gato;
}	t_gen;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_flood_fill
{
	int	row;
	int	col;
	int	height;
	int	width;
}	t_fill;

void		draw_map(t_mlx_data *data, t_create_map *draw_map, char	*type);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *s, size_t n);
void		make_map(t_create_map *newMap, t_mlx_data *data);
void		free_map(char **map);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		handle_move(int keysym, t_gato *gato,
				t_gen	*general, t_position *prev);
char		**realloc_map(char **old_map, int old_size, int new_size);
char		**ft_open_map(char *file);
char		**copy_map(char **map);
char		*ft_strtrim(char const *s1, char const *set);
int			get_map_width(char **map);
int			get_map_height(char **map);
int			keypress_to_walk(int keysym, void *param);
int			loop(void *param);
int			ft_printf(const char *format, ...);
int			valid_params(char **map, t_parse *parse);
int			flood_fill(char **tab, t_fill pos, int y, int x);
int			handle_exit(int keysym);
int			super_duper_hiper_free(void);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			valid_path(char **map);
void		redraw_map_tiles(t_gen *general, t_position prev, t_gato *gato);
bool		collision(char **map, int x, int y, t_gen *general);
t_gato		*so_long(void);
t_gen		*so_long_tudo(void);

#endif