/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 03:47:55 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/12 00:45:10 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	new_cylinder(t_rt *e, int *i)
{
	if (!(e->obj.cylinders->next = (t_cylinders*)malloc(sizeof(t_cylinders))))
		exit(-1);
	e->obj.cylinders->next->before = e->obj.cylinders;
	e->obj.cylinders->next->next = NULL;
	e->obj.cylinders = e->obj.cylinders->next;
	ft_memset(e->obj.cylinders, 0, sizeof(e->obj.cylinders));
	(*i)++;
}

void	first_cylinder(t_rt *e, int *i)
{
	if (!(e->obj.cylinders = (t_cylinders*)malloc(sizeof(t_cylinders))))
		exit(-1);
	e->obj.cylinders->before = NULL;
	e->obj.cylinders->next = NULL;
	ft_memset(e->obj.cylinders, 0, sizeof(e->obj.cylinders));
	(*i)++;
}

void	get_cylinders(t_rt *e, char **scene)
{
	int		i;

	i = -1;
	while (scene[++i])
		if (scene[i][0] && scene[i][0] != '\t')
		{
			if (!(ft_strcmp(scene[i], "cylinders:"))
					&& !(ft_strcmp(scene[i + 1], "\tnew:")))
			{
				first_cylinder(e, &i);
				while (scene[i] && scene[i][0] && scene[i][0] == '\t')
				{
					if (scene[i] && !(ft_strcmp(scene[++i], "\tnew:")))
						new_cylinder(e, &i);
					if (!(ft_strncmp(scene[i], "\t\tpos:", 6)))
						get_pos(&e->obj.cylinders->pos, scene, i);
					if (!(ft_strncmp(scene[i], "\t\tradius:", 9)))
						get_radius(&e->obj.cylinders->radius, scene, i);
					if (!(ft_strncmp(scene[i], "\t\tcolor:", 8)))
						get_col(&e->obj.cylinders->color, scene, i);
				}
			}
		}
	while (e->obj.cylinders->before)
		e->obj.cylinders = e->obj.cylinders->before;
}
