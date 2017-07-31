/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 20:36:32 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/31 20:07:46 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	print_debug(t_rt *e)
{
	printf("camera:\n");
	printf("\tpos: %f, %f, %f\n", CAM.pos[0], CAM.pos[1], CAM.pos[2]);
	printf("\tdir: %f, %f, %f\n", CAM.dir[0], CAM.dir[1], CAM.dir[2]);
	if (SPHERES)
	{
		printf("\n");
		printf("spheres:\n");
		while (SPHERES)
		{
			printf("\tnew:\n");
			printf("\t\tpos: %f, %f, %f\n", SPHERES->pos[0], SPHERES->pos[1], SPHERES->pos[2]);
			printf("\t\tradius: %f\n", SPHERES->radius);
			printf("\t\tcolor: %f, %f, %f, %f\n", SPHERES->color[0], SPHERES->color[1], SPHERES->color[2], SPHERES->color[3]);
			if (!SPHERES->next)
				break ;
			SPHERES = SPHERES->next;
		}
	}
	if (CYLINDERS)
	{
		printf("\n");
		printf("cylinders:\n");
		while (!CYLINDERS)
		{
			printf("\tnew:\n");
			printf("\t\tpos: %f, %f, %f\n", CYLINDERS->pos[0], CYLINDERS->pos[1], CYLINDERS->pos[2]);
			printf("\t\tradius: %f\n", CYLINDERS->radius);
			printf("\t\tcolor: %f, %f, %f, %f\n", CYLINDERS->color[0], CYLINDERS->color[1], CYLINDERS->color[2], CYLINDERS->color[3]);
			if (!CYLINDERS->next)
				break ;
			CYLINDERS = CYLINDERS->next;
		}
	}
	if (CONES)
	{
		printf("\n");
		printf("cones:\n");
		while (CONES)
		{
			printf("\tnew:\n");
			printf("\t\tpos: %f, %f, %f\n", CONES->pos[0], CONES->pos[1], CONES->pos[2]);
			printf("\t\tradius: %f\n", CONES->radius);
			printf("\t\tcolor: %f, %f, %f, %f\n", CONES->color[0], CONES->color[1], CONES->color[2], CONES->color[3]);
			if (!CONES->next)
				break ;
			CONES = CONES->next;
		}
	}
	if (PLANES)
	{
		printf("\n");
		printf("planes:\n");
		while (PLANES)
		{
			printf("\tnew:\n");
			printf("\t\tpos: %f, %f, %f\n", PLANES->pos[0], PLANES->pos[1], PLANES->pos[2]);
			printf("\t\tdist: %f\n", PLANES->dist);
			printf("\t\tcolor: %f, %f, %f, %f\n", PLANES->color[0], PLANES->color[1], PLANES->color[2], PLANES->color[3]);
			if (!PLANES->next)
				break ;
			PLANES = PLANES->next;
		}
	}
	if (SPOTS)
	{
		printf("\n");
		printf("spots:\n");
		while (SPOTS)
		{
			printf("\tnew:\n");
			printf("\t\tpos: %f, %f, %f\n", SPOTS->pos[0], SPOTS->pos[1], SPOTS->pos[2]);
			printf("\t\tcolor: %f, %f, %f, %f\n", SPOTS->color[0], SPOTS->color[1], SPOTS->color[2], SPOTS->color[3]);
			if (!SPOTS->next)
				break ;
			SPOTS = SPOTS->next;
		}
	}
	while (SPHERES && SPHERES->before)
		SPHERES = SPHERES->before;
	while (CYLINDERS &&CYLINDERS->before)
		CYLINDERS = CYLINDERS->before;
	while (CONES && CONES->before)
		CONES = CONES->before;
	while (PLANES && PLANES->before)
		PLANES = PLANES->before;
	while (SPOTS && SPOTS->before)
		SPOTS = SPOTS->before;
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
