/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_planes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 03:48:22 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/01 01:25:12 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	new_plane(t_rt *e, int *i)
{
	if (!(PLANES->next = (t_planes*)malloc(sizeof(t_planes))))
		exit(-1);
	PLANES->next->before = PLANES;
	PLANES->next->next = NULL;
	PLANES = PLANES->next;
	ft_memset(PLANES, 0, sizeof(PLANES));
	(*i)++;
}

void	first_plane(t_rt *e, int *i)
{
	if (!(PLANES = (t_planes*)malloc(sizeof(t_planes))))
		exit(-1);
	PLANES->before = NULL;
	PLANES->next = NULL;
	ft_memset(PLANES, 0, sizeof(PLANES));
	(*i)++;
}

void	get_planes_values(t_rt *e, char **scene, int *i)
{
	if (scene[*i] && !(ft_strcmp(scene[++(*i)], "\tnew:")))
		new_plane(e, i);
	if (!(ft_strncmp(scene[*i], "\t\tpos:", 6)))
		get_pos(&PLANES->pos, scene, *i);
	if (!(ft_strncmp(scene[*i], "\t\tdist:", 7)))
		get_radius(&PLANES->dist, scene, *i);
	if (!(ft_strncmp(scene[*i], "\t\tcolor:", 8)))
		get_col(&PLANES->color, scene, *i);
}

void	get_planes(t_rt *e, char **scene)
{
	int		i;

	i = 0;
	while (scene[i])
	{
		if (scene[i][0] && scene[i][0] != '\t')
		{
			if (!(ft_strcmp(scene[i], "planes:"))
					&& !(ft_strcmp(scene[i + 1], "\tnew:")))
			{
				first_plane(e, &i);
				while (scene[i] && scene[i][0] && scene[i][0] == '\t')
					get_planes_values(e, scene, &i);
			}
		}
		if (scene[i])
			i++;
	}
	while (PLANES && PLANES->before)
		PLANES = PLANES->before;
}
