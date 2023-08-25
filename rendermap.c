/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendermap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakpinar <rakpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:54:24 by rakpinar          #+#    #+#             */
/*   Updated: 2023/08/25 14:54:38 by rakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put(t_win *win, int move, int i, int j)
{
	char	**map;

	map = win->map->_map;
	if (map[i][j] == 'C')
		mlx_put_image_to_window(win->mlx,
			win->win, win->coin, j * 64, i * 64);
	else if (map[i][j] == '1')
		mlx_put_image_to_window(win->mlx,
			win->win, win->wall, j * 64, i * 64);
	else if (map[i][j] == 'P' && (move == 2 || move == 124))
		mlx_put_image_to_window(win->mlx,
			win->win, win->chr->chr_r, j * 64, i * 64);
	else if (map[i][j] == 'P' && (move == 13 || move == 126))
		mlx_put_image_to_window(win->mlx,
			win->win, win->chr->chr_up, j * 64, i * 64);
	else if (map[i][j] == 'P' && (move == 0 || move == 123))
		mlx_put_image_to_window(win->mlx,
			win->win, win->chr->chr_l, j * 64, i * 64);
	else if (map[i][j] == 'P' && (move == 1 || move == 125))
		mlx_put_image_to_window(win->mlx,
			win->win, win->chr->chr_down, j * 64, i * 64);
	else if (map[i][j] == 'E')
		mlx_put_image_to_window(win->mlx,
			win->win, win->exit, j * 64, i * 64);
}

void	render_others(t_win *win, char **map, int move)
{
	int	i;
	int	j;

	i = -1;
	while (++i < win->map->hei)
	{
		j = -1;
		while (map[i][++j])
			put(win, move, i, j);
	}
}

void	file_to_image(t_win *win)
{
	win->chr->size = 64;
	win->bg = mlx_xpm_file_to_image(win->mlx,
			"./textures/tile.xpm",
			&win->chr->size, &win->chr->size);
	win->chr->chr_down = mlx_xpm_file_to_image(win->mlx,
			"./textures/character_face.xpm", &win->chr->size, &win->chr->size);
	win->chr->chr_up = mlx_xpm_file_to_image(win->mlx,
			"./textures/character_back.xpm", &win->chr->size, &win->chr->size);
	win->chr->chr_l = mlx_xpm_file_to_image(win->mlx,
			"./textures/character_left.xpm", &win->chr->size, &win->chr->size);
	win->chr->chr_r = mlx_xpm_file_to_image(win->mlx,
			"./textures/character_right.xpm",
			&win->chr->size, &win->chr->size);
	win->exit = mlx_xpm_file_to_image(win->mlx,
			"./textures/hole1.xpm", &win->chr->size, &win->chr->size);
	win->wall = mlx_xpm_file_to_image(win->mlx,
			"./textures/tree1.xpm", &win->chr->size, &win->chr->size);
	win->coin = mlx_xpm_file_to_image(win->mlx,
			"./textures/carrot.xpm", &win->chr->size, &win->chr->size);
}

void	render_map(t_win *win, char	**map, int move)
{
	int	i;
	int	j;

	file_to_image(win);
	i = -1;
	while (++i < win->map->hei)
	{
		j = -1;
		while (map[i][++j])
			mlx_put_image_to_window(win->mlx,
				win->win, win->bg, j * 64, i * 64);
	}
	render_others(win, map, move);
	put_score(win);
}

void	find_player(t_win *win, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < win->map->hei)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				win->chr->x = j;
				win->chr->y = i;
			}
		}
	}
}
