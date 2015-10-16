#include "fractol.h"

static	void		draw_ellipse(t_env *env, float cx, float cy, float r)
{
	float	angle;
	float	step;
	int		x;
	int		y;
	int		color;

	modif_color(env->color);
	color = color_in_int(env->color);
	angle = 0;
	x = 0;
	y = 0;
	step = 0.1;
	while (angle <= 360)
	{
		x = cx + r * cos(angle);
		y = (cy - 0.5) + r * sin(angle);
		img_put_pixel(env, x, y, color);
		angle += step;
	}
}

void				circle_fractal(t_env *env, float cx, float cy, float r)
{
	draw_ellipse(env, cx, cy, r);
	if (r > 8)
	{
		circle_fractal(env, cx + (r / 2), cy, r / 2);
		circle_fractal(env, cx - (r / 2), cy, r / 2);
		circle_fractal(env, cx, cy + (r / 2), r / 2);
		circle_fractal(env, cx, cy - (r / 2), r / 2);
	}
}
