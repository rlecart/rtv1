/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 20:04:28 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/07 16:17:18 by rlecart          ###   ########.fr       */
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

float	get_delta_plane(float pos[3], t_v3f vec, float distance)
{
	float	calc;
	float	result;

	calc = 0;
	result = 0;
	distance += 0;
	vec.x += 0;
	pos[0] += 0;
	if (result > 0)
	{
		if (1)
			return (1);
		else if (2)
			return (2);
	}
	else if (result == 0)
		if (1)
			return (1);
	return (-1);
}
