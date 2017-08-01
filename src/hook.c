/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 19:39:00 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/01 04:16:29 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int		key_hook(int key, t_rt *e)
{
	if (key == ESC)
		exit(0);
	else if (key == MINUS)
	{
		CAM.pos[0] -= 0.1;
	}
	else if (key == PLUS)
	{
		CAM.pos[0] += 0.1;
	}
	else if (key == LEFT)
	{
		CAM.pos[1] -= 0.1;
	}
	else if (key == RIGHT)
	{
		CAM.pos[1] += 0.1;
	}
	else if (key == UP)
	{
		CAM.pos[2] -= 0.1;
	}
	else if (key == DOWN)
	{
		CAM.pos[2] += 0.1;
	}
	printf("key = %d\n", key);
	draw_obj(e);
	return (1);
}
