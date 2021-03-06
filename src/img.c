#include "fractol.h"

void		fill_img(t_env *env, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->lim->img_x)
	{
		j = 0;
		while (j < env->lim->img_y)
		{
			img_put_pixel(env, i, j, color);
			j++;
		}
		i++;
	}
}

void		img_put_pixel(t_env *env, int x, int y, int color)
{
	char			*data;
	unsigned int	value;

	data = env->idata;
	value = mlx_get_color_value(env->mlx, color);
	if (x > 0 && x < env->lim->img_x && y < env->lim->img_y)
		ft_memcpy(data + y * env->isizeline + x * (env->ibits / 8), &value, 3);
}
