/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spots.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 03:48:36 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/31 19:37:53 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	new_spot(t_rt *e, int *i)
{
	if (!(SPOTS->next = (t_spots*)malloc(sizeof(t_spots))))
		exit(-1);
	ft_memset(SPOTS->next, 0, sizeof(SPOTS));
	SPOTS->next->before = SPOTS;
	SPOTS->next->next = NULL;
	SPOTS = SPOTS->next;
	(*i)++;
}

void	first_spot(t_rt *e, int *i)
{
	if (!(SPOTS = (t_spots*)malloc(sizeof(t_spots))))
		exit(-1);
	ft_memset(SPOTS, 0, sizeof(SPOTS));
	SPOTS->before = NULL;
	SPOTS->next = NULL;
	*i += 2;
}

void	get_spots_values(t_rt *e, char **scene, int *i)
{
	if (!(ft_strncmp(scene[*i], "\t\tcolor:", 8)))
		get_col(&SPOTS->color, scene, *i);
	if (!(ft_strncmp(scene[*i], "\t\tpos:", 6)))
		get_pos(&SPOTS->pos, scene, *i);
	(*i)++;
	if (scene[*i] && !(ft_strcmp(scene[*i], "\tnew:")))
		new_spot(e, i);
}

void	get_spots(t_rt *e, char **scene)
{
	int		i;

	i = 0;
	while (scene[i])
	{
		if (scene[i][0] && scene[i][0] != '\t')
		{
			if (!(ft_strcmp(scene[i], "spots:"))
					&& !(ft_strcmp(scene[i + 1], "\tnew:")))
			{
				first_spot(e, &i);
				while (scene[i] && scene[i][0] && scene[i][0] == '\t')
					get_spots_values(e, scene, &i);
			}
		}
		if (scene[i])
			i++;
	}
	while (SPOTS && SPOTS->before)
		SPOTS = SPOTS->before;
}
