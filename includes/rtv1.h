/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 20:36:04 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/31 20:28:36 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <../libft/includes/libft.h>
# include <../graphics/includes/graphics.h>

# define MLX e->mlx
# define WIN e->win
# define CAM e->cam
# define SPHERES e->obj.spheres
# define CYLINDERS e->obj.cylinders
# define CONES  e->obj.cones
# define PLANES e->obj.planes
# define SPOTS e->obj.spots

typedef struct		s_spheres
{
	float				pos[3];
	float				radius;
	float				color[4];
	struct s_spheres	*before;
	struct s_spheres	*next;
}						t_spheres;

typedef struct			s_cylinders
{
	float				pos[3];
	float				radius;
	float				color[4];
	struct s_cylinders	*before;
	struct s_cylinders	*next;
}						t_cylinders;

typedef struct			s_cones
{
	float				pos[3];
	float				radius;
	float				color[4];
	struct s_cones		*before;
	struct s_cones		*next;
}						t_cones;

typedef struct			s_planes
{
	float				pos[3];
	float				dist;
	float				color[4];
	struct s_planes		*before;
	struct s_planes		*next;
}						t_planes;

typedef struct			s_spots
{
	float				pos[3];
	float				color[4];
	struct s_spots		*before;
	struct s_spots		*next;
}						t_spots;

typedef struct			s_obj
{
	t_spheres			*spheres;
	t_cylinders			*cylinders;
	t_cones				*cones;
	t_planes			*planes;
	t_spots				*spots;
}						t_obj;

typedef struct			s_camera
{
	float				pos[3];
	float				dir[3];
}						t_camera;

typedef struct			s_rt
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data;
	t_camera			cam;
	t_obj				obj;
}						t_rt;

void					init(t_rt *e, char *file);
int						key_hook(int key, t_rt *e);

void					get_camera(t_rt *e, char **scene);
void					get_spheres(t_rt *e, char **scene);
void					get_cylinders(t_rt *e, char **scene);
void					get_cones(t_rt *e, char **scene);
void					get_planes(t_rt *e, char **scene);
void					get_spots(t_rt *e, char **scene);

void					get_pos(float (*bpos)[3], char **scene, int i);
void					get_dir(float (*bdir)[3], char **scene, int i);
void					get_col(float (*bcol)[4], char **scene, int i);
void					get_radius(float *brad, char **scene, int i);

void					draw_obj(t_rt *e);
void					draw_sphere(t_spheres *o);
void					draw_cylinder(t_cylinders *o);
void					draw_cone(t_cones *o);
void					draw_plane(t_planes *o);

void					print_debug(t_rt *e);

#endif
