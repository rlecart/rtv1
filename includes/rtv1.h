/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:37:39 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/09 15:18:53 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RTV1_H
# define RTV1_H

# include "../libft/libft.h"
# include <math.h>
# include "../miniLibX/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libvec/libvec.h"

/*
** if we want to switch on or off supersampler we need to change
** SS value. 1 for off, 2 for on.
*/

# define DEFAULT_SUPERSAMPLING 1
# define SS (e->setup.supersampling + 1)
# define W 1500 * SS
# define H 800 * SS
# define FOV 30
# define KEY_ESC 53
# define DIST_MAX 20000
# define DIST_MIN -80000
# define AMBIENT_LIGHT 50

/*
** Compute the average color between two 24-bits RGB colors
** https://www.compuphase.com/graphic/scale3.htm
*/
# define AVERAGE(a, b)   ( ((((a) ^ (b)) & 0xfffefefeL) >> 1) + ((a) & (b)) )

//# define AVERAGE(a, b)   ( ((((a) ^ (b)) & 0xfffefefeL) >> 1) + ((a) + (b)) ) //effect bizarre

enum	e_type
{
	PLANE = 2,
	SPHERE,
	CYLINDER,
	CONE
};

typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

typedef struct	s_setup
{
	int			supersampling;
	int			bpp;
	int			sl;
	int			endian;
	t_vector	camera;
}				t_setup;

typedef struct	s_ray
{
	t_vector	origin;
	t_vector	direction;
}				t_ray;

typedef struct	s_color
{
	float		r;
	float		g;
	float		b;
}				t_color;

typedef struct		s_light
{
	/*this are the 3 variables that 
	* are definitve for the moment
	*/
	int 			is_init;
	t_vec3			pos;
	t_color 		color;

	float			intensity;
	t_vector		origin;
	struct s_light	*next;
}					t_light;

typedef struct	s_object
{
	int				type;
	float			radius;
	t_vector		normal;
	t_vector		origin;
	t_vector		direction;
	t_color			color;
	struct s_object	*next;
}				t_object;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	t_setup			setup;
	char			*data;
	t_light			*light;
	unsigned int	*img_temp;
	t_object		*obj;
	int				nbline;
	int				fd;
}					t_env;

/**************** paralel structures **************/

typedef struct		s_mlx
{
	void			*init;
	void			*window;
	void			*image;
	char			*data;
	int				bpp;
	int				size_l;
	int				endian;
	float			color;
	int 			basex;
	int 			basey;
	int 			zoom;
	int 			angle;
}					t_mlx;

typedef struct		s_input
{
	int				basex;
	int				basey;
	int				largeur;
	int				hauteur;
}					t_input;

typedef struct 		s_camera
{
	t_ray 			ray;
	t_light 		*lights;
	float 			focale;
	float 			reso;
	float			coef;
	float 			t;
	t_color 		c_lamb;
}					t_camera;

typedef struct  	s_matiere
{
	float			amb;
	t_color			diffuse;
	float			reflex;
	float			specular;
	float			shininess;
	float			reflect;
	float			transparency;
	float			absorbtion;
	char			*coeff;
	char			opacite;
}					t_matiere;

typedef struct 		s_obj
{
	char			is_init;
	char			type;
	t_color 		color;
	t_vec3			pos;
	t_vec3			rot;
	float			size;
	t_vec3			vector; //For Plane, Cylinder, Cone and Sphere
	t_vec3			maxp; //For Cylinder and Cone
	t_vec3			minp; //For Cone
	int				r;
	float			t;
	t_matiere		*mat;
}					t_obj;

typedef	struct	s_scene
{
	t_light		*lights;
	t_obj		*objects;
	int			nbr_light;
	int			nbr_object;
	char		crt_thing;
}				t_scene;

typedef struct  	s_sphere
{
	t_vec3 			pos;
	float 			r;
	t_matiere 		currentMat;
}					t_sphere;

typedef struct  	s_file
{
	char			*file_name;
	t_sphere		*sphere;
}					t_file;

typedef struct		s_rt
{
	t_mlx			*mlx;
	t_input			*input;
	t_camera		*cam;
	t_file			*source;
	t_scene			scene;
}					t_rt;


unsigned int	ret_colors(t_color color);
t_vector		normalize(t_vector vector);
t_vector		c_vector(float x, float y, float z);
t_vector		vec_ope_min(t_vector v1, t_vector v2);
t_vector		vec_ope_add(t_vector v1, t_vector v2);
t_vector		vec_ope_mult(t_vector v1, float d);
t_vector		vec_ope_div(t_vector v1, float d);
t_ray			c_ray(t_vector i, t_vector j);
t_color			c_color(float r, float g, float b);
void			set_win_img(t_env *e);
int				raytrace(t_env *e);
void			super_sampler(t_env *e);
void			anti_supersampler(t_env *e);
float			dot(t_vector v, t_vector b);
float			intersect_sphere(t_ray ray, t_object sphere);
int				key_hook(int keycode, t_env *e);
t_color			*color_mult(t_color color, float taux);
float			get_length(t_vector v);
float			intersect_plane(t_ray ray, t_object sphere);
float			intersect_cylinder(t_ray ray, t_object cylinder);
t_color			*copy_color(t_color color);
float			intersect_cone(t_ray ray, t_object cone);
float			intensity_cone(t_env *e, t_vector poi,
					t_object cone, t_light light);
float			intensity_sphere(t_env *e, t_vector poi,
					t_object sphere, t_light light);
float			intensity_plane(t_env *e, t_vector poi,
					t_object plane, t_light light);
float			intensity_cylinder(t_env *e, t_vector poi,
					t_object cylinder, t_light light);
float			get_min_dist(t_env *e, t_ray ray, t_object **closest, int cangoneg);
int				obj_in_shadow(t_env *e, t_vector poi, t_light light);
float			get_res_of_quadratic(float a, float b, float c);

/*
** Parser
*/

t_env			*parse(char *scene);
void			syntax_error(char *line, char *explain, int nbline);
void			unknown_setting(char *line, int nbline);
char			*trim_setting(t_env *e, char *setting);
char			*trim_option(t_env *e, char *option, char **arg);
void			dispatch(t_env *e, char *line);
void			set_sphere(t_env *e);
void			set_plane(t_env *e);
void			set_plane_data(t_object *plane);
void			set_cylinder(t_env *e);
void			set_cone(t_env *e);
void			set_camera(t_env *e);
void			set_light(t_env *e);
void			set_supersampling(t_env *e, char *line);
t_vector		set_vector(t_env *e, char *arg);
t_color			set_color(t_env *e, char *arg);
void			unknown_option(char *line, int nbline, char *caller);
void			set_first_obj(t_env *e, t_object *obj);
void			set_first_light(t_env *e, t_light *light);

#endif