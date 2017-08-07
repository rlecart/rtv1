/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 03:47:55 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/07 15:21:31 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	get_cylinders_values(t_rt *e, char **scene, int *i, int *j)
{
	if (scene[*i] && !(ft_strcmp(scene[(*i)], "\tnew:")))
	{
		(*j)++;
		if (!(CYLINDERS = ft_realloc(CYLINDERS, sizeof(t_cylinders*) * (*j + 1))))
			exit(-1);
		CYLINDERS[*j] = NULL;
		if (!(CYLINDERS[*j - 1] = (t_cylinders*)malloc(sizeof(t_cylinders))))
			exit(-1);
		(*i)++;
	}
	if (!(ft_strncmp(scene[*i], "\t\tpos:", 6)))
		get_pos(&CYLINDERS[*j - 1]->pos, scene, *i);
	if (!(ft_strncmp(scene[*i], "\t\tradius:", 9)))
		get_radius(&CYLINDERS[*j - 1]->radius, scene, *i);
	if (!(ft_strncmp(scene[*i], "\t\tcolor:", 8)))
		get_col(&CYLINDERS[*j - 1]->color, scene, *i);
	(*i)++;
}

void	get_cylinders(t_rt *e, char **scene)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (scene[i])
	{
		if (scene[i][0] && scene[i][0] != '\t')
		{
			if (!(ft_strcmp(scene[i], "cylinders:"))
					&& !(ft_strcmp(scene[i + 1], "\tnew:")))
			{
				i++;
				while (scene[i] && scene[i][0] && scene[i][0] == '\t')
					get_cylinders_values(e, scene, &i, &j);
			}
		}
		if (scene[i])
			i++;
	}
}
