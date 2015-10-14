#include "fractol.h"

void	cantor(t_env *env, float x, float y, float len)
{
	t_vertex	*v1;
	t_vertex	*v2;
	int			color;

	if (len >= 1)
	{
		color = 0x896A45;
		v1 = (t_vertex*)malloc(sizeof(t_vertex));
		v2 = (t_vertex*)malloc(sizeof(t_vertex));
		v1->x = x;
		v1->y = y;
		v2->x = x + len;
		v2->y = y;
		img_put_line(env, v1, v2, color);
		y += 20;
		cantor(env, x, y, len / 3);
		cantor(env, x + (len * 2 / 3), y, len / 3);
	}
}
