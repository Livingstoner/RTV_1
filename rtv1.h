/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 23:00:51 by rkhokhlo          #+#    #+#             */
/*   Updated: 2019/06/15 23:00:51 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "libft/libft.h"
# include "pthread.h"
# include "mlx.h"
# include "math.h"
# define FOV 60
# define HEIGHT 1024
# define WIDTH 1240
# define PI 3.1415926
# define SPHERE 1
# define CONE 2
# define CYLINDER 3
# define PLANE 4
# define BACKGROUND set_color(0, 0, 0)
# define SCALE tan(deg2rad(FOV * 0.5))
# define ABS(x)	(x) > 0 ? (x) : -(x)
# define ROUND(d) ABS(d) < 0.00001 ? 0 : (d)

typedef	double	t_vector __attribute__((vector_size(sizeof(double)*4)));

typedef struct			s_col
{
	double				r;
	double				g;
	double				b;
}						t_col;

typedef struct			s_ray
{
	t_vector	pos;
	t_vector	dir;
}						t_ray;

typedef struct			s_cam
{
	t_vector			pos;
	t_vector			dir;
}						t_cam;

typedef struct			s_conus
{
	t_vector			c;
	t_vector			dir;
	t_vector			surface_normal;
	t_vector			shadow_point;
	double				angle;
}						t_conus;

typedef struct			s_root
{
	double				x1;
	double				x2;
}						t_root;

typedef struct			s_plane
{
	t_vector			normal;
	t_vector			point;
	t_vector			surf_norm;
	t_vector			shadow_point;
}						t_plane;

typedef struct			s_sphere
{
	t_vector			center;
	double				rad;
	t_root				root;
	t_vector			norm;
	t_vector			p;
	t_vector			shadow_point;
}						t_sphere;

typedef struct			s_light
{
	t_vector			pos;
	double				intensity;
	struct s_light		*next;
}						t_light;

typedef struct			s_con
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
}						t_con;

typedef struct			s_shadow
{
	double				dist;
	t_vector			pos;
	t_vector			dir;
}						t_shadow;

typedef struct			s_cyl
{
	t_vector			start;
	t_vector			normal;
	double				rad;
}						t_cyl;

typedef struct			s_obj
{
	t_sphere			sphere;
	t_plane				plane;
	t_cyl				cylinder;
	t_conus				cone;
	t_vector			n;
	int					type;
	t_col				color;
	struct s_obj		*next;
}						t_obj;

typedef struct			s_inter
{
	double				t;
	t_obj				*obj;
}						t_inter;

typedef struct			s_env
{
	t_cam				*cam;
	t_obj				*obj;
	t_con				*con;
	t_light				*light;
	t_col				color;
	double				dist;
}						t_env;

/*
**		init_window.c
*/
t_con					init_window();
void					put_img_pix(void *img_ptr, int color, int x, int y);

/*
**		parser.c
*/
t_env					*parse(char *str, t_env *env);
void					help_to_parse(char *str, t_obj *obj, int i);
t_light					*create_light(char *beggin);
t_env					*get_mat_file(char *file, t_env *env);

/*
**		parse object.c
*/
t_obj					*create_sphere(char *beggin);
t_vector				skip_spaces(char *str, int i);
t_cam					*create_camera(char *beggin);
t_obj					*create_plane(char *beggin);
t_obj					*create_cylindr(char *beggin);
t_obj					*create_cone(char *beggin);

/*
**         list.c
*/
t_obj					*add_object_to_list(t_obj **full, t_obj *part);
t_obj					*add_object_cylind(t_col col, t_vector start,
						t_vector norm, double rad);
t_obj					*add_object_conus(t_col col, t_vector c,
						t_vector dir, double angle);
t_obj					*add_object_sphere(t_col col,
						t_vector cent, double rad);
t_obj					*add_object_plane(t_col col, t_vector normal,
						t_vector point);

/*
**        parse_founctions.c
*/
t_vector				find_position(char *str);
double					find_angle(char *str);
t_col					find_color_value(char *str, int i);
t_col					find_color(char *str);
t_vector				find_direction(char *str);
double					find_rad(char *str);
t_vector				find_to(char *str);

/*
**		vector.c
*/
double					len(t_vector a);
t_vector				normal(t_vector a);
t_vector				cross_product(t_vector a, t_vector b);
t_vector				increment_vector(t_vector a, double x);
double					dot(t_vector a, t_vector b);
t_vector				get_point(t_ray *ray, double t);

/*
**		keyboard.c
*/
int						keys_actions(int key, void *param);

/*
**		simple_founctions.c
*/
double					deg2rad(double deg);
t_root					find_roots(double a, double b, double c);
double					find_closest(t_root *root);

/*
**		colors.c
*/
int						rgb_to_color(t_col col);
t_col					multiply_color(t_col col, float k);
t_col					set_color(int r, int g, int b);

/*
**		find_normal.c
*/
t_vector				sphere_normal(t_sphere *sp);
t_vector				compute_normal(t_obj *obj, t_ray *ray, t_root *root);

/*
**		intersections.c
*/
t_root					intersect_sphere(t_sphere *sph, t_ray *ray);
double					intersect(t_obj *obj, t_ray *ray);
double					intersect_plane(t_plane *pl, t_ray *ray);
t_root					intersect_cylinder(t_cyl *cyl, t_ray *ray);
t_root					intersect_cone(t_conus *cone, t_ray *ray);

/*
**		raytracer.c
*/
void					raytrace(t_env *env);
int						castray(t_obj *obj, t_ray *ray, t_light *light);

/*
**		light.c
*/
double					lambert(t_light *light, t_ray *ray,
						double t, t_vector n);
t_light					*add_light(t_light **list, t_light *light);
int						calcul_lights(t_ray *ray, t_vector n, t_env *env);

/*
**		Somewhere
*/
void					print_lights(t_light *light);
t_col					add_color(t_col col, t_col col1);
double					phong(t_light *light, t_ray *ray, double t, t_vector n);
double					find_close(t_obj *obj, t_ray *ray);
int						check_file(char *file);
#endif
