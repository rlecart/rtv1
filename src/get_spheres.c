/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spheres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 03:47:25 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/13 04:05:37 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	new_sphere(t_rt *e, int *i)
{
	if (!(SPHERES->next = (t_spheres*)malloc(sizeof(t_spheres))))
		exit(-1);
	SPHERES->next->before = SPHERES;
	SPHERES->next->next = NULL;
	SPHERES = SPHERES->next;
	ft_memset(SPHERES, 0, sizeof(SPHERES));
	(*i)++;
}

void	first_sphere(t_rt *e, int *i)
{
	if (!(SPHERES = (t_spheres*)malloc(sizeof(t_spheres))))
		exit(-1);
	SPHERES->before = NULL;
	SPHERES->next = NULL;
	ft_memset(SPHERES, 0, sizeof(SPHERES));
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
				first_sphere(e, &i);
				while (scene[i] && scene[i][0] && scene[i][0] == '\t')
				{
					if (scene[i] && !(ft_strcmp(scene[++i], "\tnew:")))
						new_sphere(e, &i);
					if (!(ft_strncmp(scene[i], "\t\tpos:", 6)))
						get_pos(&SPHERES->pos, scene, i);
					if (!(ft_strncmp(scene[i], "\t\tradius:", 9)))
						get_radius(&SPHERES->radius, scene, i);
					if (!(ft_strncmp(scene[i], "\t\tcolor:", 8)))
						get_col(&SPHERES->color, scene, i);
				}
			}
		}
	while (SPHERES->before)
		SPHERES = SPHERES->before;
}
