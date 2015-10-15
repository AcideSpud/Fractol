/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 17:39:27 by jrosamon          #+#    #+#             */
/*   Updated: 2015/10/15 11:00:20 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_put_hline(t_env *env, t_vertex *v1, t_vertex *v2, int color)
{
	int i;

	i = v1->x;
	while (i < v2->x)
	{
		img_put_pixel(env, i, v1->y + ((v2->y - v1->y) *
					(i - v1->x)) / (v2->x - v1->x), color);
		i++;
	}
}

void	img_put_vline(t_env *env, t_vertex *v1, t_vertex *v2, int color)
{
	int i;

	i = v1->y;
	while (i < v2->y)
	{
		img_put_pixel(env, v1->x + ((v2->x - v1->x) *
					(i - v1->y)) / (v2->y - v1->y), i, color);
		i++;
	}
}

void	img_put_line(t_env *env, t_vertex *v1, t_vertex *v2, int color)
{
	if (fabs(v1->x - v2->x) > fabs(v1->y - v2->y))
	{
		if (v1->x < v2->x)
			img_put_hline(env, v1, v2, color);
		else
			img_put_hline(env, v2, v1, color);
	}
	else
	{
		if (v1->y < v2->y)
			img_put_vline(env, v1, v2, color);
		else
			img_put_vline(env, v2, v1, color);
	}
}
