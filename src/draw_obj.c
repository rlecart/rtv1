/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 19:51:42 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/10 01:45:41 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

float	get_delta_all(t_rt *e, t_v3f vec, int *type, int *itype)
{
	t_delta		d;

	d.tmp = 0;
	d.delta = -1;
	d.type = type;
	d.itype = itype;
	if (SPHERES)
		get_delta_all_spheres(e, vec, &d);
	if (CYLINDERS)
		get_delta_all_cylinders(e, vec, &d);
	if (CONES)
		get_delta_all_cones(e, vec, &d);
	if (PLANES)
		get_delta_all_planes(e, vec, &d);
	if (SPOTS)
		get_delta_all_spots(e, vec, &d);
	return (d.delta);
}

t_color		get_pix(t_rt *e, int type, int i)
{
	t_color		pix;

	pix = get_color(0, 0, 0, 0);
	if (type == 1)
		pix = get_color(SPHERES[i]->color[2], SPHERES[i]->color[1],
				SPHERES[i]->color[0], SPHERES[i]->color[3]);
	else if (type == 2)
		pix = get_color(CYLINDERS[i]->color[2], CYLINDERS[i]->color[1],
				CYLINDERS[i]->color[0], CYLINDERS[i]->color[3]);
	else if (type == 3)
		pix = get_color(CONES[i]->color[2], CONES[i]->color[1],
				CONES[i]->color[0], CONES[i]->color[3]);
	else if (type == 4)
		pix = get_color(PLANES[i]->color[2], PLANES[i]->color[1],
				PLANES[i]->color[0], PLANES[i]->color[3]);
	else if (type == 5)
		pix = get_color(SPOTS[i]->color[2], SPOTS[i]->color[1],
				SPOTS[i]->color[0], SPOTS[i]->color[3]);
	return (pix);
}

t_vec3	create_vector(float x, float y, float z)
{
	t_vec3	nvector;

	nvector.x = x;
	nvector.y = y;
	nvector.z = z;
	return (nvector);
}


t_ray	create_ray(t_vec3 origin, t_vec3 direction)
{
	t_ray	ray;
	
	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

void	draw_obj(t_rt *e)
{
	int			x;
	int			y;
	int			type;
	int			itype;
	float		delta;
	t_v3f		direction;
	t_color		pix[2];
	t_ray		ray;

	x = 0;
	y = 0;
	type = 0;
	itype = 0;
	pix[0] = get_color(0, 0, 0, 0);
	while (y < WIN_H)
	{
		while (x < WIN_W)
		{
			direction = get_vector(x, y, CAM.dir);
			/*jessai dajouter un ray avec 2 vecteurs, 
			un pour l'origin et un  pour la direction */
			ray = create_ray(create_vector(CAM.pos[0], CAM.pos[1], CAM.pos[2]),
				create_vector(direction.x, direction.y, direction.z));
			
			delta = get_delta_all(e, direction, &type, &itype);
			pix[1] = get_pix(e, type, itype);
			if (delta >= 0)
				pixel_put(e->data, x, y, pix[1]);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(MLX, WIN, e->img, 0, 0);
	reset_img(e->data, WIN_W, WIN_H);
}