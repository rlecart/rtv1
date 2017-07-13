/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cones.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 03:48:09 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/13 03:49:24 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	new_cone(t_rt *e, int *i)
{
	if (!(CONES->next = (t_cones*)malloc(sizeof(t_cones))))
		exit(-1);
	CONES->next->before = CONES;
	CONES->next->next = NULL;
	CONES = CONES->next;
	ft_memset(CONES, 0, sizeof(CONES));
	(*i)++;
}

void	first_cone(t_rt *e, int *i)
{
	if (!(CONES = (t_cones*)malloc(sizeof(t_cones))))
		exit(-1);
	CONES->before = NULL;
	CONES->next = NULL;
	ft_memset(CONES, 0, sizeof(CONES));
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
				first_cone(e, &i);
				while (scene[i] && scene[i][0] && scene[i][0] == '\t')
				{
					if (scene[i] && !(ft_strcmp(scene[++i], "\tnew:")))
						new_cone(e, &i);
					if (!(ft_strncmp(scene[i], "\t\tpos:", 6)))
						get_pos(&CONES->pos, scene, i);
					if (!(ft_strncmp(scene[i], "\t\tradius:", 9)))
						get_radius(&CONES->radius, scene, i);
					if (!(ft_strncmp(scene[i], "\t\tcolor:", 8)))
						get_col(&CONES->color, scene, i);
				}
			}
		}
	while (CONES->before)
		CONES = CONES->before;
}
