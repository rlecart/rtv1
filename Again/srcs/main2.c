/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 00:09:53 by mhalit            #+#    #+#             */
/*   Updated: 2017/08/10 07:48:37 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		display_args(void)
{
	ft_putstr("\nusage: rtv1 [-s source] [-w width] [-h height]\n");
	ft_putstr("-w : Set the specified source file\n");
	ft_putstr("-w : Width of the window, default 500px\n");
	ft_putstr("-h : Height of the window, default 500px\n");
	ft_putstr("--help : Show help\n");
	exit(42);
}

void	init_rt(t_rt *env)
{
	env->mlx.init = mlx_init();
	env->file.haut = 0;
	env->file.larg = 0;
	env->scene.nbr_obj = 0;
	env->scene.nbr_light = 0;
	env->scene.nbr_tot = 0;
	env->scene.obj = (t_obj *)malloc(sizeof(t_obj) * MAXOBJ);
	env->scene.lights = (t_light *)malloc(sizeof(t_light) * MAXLIGHT);
	env->scene.supersampling = 0;
}

int		main(int argc, char **argv)
{
	t_rt *env;

	env = NULL;
	env = (t_rt *)malloc(sizeof(t_rt));
	if (argc > 2)
	{
		init_rt(env);
		if (!parse_args(argv, argc, env))
			return (0);
		env->mlx.window = mlx_new_window(env->mlx.init, env->file.larg, env->file.haut, "RT Again");
		
		frame(env);
		// if (env->scene.supersampling)
		// 	super_sampler(env);
		// else
		// 	anti_supersampler(env);
		mlx_key_hook(env->mlx.window, key_hook, env);
		mlx_loop(INIT);
	}
	else
		display_args();
	return (0);
}
