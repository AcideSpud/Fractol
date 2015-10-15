#include "Fractol.h"

static int	iteration_max = 150;

void		julia(t_env *env)
{
	float		c_r;
	float		c_i;
	float		z_r;
	float		z_i;
	float		i;
	float		tmp;
	t_vertex	*v1;	
	t_vertex	*v2;
	float		img_x;
	float		img_y;
	float		zoom;

	v1 = (t_vertex*)malloc(sizeof(t_vertex));
	v2 = (t_vertex*)malloc(sizeof(t_vertex));
	zoom = 200;
	v1->x = -1;
	v1->y = -1.2;
	v2->x = 1;
	v2->y = 1.2;
	img_x = (v2->x - v1->x) * zoom;
	img_y = (v2->y - v1->x) * zoom;

	int xx = 0;
	int yy;
	while (xx < img_x)
	{
		yy = 0;
		while (yy < img_y)
		{
			c_r = 0.285;
			c_i = 0.01;
			z_r = xx/ zoom + v1->x;
			z_i = yy /zoom + v1->y;
			i = 0;
			while (((z_r * z_r) + (z_i * z_i)) < 4 && (i < iteration_max))
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			if (i == iteration_max)
			{
				choose_color(env->color, 0, 0 ,0);
				img_put_pixel(env, xx, yy, color_in_int(env->color));
			}
			else
			{
				choose_color(env->color, 0, 0,(i *255 / iteration_max));
				img_put_pixel(env, xx, yy,color_in_int(env->color));
			}
			yy++;
		}
		xx++;		
	}
}
