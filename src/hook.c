/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 19:39:00 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/07 15:21:18 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int		key_hook(int key, t_rt *e)
{
	if (key == ESC)
		exit(0);
	else if (key == KEY_W)
	{
		CAM.pos[0] += 0.5;
	}
	else if (key == KEY_S)
	{
		CAM.pos[0] -= 0.5;
	}
	else if (key == KEY_A)
	{
		CAM.pos[1] += 0.5;
	}
	else if (key == KEY_D)
	{
		CAM.pos[1] -= 0.5;
	}
	else if (key == SPACE)
	{
		CAM.pos[2] += 0.5;
	}
	else if (key == LSHIFT)
	{
		CAM.pos[2] -= 0.5;
	}
	else if (key == PAGE_UP)
	{
		CAM.dir[0] += 25;
	}
	else if (key == PAGE_DOWN)
	{
		CAM.dir[0] -= 25;
	}
	else if (key == LEFT)
	{
		CAM.dir[1] += 25;
	}
	else if (key == RIGHT)
	{
		CAM.dir[1] -= 25;
	}
	else if (key == UP)
	{
		CAM.dir[2] += 25;
	}
	else if (key == DOWN)
	{
		CAM.dir[2] -= 25;
	}
	printf("key = %d\n", key);
	if (key != 256)
		draw_obj(e);
	return (1);
}
