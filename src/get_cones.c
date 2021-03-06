/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cones.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 03:48:09 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/07 15:26:04 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	get_cones_values(t_rt *e, char **scene, int *i, int *j)
{
	if (scene[*i] && !(ft_strcmp(scene[(*i)], "\tnew:")))
	{
		(*j)++;
		if (!(CONES = ft_realloc(CONES, sizeof(t_cones*) * (*j + 1))))
			exit(-1);
		CONES[*j] = NULL;
		if (!(CONES[*j - 1] = (t_cones*)malloc(sizeof(t_cones))))
			exit(-1);
		(*i)++;
	}
	if (!(ft_strncmp(scene[*i], "\t\tpos:", 6)))
		get_pos(&CONES[*j - 1]->pos, scene, *i);
	if (!(ft_strncmp(scene[*i], "\t\tradius:", 9)))
		get_radius(&CONES[*j - 1]->radius, scene, *i);
	if (!(ft_strncmp(scene[*i], "\t\tcolor:", 8)))
		get_col(&CONES[*j - 1]->color, scene, *i);
	(*i)++;
}

void	get_cones(t_rt *e, char **scene)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (scene[i])
	{
		if (scene[i][0] && scene[i][0] != '\t')
		{
			if (!(ft_strcmp(scene[i], "cones:"))
					&& !(ft_strcmp(scene[i + 1], "\tnew:")))
			{
				i++;
				while (scene[i] && scene[i][0] && scene[i][0] == '\t')
					get_cones_values(e, scene, &i, &j);
			}
		}
		if (scene[i])
			i++;
	}
}
