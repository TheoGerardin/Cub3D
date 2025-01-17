#include "../cub3d.h"

int	flood_fill(char **map, int x, int y, t_data *data)
{
	if (x < 0 || y < 0 || y >= data->map_height || x >= (int)strlen(map[y]))
		return (0);
	if (map[y][x] == '1')
		return (1);
	if (map[y][x] == 'F')
		return (1);
	map[y][x] = 'F';
	return (
		flood_fill(map, x + 1, y, data)
		&& flood_fill(map, x - 1, y, data)
		&& flood_fill(map, x, y + 1, data)
		&& flood_fill(map, x, y - 1, data)
	);
}

int	is_wall_or_space(char c)
{
	return (c == '1' || c == ' ' || c == '\0');
}

int	allocate_map_flood(t_data *data, char **map_copy)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		map_copy[y] = malloc(strlen(data->map[y]) + 1);
		if (!map_copy[y])
			return (free_tab(map_copy), 1);
		strlcpy(map_copy[y], data->map[y], strlen(data->map[y]) + 1);
		x = 0;
		while (map_copy[y][x])
		{
			if (map_copy[y][x] == ' ')
				map_copy[y][x] = '0';
			x++;
		}
		y++;
	}
	map_copy[y] = NULL;
	return (0);
}

int	is_map_closed(t_data *data)
{
	char	**map_copy;
	size_t	x;
	int		y;

	map_copy = malloc(sizeof(char *) * (data->map_height + 1));
	if (!map_copy)
		return (1);
	if (allocate_map_flood(data, map_copy))
		return (free_tab(map_copy), 1);
	y = -1;
	while (++y < data->map_height)
	{
		x = -1;
		while (++x < strlen(data->map[y]))
		{
			if (map_copy[y][x] == '0')
			{
				if (!flood_fill(map_copy, data->player.x_ply,
						data->player.y_ply, data))
					return (free_tab(map_copy),
						(void)printf("Error: Map is not closed\n"), 1);
			}
		}
	}
	return (free_tab(map_copy), (void)printf("Map is closed\n"), 0);
}

int	available_name(char *name)
{
	int	start_pos;
	int	size_cub;
	int	size_string;

	size_cub = 4;
	size_string = strlen(name);
	start_pos = size_string - size_cub;
	if (start_pos <= 0 || strcmp(name + start_pos, ".cub"))
		return (1);
	return (0);
}
