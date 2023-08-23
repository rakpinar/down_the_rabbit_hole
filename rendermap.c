
#include "so_long.h"

void	put(t_game *game, int move, int i, int j)
{
	char	**map;

	map = game->map->_map;
	if (map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx,
			game->game, game->coin, j * 64, i * 64);
	else if (map[i][j] == '1')
		mlx_put_image_to_window(game->mlx,
			game->game, game->wall, j * 64, i * 64);
	else if (map[i][j] == 'P' && (move == 100 || move == 65363))
		mlx_put_image_to_window(game->mlx,
			game->game, game->chr->chr_r, j * 64, i * 64);
	else if (map[i][j] == 'P' && (move == 119 || move == 65362))
		mlx_put_image_to_window(game->mlx,
			game->game, game->chr->chr_up, j * 64, i * 64);
	else if (map[i][j] == 'P' && (move == 97 || move == 65361))
		mlx_put_image_to_window(game->mlx,
			game->game, game->chr->chr_l, j * 64, i * 64);
	else if (map[i][j] == 'P' && (move == 115 || move == 65364))
		mlx_put_image_to_window(game->mlx,
			game->game, game->chr->chr_down, j * 64, i * 64);
	else if (map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx,
			game->game, game->exit, j * 64, i * 64);
}

void	render_others(t_game *game, char **map, int move)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map->hei)
	{
		j = -1;
		while (map[i][++j])
			put(game, move, i, j);
	}
}

void	file_to_image(t_game *game)
{
	game->chr->size = 64;
	game->bg = mlx_xpm_file_to_image(game->mlx,
			"./xpm/bg_2.xpm", &game->chr->size, &game->chr->size);
	game->chr->chr_down = mlx_xpm_file_to_image(game->mlx,
			"./xpm/chr_down.xpm", &game->chr->size, &game->chr->size);
	game->chr->chr_up = mlx_xpm_file_to_image(game->mlx,
			"./xpm/chr_up.xpm", &game->chr->size, &game->chr->size);
	game->chr->chr_l = mlx_xpm_file_to_image(game->mlx,
			"./xpm/chr_l.xpm", &game->chr->size, &game->chr->size);
	game->chr->chr_r = mlx_xpm_file_to_image(game->mlx,
			"./xpm/chr_r.xpm", &game->chr->size, &game->chr->size);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"./xpm/exit.xpm", &game->chr->size, &game->chr->size);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"./xpm/asteroid.xpm", &game->chr->size, &game->chr->size);
	game->coin = mlx_xpm_file_to_image(game->mlx,
			"./xpm/collect.xpm", &game->chr->size, &game->chr->size);
}

void	render_map(t_game *game, char	**map, int move)
{
	int	i;
	int	j;

	file_to_image(game);
	i = -1;
	while (++i < game->map->hei)
	{
		j = -1;
		while (map[i][++j])
			mlx_put_image_to_window(game->mlx,
				game->game, game->bg, j * 64, i * 64);
	}
	render_others(game, map, move);
	put_score(game);
}

void	find_player(t_game *game, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map->hei)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				game->chr->x = j;
				game->chr->y = i;
			}
		}
	}
}
