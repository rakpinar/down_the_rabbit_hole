
#include "so_long.h"

void	put_score(t_game *game)
{
	char	*score;

	score = ft_itoa(game->chr->move_count);
	mlx_string_put(game->mlx, game->game, 62, 62, 0x00FF00, score);
	free(score);
}

void	new_map(t_game *game, char **map, int x, int y)
{
	if (map[y][x] == 'C')
			game->map->c_count--;
	if (map[y][x] == 'E' && game->map->c_count == 0)
	{
		game->chr->move_count++;
		ft_printf("%d\n", game->chr->move_count);
		ft_key(65307, game);
	}
	map[game->chr->y][game->chr->x] = '0';
	map[y][x] = 'P';
	game->chr->x = x;
	game->chr->y = y;
	game->chr->move_count++;
	ft_printf("%d\n", game->chr->move_count);
}

void	edit_map(int keycode, t_game *s_game, char **map)
{
	int	x;
	int	y;

	find_player(game, map);
	x = game->chr->x;
	y = game->chr->y;
	if (keycode == 100 || keycode == 65363)
		x++;
	else if (keycode == 119 || keycode == 65362)
		y--;
	else if (keycode == 115 || keycode == 65364)
		y++;
	else if (keycode == 97 || keycode == 65361)
		x--;
	if (map[y][x] != '1' && (map[y][x] != 'E' || game->map->c_count == 0))
	{
		new_map(game, map, x, y);
		render_map(game, map, keycode);
	}		
}
