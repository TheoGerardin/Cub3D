#include "../cub3d.h"

int	skip_line(char *line)
{
	if (line[0] == '\n' && line[1] == '\0')
		return (free(line), 1);
	return (0);
}

char	**trim_color(char **split_color)
{
	char	*no32str;
	char	**perfect_color;
	int		index;
	int		goat;

	index = -1;
	goat = 0;
	while (split_color[++index])
		goat += strlen(split_color[index]);
	no32str = malloc(goat + 1);
	goat = 0;
	while (*split_color)
	{
		index = -1;
		while ((*split_color)[++index])
		{
			if ((*split_color)[index] != ' ' && (*split_color)[index] != '\n'
			&& (*split_color)[index] != '	')
				no32str[goat++] = (*split_color)[index];
		}
		split_color++;
	}
	no32str[goat] = 0;
	perfect_color = split(no32str, ",");
	return (free(no32str), perfect_color);
}

int	allocate_map(t_data *data, int map_width, int map_height)
{
	int	i;

	i = 0;
	data->map = malloc(sizeof(char *) * (map_height + 1));
	if (!data->map)
		return (printf("Error: memories\n"), 1);
	while (i < map_height)
	{
		data->map[i] = malloc(sizeof(char) * (map_width + 1));
		if (!data->map[i])
		{
			while (i > 0)
				free(data->map[i--]);
			free(data->map);
			return (printf("Error: memories columns\n"), 1);
		}
		memset(data->map[i], 0, map_width + 1);
		i++;
	}
	data->map[map_height] = NULL;
	return (0);
}

int	find_max_len(int fd)
{
	int		len;
	int		max_len;
	char	*line;

	max_len = 0;
	line = get_next_line(fd);
	while (line)
	{
		len = strlen(line);
		if (len > max_len)
			max_len = len;
		free(line);
		line = get_next_line(fd);
	}
	return (max_len);
}

int	find_max_height(char *filename)
{
	int		line_count;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	line_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (*line && (*line == '1' || *line == '0' || *line == '\t'
				|| *line == ' '))
			line_count++;
		free (line);
		line = get_next_line(fd);
	}
	return ((void)close(fd), line_count);
}
