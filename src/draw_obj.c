/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 19:51:42 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/31 20:12:45 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	draw_obj_one(t_rt *e)
{
	while (SPHERES)
	{
		draw_sphere(SPHERES);
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

void	draw_obj(t_rt *e)
{
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
}
