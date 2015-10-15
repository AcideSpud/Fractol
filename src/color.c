#include "fractol.h"

int			color_in_int(t_color *color)
{
	return ((color->r << 16) + (color->g << 8) + (color->b));
}

void		modif_color(t_color *color)
{
	color->r = rand() % 255;
	color->g = rand() % 255;
	color->b = rand() % 255;
}

void		choose_color(t_color *color, int r, int g, int b)
{
	color->r = r;
	color->g = g;
	color->b = b;
}
