/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 11:21:00 by jrosamon          #+#    #+#             */
/*   Updated: 2015/10/14 11:39:08 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		draw(t_env *env)
{
	(void)env;
	return (0);
}

int		key(int key, t_env *env)
{
	(void)env;
	if (key == 53)
		error("User exit");
	return (0);
}
