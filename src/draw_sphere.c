/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 19:49:56 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/07 16:17:20 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

float	get_delta_sphere(float pos[3], t_v3f vec, float radius)
{
	float	a;
	float	b;
	float	c;
	float	result;

	a = pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2);
	b = 2 * (pos[0] * vec.x + pos[1] * vec.y + pos[2] * vec.z);
	c = (pow(pos[0], 2) + pow(pos[1], 2) + pow(pos[2], 2)) - radius;
	result = pow(b, 2) - (4 * a * c);
	if (result > 0)
	{
		if ((-b + sqrtf(result)) / 2 * a < (-b - sqrtf(result)) / 2 * a
				&& (-b + sqrtf(result)) / 2 * a > 0
				&& (-b - sqrtf(result)) / 2 * a > 0)
			return ((-b + sqrtf(result)) / 2 * a);
		else if ((-b - sqrtf(result)) / 2 * a > 0)
			return ((-b - sqrtf(result)) / 2 * a);
	}
	else if (result == 0)
		if (a != 0.0f && b != 0)
			return (-b / 2 * a);
	return (-1);
}
