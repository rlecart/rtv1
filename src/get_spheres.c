/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spheres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 03:47:25 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/07 15:26:56 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	get_spheres_values(t_rt *e, char **scene, int *i, int *j)
{
	if (scene[*i] && !(ft_strcmp(scene[(*i)], "\tnew:")))
	{
		(*j)++;
		if (!(SPHERES = ft_realloc(SPHERES, sizeof(t_spheres*) * (*j + 1))))
			exit(-1);
		SPHERES[*j] = NULL;
		if (!(SPHERES[*j - 1] = (t_spheres*)malloc(sizeof(t_spheres))))
			exit(-1);
		(*i)++;
	}
	if (!(ft_strncmp(scene[*i], "\t\tpos:", 6)))
		get_pos(&SPHERES[*j - 1]->pos, scene, *i);
	if (!(ft_strncmp(scene[*i], "\t\tradius:", 9)))
		get_radius(&SPHERES[*j - 1]->radius, scene, *i);
	if (!(ft_strncmp(scene[*i], "\t\tcolor:", 8)))
		get_col(&SPHERES[*j - 1]->color, scene, *i);
	(*i)++;
}

void	get_spheres(t_rt *e, char **scene)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (scene[i])
	{
		if (scene[i][0] && scene[i][0] != '\t')
		{
			if (!(ft_strcmp(scene[i], "spheres:"))
					&& !(ft_strcmp(scene[i + 1], "\tnew:")))
			{
				i++;
				while (scene[i] && scene[i][0] && scene[i][0] == '\t')
					get_spheres_values(e, scene, &i, &j);
			}
		}
		if (scene[i])
			i++;
	}
}
