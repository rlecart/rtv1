/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 02:40:47 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/11 07:12:28 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	get_camera(t_rt *e, char **scene)
{
	int		i;

	i = 0;
	while (scene[i])
	{
		if (scene[i][0] && scene[i][0] != '\t')
		{
			if (!(ft_strcmp(scene[i], "camera:")))
			{
				i++;
				while (scene[i] && scene[i][0] && scene[i][0] == '\t')
				{
					if (!(ft_strncmp(scene[i], "\tpos:", 5)))
						get_pos(&e->cam.pos, scene, i);
					if (!(ft_strncmp(scene[i], "\tdir:", 5)))
						get_dir(&e->cam.dir, scene, i);
					i++;
				}
			}
		}
		i++;
	}
}
