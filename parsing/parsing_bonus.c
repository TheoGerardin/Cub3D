#include "../cub3d.h"

void	init_color_bonus(t_data *data)
{
	data->assets.f_color[0] = 253;
	data->assets.f_color[1] = 217;
	data->assets.f_color[2] = 235;
	data->assets.c_color[0] = 253;
	data->assets.c_color[1] = 217;
	data->assets.c_color[2] = 235;
}

void	init_texture_bonus(t_data *data)
{
	char	*texture_path;

	texture_path = strncpy("./textures/hello_kitty.xpm", 26);
	if (!texture_path)
		return ;
	get_texture(data, texture_path, &(data->assets.n_texture));
	get_texture(data, texture_path, &(data->assets.s_texture));
	get_texture(data, texture_path, &(data->assets.w_texture));
	get_texture(data, texture_path, &(data->assets.e_texture));
	free(texture_path);
}
