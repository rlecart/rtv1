/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 20:04:28 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/08 14:34:15 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

// Ax + By + Cz + D = 0; 
// A = pos[0]
// B = pos[1]
// C = pos[2]
// DIR = vec
// D = distance
// t = -((pos[0] * X + pos[1] * Y + pos[2] * Z + distance) / (pos[0] * vec.x + pos[1] * vec.y + pos[2] * vec.z))

// où (X) = (O.x - pointplaneX).
// pointplane est un point du plan que l'on connait (pour construire le plan on lui passe un point sur le plan et la normale du plan).

// A * vec.x + B * vec.y + C * vec.z + distance = 0;
//

t_v3f	vec3_normalize(t_v3f a)
{
	t_v3f	result;
	float	length;

	length = sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
	result.x = a.x / length;
	result.y = a.y / length;
	result.z = a.z / length;
	return (result);
}

float	dot_product(t_v3f vec1, t_v3f vec2)
{
	int		i;
	float	result;

	i = 0;
	result = 0;
	result += vec1.x * vec2.x;
	result += vec1.y * vec2.y;
	result += vec1.z * vec2.z;
	return (result);
}

t_v3f	dot_min(t_v3f vec1, t_v3f vec2)
{
	t_v3f	result;

	result.x = vec1.x - vec2.x;
	result.y = vec1.y - vec2.y;
	result.z = vec1.z - vec2.z;
	return (result);
}

t_v3f	ftov(float pos[3])
{
	t_v3f	vec;

	vec.x = pos[0];
	vec.y = pos[1];
	vec.z = pos[2];
	return (vec);
}

t_v3f	dot_div(t_v3f vec1, t_v3f vec2)
{
	t_v3f	result;

	result.x = vec1.x / vec2.x;
	result.y = vec1.y / vec2.y;
	result.z = vec1.z / vec2.z;
	return (result);
}

// Ax + By + Cz + D = 0;
//
// t = dot(-(dot_min(CAM.pos, pos)), V) / dot(D, V);
// X = O - C

float	get_delta_plane(float pos[3], t_v3f vec, float distance, t_rt *e)
{
	float	d;
	float	result;
	t_v3f	n;
	t_v3f	dist;

	distance += 0;
	n.x = 0;
	n.y = 1;
	n.z = 0;
	d = dot_product(n, vec);
	//n = vec3_normalize(vec);
	//result = -((pos[0] * n.x + pos[1] * n.y + pos[2] * n.z + distance) / (pos[0] * vec.x + pos[1] * vec.y + pos[2] * vec.z));
	//result = -(n.x * pos[0] + n.y * pos[1] + n.z * pos[2] + distance);
	if (fabs(d) > 0.0001)
	{
		dist = dot_min(ftov(pos), ftov(CAM.pos));
		result = dot_product(dist, n) / d;
		return (result);
	}
	else
		return (-1);
}


//  (P-C)|V = 0

/*
float	get_delta_plane(float pos[3], t_v3f vec, float distance)
{
	float	t;
	t_v3f	result;
	t_v3f	normale;

	normale.x = 0;
	normale.y = 0.999;
	normale.z = 0.001;
	result = dot_min(vec, ftov(pos));
	result = dot_div(result, normale);
	t = 
	return (t);
}
*/
