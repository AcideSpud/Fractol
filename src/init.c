#include "fractol.h"

int			ft_init(t_env *env)
{
	env->mlx = mlx_init();
	if (!env->mlx)
		return (0);
	env->height = 800;
	env->width = 600;
	env->win = mlx_new_window(env->mlx, env->width, env->height, "fractol");
	env->img = mlx_new_image(env->mlx, env->width, env->height);
	env->idata = mlx_get_data_addr(env->img, &(env->ibits), &(env->isizeline),
			&(env->iendian));
	return (1);
}
