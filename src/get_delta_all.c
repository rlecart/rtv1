/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_delta_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 16:03:59 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/08 14:30:58 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	get_delta_all_spheres(t_rt *e, t_v3f vec, t_delta *d)
{
	int		i;

	i = 0;
	while (SPHERES[i])
	{
		ft_memset(d->dis, 0, sizeof(d->dis));
		add_3f(&d->dis, &SPHERES[i]->pos, &CAM.pos);
		d->tmp = get_delta_sphere(d->dis, vec, SPHERES[i]->radius);
		if (d->delta == -1 || (d->tmp < d->delta))
		{
			if (d->tmp != -1)
			{
				d->delta = d->tmp;
				*d->type = 1;
				*d->itype = i;
			}
		}
		i++;
	}
}

void	get_delta_all_cylinders(t_rt *e, t_v3f vec, t_delta *d)
{
	int		i;

	i = 0;
	while (CYLINDERS[i])
	{
		ft_memset(d->dis, 0, sizeof(d->dis));
		add_3f(&d->dis, &CYLINDERS[i]->pos, &CAM.pos);
		d->tmp = get_delta_cylinder(d->dis, vec, CYLINDERS[i]->radius);
		if (d->tmp < d->delta)
		{
			d->delta = d->tmp;
			*d->type = 2;
			*d->itype = i;
		}
		i++;
	}
}

void	get_delta_all_cones(t_rt *e, t_v3f vec, t_delta *d)
{
	int		i;

	i = 0;
	while (CONES[i])
	{
		ft_memset(d->dis, 0, sizeof(d->dis));
		add_3f(&d->dis, &CONES[i]->pos, &CAM.pos);
		d->tmp = get_delta_cone(d->dis, vec, CONES[i]->radius);
		if (d->tmp < d->delta)
		{
			d->delta = d->tmp;
			*d->type = 3;
			*d->itype = i;
		}
		i++;
	}
}

void	get_delta_all_planes(t_rt *e, t_v3f vec, t_delta *d)
{
	int		i;

	i = 0;
	while (PLANES[i])
	{
		ft_memset(d->dis, 0, sizeof(d->dis));
		add_3f(&d->dis, &PLANES[i]->pos, &CAM.pos);
		d->tmp = get_delta_plane(d->dis, vec, PLANES[i]->dist, e);
		if (d->delta == -1 || (d->tmp < d->delta))
		{
			if (d->tmp != -1)
			{
				d->delta = d->tmp;
				*d->type = 4;
				*d->itype = i;
			}
		}
		i++;
	}
}

void	get_delta_all_spots(t_rt *e, t_v3f vec, t_delta *d)
{
	e += 0;
	vec.x += 0;
	d += 0;
}
