#ifndef MINI_RT_H
# define MINI_RT_H
#include "libft/libft.h"

// typedef struct	s_data 
// {
// 	void		*img;
// 	char		*addr;
// 	int			bits_per_pixel;
// 	int			line_length;
// 	int			endian;
// }				t_data;

// typedef struct	s_ray
// {
// 	float		vector[3];
// }				t_ray;

typedef struct 		s_rgb
{
	int				red;
	int				green;
	int				blue;
}					t_rgb;

typedef struct		s_coordinates
{
	double			x;
	double			y;
	double			z;
}					t_coordinates;

typedef struct		s_camera
{
	t_coordinates	coordinates;
	t_coordinates	vector;
	int				FOV;
}					t_camera;

typedef struct		s_light
{
	t_coordinates	coordinates;
	t_rgb			rgb;
	double			brightness;

}					t_light;

typedef struct		s_sphere
{
	t_coordinates	coordinates;
	t_rgb			rgb;
	float			diameter;

}					t_sphere;

typedef struct		s_plane
{
	t_coordinates	coordinates;
	t_coordinates	vector;
	t_rgb			rgb;
}					t_plane;

typedef struct		s_square
{
	t_coordinates	coordinates;
	t_coordinates	vector;
	t_rgb			rgb;
	float			side;
}					t_square;

typedef struct		s_cylinder
{
	t_coordinates	coordinates;
	t_coordinates	vector;
	t_rgb			rgb;
	float			diameter;
	float			height;

}					t_cylinder;

typedef struct		s_triangle
{
	t_coordinates	coordinates1;
	t_coordinates	coordinates2;
	t_coordinates	coordinates3;
	t_rgb			rgb;
}					t_triangle;

typedef struct		s_scene
{
	int				resolution[2];
	float			ambi_light;
	t_rgb			rgb;
	t_list			*planes;
	t_list			*spheres;
	t_list			*squares;
	t_list			*cylinders;
	t_list			*triangles;
	t_list			*cameras;
	t_list			*lights;
}					t_scene;

t_scene				*parse_scene	(char *str, t_scene *scene);
t_scene				*init_scene(t_scene *scene);
t_camera			*init_camera(t_camera *camera);
void				get_resolution(t_scene *scene, char *str);
void				get_ambient(t_scene *scene, char *str);
void				get_camera(t_scene *scene, char *str);
void				get_light(t_scene *scene, char *str);
void				get_plane(t_scene *scene, char *str);
void 				get_sphere(t_scene *scene, char *str);
void				get_square(t_scene *scene, char *str);
void				get_cylinder(t_scene *scene, char *str);
void				get_triangle(t_scene *scene, char *str);
void				free_2d_array(char **str);
t_rgb				get_rgb(t_rgb rgb, char *str);
t_coordinates		get_coords(t_coordinates coordinates, char *str);
#endif