/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakpinar <rakpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:51:42 by rakpinar          #+#    #+#             */
/*   Updated: 2023/08/22 14:51:42 by rakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H


#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"

typedef struct s_map()
{
	int lines;
	int	columns;
}t_map;



typedef struct game
{
	void *mlx;
	void *wint;
	void *wall;
	void *exit;
	void *coin;


}t_game;





#endif 


