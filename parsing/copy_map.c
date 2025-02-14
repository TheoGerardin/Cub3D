#include "../cub3d.h"

int	copy_color(t_data *data, char **split_color, char *color, int bonus)
{
	if (bonus == 1)
		return (init_color_bonus(data), 0);
	if (color[0] == 'F' && color[1] == '\0')
	{
		data->assets.f_color[0] = atoi(split_color[0]);
		data->assets.f_color[1] = atoi(split_color[1]);
		data->assets.f_color[2] = atoi(split_color[2]);
		if (is_color_is_correct(data->assets.f_color[0],
				data->assets.f_color[1], data->assets.f_color[2]) == 1)
			return (1);
	}
	else if (color[0] == 'C' && color[1] == '\0')
	{
		data->assets.c_color[0] = atoi(split_color[0]);
		data->assets.c_color[1] = atoi(split_color[1]);
		data->assets.c_color[2] = atoi(split_color[2]);
		if (is_color_is_correct(data->assets.f_color[0],
				data->assets.f_color[1], data->assets.f_color[2]) == 1)
			return (printf("Error: Floor color error\n"), 1);
	}
	else
		return (1);
	return (0);
}

int	copy_map(t_data *data, char *filename)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		if (*line == '0' || *line == '1' || *line == ' ')
		{
			free(data->map[i]);
			data->map[i] = strncpy(line, data->map_width);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (search_player_pos(data) != 0)
		return (printf("Error: player position not found\n"), 1);
	return (0);
}

int	copy_assets(t_data *data, char **split_line, int bonus)
{
	char	*texture_path;

	if (bonus == 1)
		return (init_texture_bonus(data), 0);
	else
	{
		if (!split_line || !split_line[0] || !split_line[1])
			return (printf("Error: Invalid split_line content\n"), 1);
		texture_path = strncpy(split_line[1],
				ft_strchr_i(split_line[1], '\n'));
		if (!texture_path)
			return (printf("Error: Failed to extract texture path\n"), 1);
		if (ft_strcmp(split_line[0], "NO") == 0)
			get_texture(data, texture_path, &(data->assets.n_texture));
		else if (ft_strcmp(split_line[0], "SO") == 0)
			get_texture(data, texture_path, &(data->assets.s_texture));
		else if (ft_strcmp(split_line[0], "WE") == 0)
			get_texture(data, texture_path, &(data->assets.w_texture));
		else if (ft_strcmp(split_line[0], "EA") == 0)
			get_texture(data, texture_path, &(data->assets.e_texture));
		else
			return (free(texture_path),
				(void) printf("Error: Incorret texture path\n"), 1);
		return (free(texture_path), 0);
	}
}
