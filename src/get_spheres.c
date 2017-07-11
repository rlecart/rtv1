/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spheres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 03:47:25 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/11 07:27:43 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	new_sphere(t_rt *e, int *i)
{
	if (!(e->obj.spheres->next = (t_spheres*)malloc(sizeof(t_spheres))))
		return ;
	e->obj.spheres->next->before = e->obj.spheres;
	e->obj.spheres->next->next = NULL;
	e->obj.spheres = e->obj.spheres->next;
	(*i)++;
}

void	get_spheres(t_rt *e, char **scene)
{
	int		i;

	i = -1;
	while (scene[++i])
		if (scene[i][0] && scene[i][0] != '\t')
		{
			if (!(ft_strcmp(scene[i], "spheres:"))
					&& !(ft_strcmp(scene[i + 1], "\tnew:")))
			{
				i += 2;
				while (scene[i] && scene[i][0] && scene[i][0] == '\t')
				{
					if (!(ft_strncmp(scene[i], "\t\tpos:", 6)))
						get_pos(&e->obj.spheres->pos, scene, i);
					if (!(ft_strncmp(scene[i], "\t\tradius:", 9)))
						get_radius(&e->obj.spheres->radius, scene, i);
					if (!(ft_strncmp(scene[i], "\t\tcolor:", 8)))
						get_col(&e->obj.spheres->color, scene, i);
					if (scene[i] && !(ft_strcmp(scene[++i], "\tnew:")))
						new_sphere(e, &i);
				}
			}
		}
	while (e->obj.spheres->before)
		e->obj.spheres = e->obj.spheres->before;
}
