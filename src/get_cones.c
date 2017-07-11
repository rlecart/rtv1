/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cones.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 03:48:09 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/11 07:27:22 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	new_cone(t_rt *e, int *i)
{
	if (!(e->obj.cones->next = (t_cones*)malloc(sizeof(t_cones))))
		return ;
	e->obj.cones->next->before = e->obj.cones;
	e->obj.cones->next->next = NULL;
	e->obj.cones = e->obj.cones->next;
	(*i)++;
}

void	get_cones(t_rt *e, char **scene)
{
	int		i;

	i = -1;
	while (scene[++i])
		if (scene[i][0] && scene[i][0] != '\t')
		{
			if (!(ft_strcmp(scene[i], "cones:"))
					&& !(ft_strcmp(scene[i + 1], "\tnew:")))
			{
				i += 2;
				while (scene[i] && scene[i][0] && scene[i][0] == '\t')
				{
					if (!(ft_strncmp(scene[i], "\t\tpos:", 6)))
						get_pos(&e->obj.cones->pos, scene, i);
					if (!(ft_strncmp(scene[i], "\t\tradius:", 9)))
						get_radius(&e->obj.cones->radius, scene, i);
					if (!(ft_strncmp(scene[i], "\t\tcolor:", 8)))
						get_col(&e->obj.cones->color, scene, i);
					if (scene[i] && !(ft_strcmp(scene[++i], "\tnew:")))
						new_cone(e, &i);
				}
			}
		}
	while (e->obj.cones->before)
		e->obj.cones = e->obj.cones->before;
}
