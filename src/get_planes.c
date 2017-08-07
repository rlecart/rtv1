/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_planes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 03:48:22 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/07 19:00:11 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	get_planes_values(t_rt *e, char **scene, int *i, int *j)
{
	if (scene[*i] && !(ft_strcmp(scene[(*i)], "\tnew:")))
	{
		(*j)++;
		if (!(PLANES = ft_realloc(PLANES, sizeof(t_planes*) * (*j + 1))))
			exit(-1);
		PLANES[*j] = NULL;
		if (!(PLANES[*j - 1] = (t_planes*)malloc(sizeof(t_planes))))
			exit(-1);
		(*i)++;
	}
	if (!(ft_strncmp(scene[*i], "\t\tpos:", 6)))
		get_pos(&PLANES[*j - 1]->pos, scene, *i);
	if (!(ft_strncmp(scene[*i], "\t\tdist:", 7)))
		get_radius(&PLANES[*j - 1]->dist, scene, *i);
	if (!(ft_strncmp(scene[*i], "\t\tcolor:", 8)))
		get_col(&PLANES[*j - 1]->color, scene, *i);
	(*i)++;
}

void	get_planes(t_rt *e, char **scene)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (scene[i])
	{
		if (scene[i][0] && scene[i][0] != '\t')
		{
			if (!(ft_strcmp(scene[i], "planes:"))
					&& !(ft_strcmp(scene[i + 1], "\tnew:")))
			{
				i++;
				while (scene[i] && scene[i][0] && scene[i][0] == '\t')
					get_planes_values(e, scene, &i, &j);
			}
		}
		if (scene[i])
			i++;
	}
}
