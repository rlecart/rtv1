/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 19:51:42 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/08 16:15:17 by rlecart          ###   ########.fr       */
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

void	draw_obj(t_rt *e)
{
	int			x;
	int			y;
	int			type;
	int			itype;
	float		delta;
	t_v3f		vec;
	t_color		pix[2];

	x = 0;
	y = 0;
	type = 0;
	itype = 0;
	pix[0] = get_color(0, 0, 0, 0);
	while (y < WIN_H)
	{
		while (x < WIN_W)
		{
			vec = get_vector(x, y, CAM.dir);
			delta = get_delta_all(e, vec, &type, &itype);
			if (delta >= 0)
			{
				pix[1] = get_pix(e, type, itype);
				pixel_put(e->data, x, y, pix[1]);
			}
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(MLX, WIN, e->img, 0, 0);
	reset_img(e->data, WIN_W, WIN_H);
}
