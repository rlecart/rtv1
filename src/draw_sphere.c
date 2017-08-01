/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 19:49:56 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/01 04:08:21 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_v3f	get_vector(int x, int y)
{
	t_v3f	dis;

	dis.x = 500;
	dis.y = (WIN_W / 2) - x;
	dis.z = (WIN_H / 2) - y;
	return (dis);
}

float	get_delta_sphere(float pos[3], t_v3f dis, float radius)
{
	float	a;
	float	b;
	float	c;
	float	result;

	a = pow(dis.x, 2) + pow(dis.y, 2) + pow(dis.z, 2);
	b = 2 * (pos[0] * dis.x + pos[1] * dis.y + pos[2] * dis.z);
	c = (pow(pos[0], 2) + pow(pos[1], 2) + pow(pos[2], 2)) - radius;
	result = pow(b, 2) - (4 * a * c);
	if (result > 0)
	{
		if ((-b + sqrt(result)) / 2 * a < (-b - sqrt(result)) / 2 * a
				&& (-b + sqrt(result)) / 2 * a > 0
				&& (-b - sqrt(result)) / 2 * a > 0)
			return ((-b + sqrt(result)) / 2 * a);
		else if ((-b - sqrt(result)) / 2 * a > 0)
			return ((-b - sqrt(result)) / 2 * a);
	}
	else if (result == 0)
		if (a != 0.0f && b != 0)
			return (-b / 2 * a);
	return (-1);
}

void	draw_sphere(t_rt *e)
{
	int			x;
	int			y;
	float		delta;
	t_v3f		dis;
	t_color		pix[2];

	x = 0;
	y = 0;
	pix[0] = get_color(SPHERES->color[2], SPHERES->color[1], SPHERES->color[0], SPHERES->color[3]);
	pix[1] = get_color(0, 0, 0, 0);
	while (y < WIN_H)
	{
		while (x < WIN_W)
		{
			dis = get_vector(x, y);
			delta = get_delta_sphere(SPHERES->pos, dis, SPHERES->radius);
			if (delta >= 0)
				pixel_put(e->data, x, y, pix[0]);
			x++;
		}
		x = 0;
		y++;
	}
}
