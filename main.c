/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakpinar <rakpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:11:22 by rakpinar          #+#    #+#             */
/*   Updated: 2023/08/22 16:11:22 by rakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_error(char *str)
{
	ft_printf("Error %s\n", str);
	exit(1);

}


void start_game(t_game *game)
{
	validate_map(game->argv[1], game);




}

int main(int argc, **argv)
{
	t_game game;

	if(argc == 2 && !ft_strncmp(&[ft_strlen(argv[1]) - 4], ".ber", 5))
	{
		game = ft_calloc(1, sizeof(t_game));
		game->map = ft_calloc(1, sizeof(t_map));
		game->chr = ft_calloc(1, sizeof(t_chr));
		game-> mlx_init;
		start_game(&game)

	}	

	else
		ft_error("Missing Argument or Wrong File Extension");

}