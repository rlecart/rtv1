/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:04:18 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/09 14:13:30 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

float		intensity_sphere(t_env *e, t_vector poi,
				t_object sphere, t_light light)
{
	float		dist_to_light;
	t_vector	vec_to_eyes;
	t_vector	vec_to_light;
	float		intensity;

	vec_to_eyes = normalize(vec_ope_min(poi, sphere.origin));
	vec_to_light = vec_ope_min(light.origin, poi);
	dist_to_light = get_length(vec_to_light);
	intensity = (dot(vec_to_eyes, normalize(vec_to_light)) *
		ft_map(dist_to_light, 2000 * light.intensity, 500, 200));
	if (obj_in_shadow(e, poi, light))
		intensity -= AMBIENT_LIGHT;
	return (intensity > AMBIENT_LIGHT) ? intensity : AMBIENT_LIGHT;
}

/*
** Implementation of :
** http://hugi.scene.org/online/hugi24/index%20coding%20&%20maths.htm
*/

float		intersect_sphere(t_ray ray, t_object sphere)
{
	float		a;
	float		b;
	float		c;
	t_vector	x;

	x = vec_ope_min(ray.origin, sphere.origin);
	a = dot(ray.direction, ray.direction);
	b = 2 * dot(ray.direction, x);
	c = dot(x, x) - (sphere.radius * sphere.radius);
	return (get_res_of_quadratic(a, b, c));
}
