
#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include "./Libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./get_next_line/get_next_line.h"

typedef struct s_map
{
	int			wid;
	int			hei;
	char		**_map;
	char		**temp_map;
	int			p_count;
	int			c_count;
	int			e_count;
}	t_map;

typedef struct s_chr
{
	void	*chr_r;
	void	*chr_l;
	void	*chr_up;
	void	*chr_down;
	int		move_count;
	int		size;
	int		x;
	int		y;
}	t_chr;

typedef struct s_game
{
	t_map	*map;
	t_chr	*chr;
	void	*mlx;
	void	*game;
	void	*bg;
	void	*wall;
	void	*exit;
	void	*coin;
}	t_game;

void	map_size(char *path, t_game *map);
void	ft_error(char	*msg);
void	new_map(t_game *game, char **map, int x, int y);
void	read_map(t_game *game, char *path);
void	read_temp_map(t_game *game, char *path);
void	map_control(t_game	*game, char	**map);
void	render_map(t_game *game, char	**map, int move);
int		ft_key(int keycode, t_game *game);
void	edit_map(int keycode, t_game *game, char **map);
void	find_player(t_game *game, char **map);
void	put_score(t_game *game);
void	file_to_image(t_game *game);
void	render_others(t_game *game, char **map, int move);
void	put(t_game *game, int move, int i, int j);

#endif
