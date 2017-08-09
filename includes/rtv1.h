/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 20:36:04 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/10 01:19:44 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <../libft/includes/libft.h>
# include <../graphics/includes/graphics.h>
# include <../libvec/libvec.h>

# define MLX e->mlx
# define WIN e->win
# define CAM e->cam
# define SPHERES e->obj.spheres
# define CYLINDERS e->obj.cylinders
# define CONES  e->obj.cones
# define PLANES e->obj.planes
# define SPOTS e->obj.spots

typedef	struct		s_ray
{
	t_vec3			origin;
	t_vec3			direction;
}					t_ray;

typedef struct		s_delta
{
	float			tmp;
	float			delta;
	float			dis[3];
	int				*type;
	int				*itype;
}					t_delta;

typedef struct		s_spheres
{
	float				pos[3];
	float				radius;
	float				color[4];
}						t_spheres;

typedef struct			s_cylinders
{
	float				pos[3];
	float				radius;
	float				color[4];
}						t_cylinders;

typedef struct			s_cones
{
	float				pos[3];
	float				radius;
	float				color[4];
}						t_cones;

typedef struct			s_planes
{
	float				pos[3];
	float				dist;
	float				color[4];
}						t_planes;

typedef struct			s_spots
{
	float				pos[3];
	float				dir[3];
	float				color[4];
}						t_spots;

typedef struct			s_obj
{
	t_spheres			**spheres;
	t_cylinders			**cylinders;
	t_cones				**cones;
	t_planes			**planes;
	t_spots				**spots;
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

float					get_delta_sphere(float pos[3], t_v3f vec, float radius);
float					get_delta_cylinder(float pos[3], t_v3f vec, float radius);
float					get_delta_cone(float pos[3], t_v3f vec, float radius);
float					get_delta_plane(float pos[3], t_v3f vec, float distance);
float					get_delta_spot(float pos[3], t_v3f vec, float radius);

void					get_delta_all_spheres(t_rt *e, t_v3f vec, t_delta *d);
void					get_delta_all_cylinders(t_rt *e, t_v3f vec, t_delta *d);
void					get_delta_all_cones(t_rt *e, t_v3f vec, t_delta *d);
void					get_delta_all_planes(t_rt *e, t_v3f vec, t_delta *d);
void					get_delta_all_spots(t_rt *e, t_v3f vec, t_delta *d);

void					draw_obj(t_rt *e);

void					print_debug(t_rt *e);

#endif
