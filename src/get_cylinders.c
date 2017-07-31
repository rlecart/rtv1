/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 03:47:55 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/31 19:35:35 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	new_cylinder(t_rt *e, int *i)
{
	if (!(CYLINDERS->next = (t_cylinders*)malloc(sizeof(t_cylinders))))
		exit(-1);
	CYLINDERS->next->before = CYLINDERS;
	CYLINDERS->next->next = NULL;
	CYLINDERS = CYLINDERS->next;
	ft_memset(CYLINDERS, 0, sizeof(CYLINDERS));
	(*i)++;
}

void	first_cylinder(t_rt *e, int *i)
{
	if (!(CYLINDERS = (t_cylinders*)malloc(sizeof(t_cylinders))))
		exit(-1);
	CYLINDERS->before = NULL;
	CYLINDERS->next = NULL;
	ft_memset(CYLINDERS, 0, sizeof(CYLINDERS));
	(*i)++;
}

void	get_cylinders_values(t_rt *e, char **scene, int *i)
{
	if (scene[*i] && !(ft_strcmp(scene[++(*i)], "\tnew:")))
		new_cylinder(e, i);
	if (!(ft_strncmp(scene[*i], "\t\tpos:", 6)))
		get_pos(&CYLINDERS->pos, scene, *i);
	if (!(ft_strncmp(scene[*i], "\t\tradius:", 9)))
		get_radius(&CYLINDERS->radius, scene, *i);
	if (!(ft_strncmp(scene[*i], "\t\tcolor:", 8)))
		get_col(&CYLINDERS->color, scene, *i);
}

void	get_cylinders(t_rt *e, char **scene)
{
	int		i;

	i = 0;
	while (scene[i])
	{
		if (scene[i][0] && scene[i][0] != '\t')
		{
			if (!(ft_strcmp(scene[i], "cylinders:"))
					&& !(ft_strcmp(scene[i + 1], "\tnew:")))
			{
				first_cylinder(e, &i);
				while (scene[i] && scene[i][0] && scene[i][0] == '\t')
					get_cylinders_values(e, scene, &i);
			}
		}
		if (scene[i])
			i++;
	}
	while (CYLINDERS && CYLINDERS->before)
		CYLINDERS = CYLINDERS->before;
}
