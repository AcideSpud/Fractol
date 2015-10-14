/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 10:34:48 by jrosamon          #+#    #+#             */
/*   Updated: 2015/10/14 11:40:39 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;

	t_env	env;
	if(!ft_init(&env))
		return (0);
	mlx_loop(env.mlx);

	return (0);
}


