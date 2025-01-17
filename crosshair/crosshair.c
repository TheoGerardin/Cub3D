#include "../cub3d.h"

void	draw_crosshair(t_image *img, int center_x, int center_y)
{
	int	size;
	int	thickness;
	int	i;
	int	j;

	size = 10;
	thickness = 2;
	i = -size;
	while (i <= size)
	{
		j = -thickness / 2;
		while (j <= thickness / 2)
			draw_pixel(img, center_x + i, center_y + j++, 0xFFFFFF);
		i++;
	}
	i = -size;
	while (i <= size)
	{
		j = -thickness / 2;
		while (j <= thickness / 2)
			draw_pixel(img, center_x + j++, center_y + i, 0xFFFFFF);
		i++;
	}
}
