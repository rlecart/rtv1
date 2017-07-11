/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 20:38:26 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/11 07:22:19 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

char	**split_wc(char *str, char c)
{
	int		i;
	char	**result;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			str[i] = ' ';
		i++;
	}
	if (!(result = ft_strsplit(str, c)))
		return (NULL);
	return (result);
}

void	get_conf(t_rt *e, char **scene)
{
	get_camera(e, scene);
	printf("camera:\n");
	printf("\tpos: %f, %f, %f\n", e->cam.pos[0], e->cam.pos[1], e->cam.pos[2]);
	printf("\tdir: %f, %f, %f\n", e->cam.dir[0], e->cam.dir[1], e->cam.dir[2]);
	get_spheres(e, scene);
	printf("\n");
	printf("spheres:\n");
	printf("\tnew:\n");
	printf("\t\tpos: %f, %f, %f\n", e->obj.spheres->pos[0], e->obj.spheres->pos[1], e->obj.spheres->pos[2]);
	printf("\t\tradius: %f\n", e->obj.spheres->radius);
	printf("\t\tcolor: %f, %f, %f, %f\n", e->obj.spheres->color[0], e->obj.spheres->color[1], e->obj.spheres->color[2], e->obj.spheres->color[3]);
	printf("\tnew:\n");
	printf("\t\tpos: %f, %f, %f\n", e->obj.spheres->next->pos[0], e->obj.spheres->next->pos[1], e->obj.spheres->next->pos[2]);
	printf("\t\tradius: %f\n", e->obj.spheres->next->radius);
	printf("\t\tcolor: %f, %f, %f, %f\n", e->obj.spheres->next->color[0], e->obj.spheres->next->color[1], e->obj.spheres->next->color[2], e->obj.spheres->next->color[3]);
	get_cylinders(e, scene);
	printf("\n");
	printf("cylinders:\n");
	printf("\tnew:\n");
	printf("\t\tpos: %f, %f, %f\n", e->obj.cylinders->pos[0], e->obj.cylinders->pos[1], e->obj.cylinders->pos[2]);
	printf("\t\tradius: %f\n", e->obj.cylinders->radius);
	printf("\t\tcolor: %f, %f, %f, %f\n", e->obj.cylinders->color[0], e->obj.cylinders->color[1], e->obj.cylinders->color[2], e->obj.cylinders->color[3]);
	get_cones(e, scene);
	printf("\n");
	printf("cones:\n");
	printf("\tnew:\n");
	printf("\t\tpos: %f, %f, %f\n", e->obj.cones->pos[0], e->obj.cones->pos[1], e->obj.cones->pos[2]);
	printf("\t\tradius: %f\n", e->obj.cones->radius);
	printf("\t\tcolor: %f, %f, %f, %f\n", e->obj.cones->color[0], e->obj.cones->color[1], e->obj.cones->color[2], e->obj.cones->color[3]);
	get_planes(e, scene);
	printf("\n");
	printf("planes:\n");
	printf("\tnew:\n");
	printf("\t\tpos: %f, %f, %f\n", e->obj.planes->pos[0], e->obj.planes->pos[1], e->obj.planes->pos[2]);
	printf("\t\tdist: %f\n", e->obj.planes->dist);
	printf("\t\tcolor: %f, %f, %f, %f\n", e->obj.planes->color[0], e->obj.planes->color[1], e->obj.planes->color[2], e->obj.planes->color[3]);
	get_spots(e, scene);
	printf("\n");
	printf("spots:\n");
	printf("\tnew:\n");
	printf("\t\tpos: %f, %f, %f\n", e->obj.spots->pos[0], e->obj.spots->pos[1], e->obj.spots->pos[2]);
	printf("\t\tcolor: %f, %f, %f, %f\n", e->obj.spots->color[0], e->obj.spots->color[1], e->obj.spots->color[2], e->obj.spots->color[3]);
}

int		init_env(t_rt *e)
{
	if (!(e->obj.spheres = (t_spheres*)malloc(sizeof(t_spheres))))
		return (-1);
	if (!(e->obj.cylinders = (t_cylinders*)malloc(sizeof(t_cylinders))))
		return (-1);
	if (!(e->obj.cones = (t_cones*)malloc(sizeof(t_cones))))
		return (-1);
	if (!(e->obj.planes = (t_planes*)malloc(sizeof(t_planes))))
		return (-1);
	if (!(e->obj.spots = (t_spots*)malloc(sizeof(t_spots))))
		return (-1);
	e->obj.spheres->before = NULL;
	e->obj.spheres->next = NULL;
	e->obj.cylinders->before = NULL;
	e->obj.cylinders->next = NULL;
	e->obj.cones->before = NULL;
	e->obj.cones->next = NULL;
	e->obj.planes->before = NULL;
	e->obj.planes->next = NULL;
	e->obj.spots->before = NULL;
	e->obj.spots->next = NULL;
	return (0);
}

int		init(t_rt *e, char *file)
{
	char	**scene;

	if (!(scene = ft_get_file(file)))
		return (-1);
	if ((init_env(e)) == -1)
		return (-1);
	get_conf(e, scene);
	return (0);
}
