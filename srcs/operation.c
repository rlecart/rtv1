/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 15:20:18 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/09 14:13:30 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector	vec_ope_min(t_vector v1, t_vector v2)
{
	return (c_vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

t_vector	vec_ope_add(t_vector v1, t_vector v2)
{
	return (c_vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

t_vector	vec_ope_mult(t_vector v1, float d)
{
	return (c_vector(v1.x * d, v1.y * d, v1.z * d));
}

t_vector	vec_ope_div(t_vector v1, float d)
{
	return (c_vector(v1.x / d, v1.y / d, v1.z / d));
}

float		get_res_of_quadratic(float a, float b, float c)
{
	float		determinant;
	float		t0;
	float		t1;

	determinant = b * b - 4 * a * c;
	if (determinant < 0)
		return (DIST_MAX);
	if (determinant == 0)
		return (-b / (2 * a));
	t0 = (-b + sqrt(determinant)) / (2 * a);
	t1 = (-b - sqrt(determinant)) / (2 * a);
	return (t0 > t1) ? t1 : t0;
}