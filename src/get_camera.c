/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 02:40:47 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/31 19:32:02 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	set_cam(t_rt *e)
{
	ft_memset(CAM.pos, 0, sizeof(CAM.pos));
	ft_memset(CAM.dir, 0, sizeof(CAM.dir));
}

void	get_camera(t_rt *e, char **scene)
{
	int		i;

	i = 0;
	set_cam(e);
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
						get_pos(&CAM.pos, scene, i);
					if (!(ft_strncmp(scene[i], "\tdir:", 5)))
						get_dir(&CAM.dir, scene, i);
					i++;
				}
			}
		}
		if (scene[i])
			i++;
	}
}
