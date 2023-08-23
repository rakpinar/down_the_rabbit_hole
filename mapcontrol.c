#include "so_long.h"

void	component_control(t_game *game, char **game)
{
	int		i;
	int		j;

	i = -1;
	while (++i < game->map->hei)
	{
		j = -1;
		while (map[i][++j])
		{
			if (!ft_strchr("01ECP", map[i][j]))
				ft_error("The map contains invalid letter(s).");
			else if (map[i][j] == 'P')
				game->map->p_count++;
			else if (map[i][j] == 'C')
				game->map->c_count++;
			else if (map[i][j] == 'E')
				game->map->e_count++;
		}
	}
	if (game->map->p_count != 1)
		ft_error("Invalid number of player(s)");
	if (game->map->e_count != 1)
		ft_error("Invalid exit door.");
	if (game->map->c_count < 1)
		ft_error("Invalid collectible.");
}

void	wall_control(t_game *game, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map->hei)
	{
		j = -1;
		while (map[i][++j])
		{
			if (i == 0 || i == game->map->hei - 1)
			{
				if (map[i][j] != '1')
				{
					ft_error("Invalid walls. Check the borders of the map.");
					break ;
				}
			}
		}
		if (map[i][0] != '1' || map[i][game->map->wid - 1] != '1')
		{
			ft_error("Invalid walls. Check the borders of the map.");
			break ;
		}
	}
}

void    valid_path(char **temp_map, int x, int y)
{
	if(temp_map[y][x] != 'E')
	{
		temp_map[y][x] = '.';
    	if (temp_map[y][x - 1] != '1' && temp_map[y][x - 1] != '.')
        	valid_path(temp_map, x - 1, y);
    	if (temp_map[y + 1][x] != '1' && temp_map[y + 1][x] != '.')
        	valid_path(temp_map, x, y + 1);
    	if (temp_map[y - 1][x] != '1' && temp_map[y - 1][x] != '.')
        	valid_path(temp_map, x, y - 1);
    	if (temp_map[y][x + 1] != '1' && temp_map[y][x + 1] != '.')
        	valid_path(temp_map, x + 1, y);
	}
	else
        	temp_map[y][x] = '1';
}

void    path_control(t_game *game, char **temp_map)
{
    int	i;
	int	j;
	find_player(game, temp_map);
	valid_path(game->map->temp_map, game->chr->x, game->chr->y);
	i = -1;
	while (++i < game->map->hei)
	{
		j = -1;
		while (temp_map[i][++j])
		{
			if (temp_map[i][j] == 'P' || temp_map[i][j] == 'C' || temp_map[i][j] == 'E')
				ft_error("Invalid path.");
		}
	}
}

void	map_control(t_game	*s_game, char	**map)
{
	//game->map->p_count = 0;
	component_control(s_game, map);
	wall_control(s_game, map);
	path_control(game, game->map->temp_map);
}
