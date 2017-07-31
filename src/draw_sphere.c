/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 19:49:56 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/31 20:28:33 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	draw_sphere(t_spheres *o)
{
	t_color		pix;
	t_color		bpix;

	pix = get_color(o->color[2], o->color[1], o->color[0], o->color[3]);
	bpix = get_color(0, 0, 0, 0);
}
