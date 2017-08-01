/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 19:51:42 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/01 02:26:33 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	draw_obj_one(t_rt *e)
{
	while (SPHERES)
	{
		draw_sphere(e);
		if (SPHERES->next)
			SPHERES = SPHERES->next;
		else
			break ;
	}
	while (CYLINDERS)
	{
		draw_cylinder(CYLINDERS);
		if (CYLINDERS->next)
			CYLINDERS = CYLINDERS->next;
		else
			break ;
	}
}

void	draw_obj_two(t_rt *e)
{
	while (CONES)
	{
		draw_cone(CONES);
		if (CONES->next)
			CONES = CONES->next;
		else
			break ;
	}
	while (PLANES)
	{
		draw_plane(PLANES);
		if (PLANES->next)
			PLANES = PLANES->next;
		else
			break ;
	}
}

void	reset_img(t_rt *e)
{
	int			x;
	int			y;
	t_color		pix;

	x = 0;
	y = 0;
	pix = get_color(0, 0, 0, 0);
	while (y < WIN_H)
	{
		while (x < WIN_W)
		{
			pixel_put(e->data, x, y, pix);
			x++;
		}
		x = 0;
		y++;
	}
}

void	draw_obj(t_rt *e)
{
	reset_img(e);
	draw_obj_one(e);
	draw_obj_two(e);
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
	mlx_put_image_to_window(MLX, WIN, e->img, 0, 0);
}
