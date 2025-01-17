#include "../cub3d.h"

int	two_arguments(t_data data, char **av)
{
	if (parser(&data, av, 0) == 1 || is_map_closed(&data) == 1)
		close_window(&data);
	data.mlx_win = mlx_new_window(data.mlx, data.win_width,
			data.win_height, "Cub3D Tgerardi & Romlamb");
	mlx_do_key_autorepeatoff(data.mlx);
	mlx_hook(data.mlx_win, 2, 1L << 0, manage_input_press, &data);
	mlx_hook(data.mlx_win, 3, 1L << 1, manage_input_release, &data);
	mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	mlx_hook(data.mlx_win, 6, 1L << 6, manage_mouse, &data);
	mlx_mouse_hide(data.mlx, data.mlx_win);
	mlx_loop_hook(data.mlx, render_cube, &data);
	mlx_loop(data.mlx);
	free_data(&data);
	return (0);
}

int	three_arguments(t_data data, char **av)
{
	if (parser(&data, av, 1) == 1 || is_map_closed(&data) == 1)
		close_window(&data);
	data.mlx_win = mlx_new_window(data.mlx, data.win_width,
			data.win_height, "Cub3D Tgerardi & Romlamb BONUS");
	mlx_do_key_autorepeatoff(data.mlx);
	mlx_hook(data.mlx_win, 2, 1L << 0, manage_input_press, &data);
	mlx_hook(data.mlx_win, 3, 1L << 1, manage_input_release, &data);
	mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	mlx_hook(data.mlx_win, 6, 1L << 6, manage_mouse, &data);
	mlx_mouse_hide(data.mlx, data.mlx_win);
	mlx_loop_hook(data.mlx, render_cube_bonus, &data);
	mlx_loop(data.mlx);
	free_data(&data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if ((ac == 3 && ft_strncmp(av[2], "-kawai", 6) == 0) || ac == 2)
	{
		if (available_name(av[1]) == 1)
			return ((void)printf("Error: Invalid file type\n"), 1);
		init_data(&data);
		if (ac == 2)
			two_arguments(data, av);
		else
			three_arguments(data, av);
	}
	return (printf("Error: Usage ./cub3d <filename>\n"), 1);
}
