/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 20:36:32 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/07 17:01:34 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	print_debug(t_rt *e)
{
	int		i;

	i = 0;
	printf("camera:\n");
	printf("\tpos: %f, %f, %f\n", CAM.pos[0], CAM.pos[1], CAM.pos[2]);
	printf("\tdir: %f, %f, %f\n", CAM.dir[0], CAM.dir[1], CAM.dir[2]);
	if (SPHERES)
	{
		printf("\n");
		printf("spheres:\n");
		while (SPHERES[i])
		{
			printf("\tnew:\n");
			printf("\t\tpos: %f, %f, %f\n", SPHERES[i]->pos[0], SPHERES[i]->pos[1], SPHERES[i]->pos[2]);
			printf("\t\tradius: %f\n", SPHERES[i]->radius);
			printf("\t\tcolor: %f, %f, %f, %f\n", SPHERES[i]->color[0], SPHERES[i]->color[1], SPHERES[i]->color[2], SPHERES[i]->color[3]);
			i++;
		}
	}
	i = 0;
	if (CYLINDERS)
	{
		printf("\n");
		printf("cylinders:\n");
		while (CYLINDERS[i])
		{
			printf("\tnew:\n");
			printf("\t\tpos: %f, %f, %f\n", CYLINDERS[i]->pos[0], CYLINDERS[i]->pos[1], CYLINDERS[i]->pos[2]);
			printf("\t\tradius: %f\n", CYLINDERS[i]->radius);
			printf("\t\tcolor: %f, %f, %f, %f\n", CYLINDERS[i]->color[0], CYLINDERS[i]->color[1], CYLINDERS[i]->color[2], CYLINDERS[i]->color[3]);
			i++;
		}
	}
	i = 0;
	if (CONES)
	{
		printf("\n");
		printf("cones:\n");
		while (CONES[i])
		{
			printf("\tnew:\n");
			printf("\t\tpos: %f, %f, %f\n", CONES[i]->pos[0], CONES[i]->pos[1], CONES[i]->pos[2]);
			printf("\t\tradius: %f\n", CONES[i]->radius);
			printf("\t\tcolor: %f, %f, %f, %f\n", CONES[i]->color[0], CONES[i]->color[1], CONES[i]->color[2], CONES[i]->color[3]);
			i++;
		}
	}
	i = 0;
	if (PLANES)
	{
		printf("\n");
		printf("planes:\n");
		while (PLANES[i])
		{
			printf("\tnew:\n");
			printf("\t\tpos: %f, %f, %f\n", PLANES[i]->pos[0], PLANES[i]->pos[1], PLANES[i]->pos[2]);
			printf("\t\tdist: %f\n", PLANES[i]->dist);
			printf("\t\tcolor: %f, %f, %f, %f\n", PLANES[i]->color[0], PLANES[i]->color[1], PLANES[i]->color[2], PLANES[i]->color[3]);
			i++;
		}
	}
	i = 0;
	if (SPOTS)
	{
		printf("\n");
		printf("spots:\n");
		while (SPOTS[i])
		{
			printf("\tnew:\n");
			printf("\t\tpos: %f, %f, %f\n", SPOTS[i]->pos[0], SPOTS[i]->pos[1], SPOTS[i]->pos[2]);
			printf("\t\tcolor: %f, %f, %f, %f\n", SPOTS[i]->color[0], SPOTS[i]->color[1], SPOTS[i]->color[2], SPOTS[i]->color[3]);
			i++;
		}
	}
	printf("\n");
}

int		main(int argc, char **argv)
{
	t_rt	e;

	if (argc == 2)
	{
		init(&e, argv[1]);
		draw_obj(&e);
		mlx_loop(e.mlx);
	}
	else
		ft_putendl("usage ./rtv1 scene");
	return (0);
}
