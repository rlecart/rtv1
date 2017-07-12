/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_planes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 03:48:22 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/12 00:45:05 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	new_plane(t_rt *e, int *i)
{
	if (!(e->obj.planes->next = (t_planes*)malloc(sizeof(t_planes))))
		exit(-1);
	e->obj.planes->next->before = e->obj.planes;
	e->obj.planes->next->next = NULL;
	e->obj.planes = e->obj.planes->next;
	ft_memset(e->obj.planes, 0, sizeof(e->obj.planes));
	(*i)++;
}

void	first_plane(t_rt *e, int *i)
{
	if (!(e->obj.planes = (t_planes*)malloc(sizeof(t_planes))))
		exit(-1);
	e->obj.planes->before = NULL;
	e->obj.planes->next = NULL;
	ft_memset(e->obj.planes, 0, sizeof(e->obj.planes));
	(*i)++;
}

void	get_planes(t_rt *e, char **scene)
{
	int		i;

	i = -1;
	while (scene[++i])
		if (scene[i][0] && scene[i][0] != '\t')
		{
			if (!(ft_strcmp(scene[i], "planes:"))
					&& !(ft_strcmp(scene[i + 1], "\tnew:")))
			{
				first_plane(e, &i);
				while (scene[i] && scene[i][0] && scene[i][0] == '\t')
				{
					if (scene[i] && !(ft_strcmp(scene[++i], "\tnew:")))
						new_plane(e, &i);
					if (!(ft_strncmp(scene[i], "\t\tpos:", 6)))
						get_pos(&e->obj.planes->pos, scene, i);
					if (!(ft_strncmp(scene[i], "\t\tdist:", 7)))
						get_radius(&e->obj.planes->dist, scene, i);
					if (!(ft_strncmp(scene[i], "\t\tcolor:", 8)))
						get_col(&e->obj.planes->color, scene, i);
				}
			}
		}
	while (e->obj.planes->before)
		e->obj.planes = e->obj.planes->before;
}
