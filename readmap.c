
#include "so_long.h"

int	ft_mapsize_control(t_game *game, char *line)
{
	return (((int)ft_strlen(line) - 1 != game->map->wid
			&& line[ft_strlen(line) - 1] == '\n')
		|| (line[ft_strlen(line) - 1] != '\n'
			&& (int)ft_strlen(line) != game->map->wid));
}

void	map_size(char *path, t_game *game)
{
	int		fd;
	char	*line;

	game->map->hei = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("Invalid ber");
	line = get_next_line(fd);
	if (line == 0)
		ft_error("Invalid map size");
	game->map->wid = (int)ft_strlen(line)-1;
	while (line)
	{
		if (ft_mapsize_control(game, line))
			ft_error("Invalid map size");
		game->map->hei++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	read_map(t_game *game, char *path)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("Invalid ber");
	line = get_next_line(fd);
	game->map->_map = ft_calloc(game->map->hei, sizeof(char *));
	while (line)
	{
		game->map->_map[i] = ft_calloc(game->map->wid, 1);
		ft_strlcpy(game->map->_map[i], line, game->map->wid + 1);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	read_temp_map(game, path);
}

void	read_temp_map(t_game *game, char *path)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("Invalid ber");
	line = get_next_line(fd);
	game->map->temp_map = ft_calloc(game->map->hei, sizeof(char *));
	while (line)
	{
		game->map->temp_map[i] = ft_calloc(game->map->wid, 1);
		ft_strlcpy(game->map->temp_map[i], line, game->map->wid + 1);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
