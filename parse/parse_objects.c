/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_objects.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 17:33:12 by ivork         #+#    #+#                 */
/*   Updated: 2021/05/06 20:08:43 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../libft/libft.h"
#include <stdio.h>

void	get_plane(t_scene *scene, char *str)
{
	char **info;
	t_plane *plane;

	plane = (t_plane*)malloc(sizeof(t_plane));
	if (plane == NULL)
	{
		printf("mallloc fail");
		exit(0);
	}
	info = ft_split(str + 2, ' ');
	if (info[0] == NULL || info[1] == NULL || info[2] == NULL)
	{
		printf("Error\nCould not read plane information\n");
		exit(0);
	}
	if (info[3] != NULL)
		printf("Error\nToo many arguments\n");
	plane->coordinates = get_coords(plane->coordinates, info[0]);
	plane->vector = get_coords(plane->vector, info[1]);
	if (plane->vector.x < -1 || plane->vector.x > 1)
		printf("Errfunc...........");
	if (plane->vector.y < -1 || plane->vector.y > 1)
		printf("Errfunc...........");
	if (plane->vector.z < -1 || plane->vector.z > 1)
		printf("Errfunc...........");
	plane->rgb = get_rgb(plane->rgb, info[2]);
	ft_lstadd_back(&scene->planes, ft_lstnew(plane));
	free_2d_array(info);
}

void get_sphere(t_scene *scene, char *str)
{
	char **info;
	t_sphere *sphere;

	sphere = (t_sphere*)malloc(sizeof(t_sphere));
	if (sphere == NULL)
	{
		printf("Malloc fail");
		exit(0);
	}
	info = ft_split(str + 2, ' ');
	if (info[0] == NULL || info[1] == NULL || info[2] == NULL)
	{
		printf("Error\nCould not read plane information\n");
		exit(0);
	}
	if (info[3] != NULL)
	{
		printf("Error\nToo many arguments sphere\n");
		exit(0);
	}
	sphere->coordinates = get_coords(sphere->coordinates, info[0]);
	sphere->rgb= get_rgb(sphere->rgb, info[2]);
	sphere->diameter = ft_atod(info[1]);
	ft_lstadd_back(&scene->spheres, ft_lstnew(sphere));
	free_2d_array(info);
}

void	get_square(t_scene *scene, char *str)
{
	char **info;
	t_square *square;

	square = (t_square*)malloc(sizeof(t_square));
	if (square == NULL)
	{
		printf("malloc fail");
		exit(0);
	}
	info = ft_split(str + 2, ' ');
	if (info[0] == NULL || info[1] == NULL || info[2] == NULL || info [3] == NULL)
	{
		printf("Error\nCould not read square information\n");
		exit(0);
	}
	if (info[4] != NULL)
		printf("Error\nToo many arguments square\n");
	square->coordinates = get_coords(square->coordinates, info[0]);
	square->vector=  get_coords(square->vector, info[1]);
	if (square->vector.x < -1 || square->vector.x > 1)
		printf("Errfunc...........");
	if (square->vector.y < -1 || square->vector.y > 1)
		printf("Errfunc...........");
	if (square->vector.z < -1 || square->vector.z > 1)
		printf("Errfunc...........");
	square->side = ft_atod(info[2]);
	square->rgb = get_rgb(square->rgb, info[3]);
	ft_lstadd_back(&scene->squares, ft_lstnew(square));
	free_2d_array(info);
}

void	get_cylinder(t_scene *scene, char *str)
{
	char **info;
	t_cylinder *cylinder;

	cylinder = (t_cylinder*)malloc(sizeof(t_cylinder));
	if (cylinder == NULL)
	{
		printf("malloc fail");
		exit(0);
	}
	info = ft_split(str + 2, ' ');
	if (info[0] == NULL || info[1] == NULL || info[2] == NULL || info [3] == NULL || info[4] == NULL)
	{
		printf("Error\nCould not read square information\n");
		exit(0);
	}
	if (info[5] != NULL)
		printf("Error\nToo many arguments square\n");
	cylinder->coordinates = get_coords(cylinder->coordinates, info[0]);
	cylinder->vector = get_coords(cylinder->vector, info[1]);
	if (cylinder->vector.x < -1 || cylinder->vector.x > 1)
		printf("Errfunc...........");
	if (cylinder->vector.y < -1 || cylinder->vector.y > 1)
		printf("Errfunc...........");
	if (cylinder->vector.z < -1 || cylinder->vector.z > 1)
		printf("Errfunc...........");
	cylinder->diameter = ft_atod(info[2]); // limits??????
	cylinder->height = ft_atod(info[3]);
	cylinder->rgb = get_rgb(cylinder->rgb, info[4]);
	ft_lstadd_back(&scene->cylinders, ft_lstnew(cylinder));
	free_2d_array(info);
}

void	get_triangle(t_scene *scene, char *str)
{
	char **info;
	t_triangle *triangle;

	triangle = (t_triangle*)malloc(sizeof(t_triangle));
	if (triangle == NULL)
	{
		printf("malloc fail");
		exit(0);
	}
	info = ft_split(str + 2, ' ');
	if (info[0] == NULL || info[1] == NULL || info[2] == NULL || info [3] == NULL)
	{
		printf("Error\nCould not read square information\n");
		exit(0);
	}
	if (info[4] != NULL)
		printf("Error\nToo many arguments square\n");

	triangle->coordinates1 = get_coords(triangle->coordinates1, info[0]);
	triangle->coordinates2 = get_coords(triangle->coordinates2, info[1]);
	triangle->coordinates3 = get_coords(triangle->coordinates3, info[2]);
	triangle->rgb = get_rgb(triangle->rgb, info[3]);
	ft_lstadd_back(&scene->triangles, ft_lstnew(triangle));
	free_2d_array(info);
}