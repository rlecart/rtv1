/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:20:07 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/01 02:04:47 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "../../minilibx_macos/mlx.h"

# define WIN_W 1024
# define WIN_H 768

# define ESC 53
# define BACKSPACE 51
# define SPACE 49
# define ENTER 36
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define PLUS 69
# define MINUS 78
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

typedef struct		s_color
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_color;

void				pixel_put(char *data, int x, int y, t_color pix);
t_color				get_color(int b, int g, int r, int a);

#endif
