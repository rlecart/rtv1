/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 20:36:32 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/12 18:47:51 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	stoprt(t_rt *e)
{
	if (e)
	{
/*		if (e->mlx)
			ft_memdel(&e->mlx);
		if (e->win)
			ft_memdel(&e->win);
*/		if (e->obj.spheres)
		{
			while (e->obj.spheres->next)
			{
				e->obj.spheres = e->obj.spheres->next;
				ft_memdel((void*)&e->obj.spheres->before);
			}
			ft_memdel((void*)&e->obj.spheres);
		}
		if (e->obj.cylinders)
		{
			while (e->obj.cylinders->next)
			{
				e->obj.cylinders= e->obj.cylinders->next;
				ft_memdel((void*)&e->obj.cylinders->before);
			}
			ft_memdel((void*)&e->obj.cylinders);
		}
		if (e->obj.cones)
		{
			while (e->obj.cones->next)
			{
				e->obj.cones = e->obj.cones->next;
				ft_memdel((void*)&e->obj.cones->before);
			}
			ft_memdel((void*)&e->obj.cones);
		}
		if (e->obj.planes)
		{
			while (e->obj.planes->next)
			{
				e->obj.planes = e->obj.planes->next;
				ft_memdel((void*)&e->obj.planes->before);
			}
			ft_memdel((void*)&e->obj.planes);
		}
		if (e->obj.spots)
		{
			while (e->obj.spots->next)
			{
				e->obj.spots = e->obj.spots->next;
				ft_memdel((void*)&e->obj.spots->before);
			}
			ft_memdel((void*)&e->obj.spots);
		}
	}
}

int		main(int argc, char **argv)
{
	t_rt	e;

	if (argc == 2)
	{
		if ((init(&e, argv[1])))
			return (-1);
	}
	stoprt(&e);
	return (0);
}
