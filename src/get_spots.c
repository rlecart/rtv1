/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spots.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 03:48:36 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/07 15:23:25 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	get_spots_values(t_rt *e, char **scene, int *i, int *j)
{
	if (scene[*i] && !(ft_strcmp(scene[(*i)], "\tnew:")))
	{
		(*j)++;
		if (!(SPOTS = ft_realloc(SPOTS, sizeof(t_spots*) * (*j + 1))))
			exit(-1);
		SPOTS[*j] = NULL;
		if (!(SPOTS[*j - 1] = (t_spots*)malloc(sizeof(t_spots))))
			exit(-1);
		(*i)++;
	}
	if (!(ft_strncmp(scene[*i], "\t\tpos:", 6)))
		get_pos(&SPOTS[*j - 1]->pos, scene, *i);
	if (!(ft_strncmp(scene[*i], "\t\tdir:", 6)))
		get_dir(&SPOTS[*j - 1]->pos, scene, *i);
	if (!(ft_strncmp(scene[*i], "\t\tcolor:", 8)))
		get_col(&SPOTS[*j - 1]->color, scene, *i);
	(*i)++;
}

void	get_spots(t_rt *e, char **scene)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (scene[i])
	{
		if (scene[i][0] && scene[i][0] != '\t')
		{
			if (!(ft_strcmp(scene[i], "spots:"))
					&& !(ft_strcmp(scene[i + 1], "\tnew:")))
			{
				i++;
				while (scene[i] && scene[i][0] && scene[i][0] == '\t')
					get_spots_values(e, scene, &i, &j);
			}
		}
		if (scene[i])
			i++;
	}
}
