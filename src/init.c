/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 20:38:26 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/07 15:21:13 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	get_conf(t_rt *e, char **scene)
{
	SPHERES = NULL;
	CYLINDERS = NULL;
	CONES = NULL;
	PLANES = NULL;
	SPOTS = NULL;
	get_camera(e, scene);
	get_spheres(e, scene);
	get_cylinders(e, scene);
	get_cones(e, scene);
	get_planes(e, scene);
	get_spots(e, scene);
	print_debug(e);
}

void	init(t_rt *e, char *file)
{
	int		i;
	char	**scene;

	if (!(scene = ft_get_file(file)))
		exit(-1);
	get_conf(e, scene);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIN_W, WIN_H, "Khey Trassing");
	e->img = mlx_new_image(MLX, WIN_W, WIN_H);
	e->data = mlx_get_data_addr(e->img, &i, &i, &i);
	mlx_key_hook(WIN, key_hook, e);
	ft_strtabdel(&scene);
}
