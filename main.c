/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakpinar <rakpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:31:01 by rakpinar          #+#    #+#             */
/*   Updated: 2023/08/23 15:56:25 by rakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void ft_error(char *str)
{
	ft_printf("Error %s\n", str);
	exit(0);

}

int	close_frame(t_game *game)
{
	int		i;

	i = -1;
	  while (++i < win->map->hei) // Harita yüksekliği boyunca döngü
    {
        free(win->map->_map[i]); // Harita verisini temizle
        free(win->map->temp_map[i]); // Geçici harita verisini temizle
    }
	mlx_destroy_window(game->mlx, game->game);
	exit(0);
	return (0);
}

int	ft_key(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_frame(game);
	else if (keycode == 100 || keycode == 97 || keycode == 119 || keycode == 115)
		edit_map(keycode, game, game->map->_map);
	else if (keycode == 65361 || keycode == 65363)
		edit_map(keycode, game, game->map->_map);
	else if (keycode == 65364 || keycode == 65362)
		edit_map(keycode, game, game->map->_map);
	return (0);
}


void start_game(t_game *game)
{
		map_size(argv[1], game);
		game->game = mlx_new_window(game->mlx,
				64 * game->map->wid, 64 * game->map->hei, "Down the rabbit hole");
		read_map(game, argv[1]);
		map_control(game, game->map->_map);
		mlx_hook(game->game, 2, 1L << 0, ft_key, game);
		mlx_hook(game->game, 17, 0, close_frame, game);
		render_map(game, game->map->_map, 97);
		mlx_loop(game->mlx);

}

int main(int argc, **argv)
{
	t_game *game;

	if(argc == 2 && !ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 5))
		ft_error("Missing Argument or Wrong File Extension");
	
		game = ft_calloc(1, sizeof(t_game));
		game->map = ft_calloc(1, sizeof(t_map));
		game->chr = ft_calloc(1, sizeof(t_chr));
		game->mlx = mlx_init();
		start_game(&game)
	
	return(0);
}
