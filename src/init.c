/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 10:54:19 by jrosamon          #+#    #+#             */
/*   Updated: 2015/10/14 11:41:05 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
