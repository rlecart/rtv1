/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 04:06:08 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/07 15:26:08 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	get_pos(float (*bpos)[3], char **scene, int i)
{
	char	**pos;

	pos = ft_strsplit_wc(scene[i], ' ');
	if (pos[1] && pos[2] && pos[3])
	{
		(*bpos)[0] = ft_atof(pos[1]);
		(*bpos)[1] = ft_atof(pos[2]);
		(*bpos)[2] = ft_atof(pos[3]);
	}
	ft_strtabdel(&pos);
}

void	get_dir(float (*bdir)[3], char **scene, int i)
{
	char	**dir;

	dir = ft_strsplit_wc(scene[i], ' ');
	if (dir[1] && dir[2] && dir[3])
	{
		(*bdir)[0] = ft_atof(dir[1]);
		(*bdir)[1] = ft_atof(dir[2]);
		(*bdir)[2] = ft_atof(dir[3]);
	}
	ft_strtabdel(&dir);
}

void	get_col(float (*bcol)[4], char **scene, int i)
{
	char	**col;

	col = ft_strsplit_wc(scene[i], ' ');
	if (col[1] && col[2] && col[3])
	{
		(*bcol)[0] = ft_atof(col[1]);
		(*bcol)[1] = ft_atof(col[2]);
		(*bcol)[2] = ft_atof(col[3]);
		(*bcol)[3] = ft_atof(col[4]);
	}
	ft_strtabdel(&col);
}

void	get_radius(float *brad, char **scene, int i)
{
	char	**rad;

	rad = ft_strsplit_wc(scene[i], ' ');
	if (rad[1])
		*brad = ft_atof(rad[1]);
	ft_strtabdel(&rad);
}
