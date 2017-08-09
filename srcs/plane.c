/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 20:08:17 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/08/09 14:13:30 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

float		intensity_plane(t_env *e, t_vector poi,
				t_object plane, t_light light)
{
	t_vector	dist_to_light;
	float		intensity;

	dist_to_light = vec_ope_min(light.origin, poi);
	intensity = 0.5 * ft_map(get_length(dist_to_light), 2000 * light.intensity, 500, 200);
	if (obj_in_shadow(e, poi, light))
		intensity -= AMBIENT_LIGHT;
	return (intensity > AMBIENT_LIGHT) ? intensity : AMBIENT_LIGHT;
}

/*
** Implementation of 
** http://stackoverflow.com/questions/23975555/how-to-do-ray-plane-intersection
*/

float		intersect_plane(t_ray ray, t_object plane)
{
	float		d;
	float		dist;
	t_vector	vector_distance;

	d = dot(plane.normal, ray.direction);
	if (fabs(d) > 0.0001)
	{
		vector_distance = vec_ope_min(plane.origin, ray.origin);
		dist = dot(vector_distance, plane.normal) / d;
		return (dist);
	}
	return (DIST_MAX);
}
