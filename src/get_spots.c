/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spots.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 03:48:36 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/11 07:28:26 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	new_spot(t_rt *e, int *i)
{
	if (!(e->obj.spots->next = (t_spots*)malloc(sizeof(t_spots))))
		return ;
	e->obj.spots->next->before = e->obj.spots;
	e->obj.spots->next->next = NULL;
	e->obj.spots = e->obj.spots->next;
	(*i)++;
}

void	get_spots(t_rt *e, char **scene)
{
	int		i;

	i = 0;
	while (scene[i++])
		if (scene[i][0] && scene[i][0] != '\t')
		{
			if (!(ft_strcmp(scene[i], "spots:"))
					&& !(ft_strcmp(scene[i + 1], "\tnew:")))
			{
				i += 2;
				while (scene[i] && scene[i][0] && scene[i][0] == '\t')
				{
					if (!(ft_strncmp(scene[i], "\t\tcolor:", 8)))
						get_col(&e->obj.spots->color, scene, i);
					if (!(ft_strncmp(scene[i], "\t\tpos:", 6)))
						get_pos(&e->obj.spots->pos, scene, i);
					i++;
					if (scene[i] && !(ft_strcmp(scene[i], "\tnew:")))
						new_spot(e, &i);
				}
			}
		}
	while (e->obj.spots->before)
		e->obj.spots = e->obj.spots->before;
}
