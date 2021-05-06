/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/04 21:43:19 by ivork         #+#    #+#                 */
/*   Updated: 2021/05/06 19:58:00 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../libft/libft.h"
#include <stdio.h>

void	get_camera(t_scene *scene, char *str)
{
	char **info;
	t_camera *camera;

	camera = (t_camera*)malloc(sizeof(t_camera));
	if (camera == NULL)
		exit(0); // exit>??
	init_camera(camera);
	info = ft_split(str + 1, ' ');
	if (info[0] == NULL || info[1] == NULL || info[2] == NULL)
	{
		printf("Error\nCould not read camera information\n");
		exit(0);
	}
	if (info[3] != NULL)
		printf("Error\nToo many arguments\n");
	camera->coordinates = get_coords(camera->coordinates, info[0]);
	camera->vector = get_coords(camera->vector, info[1]);
	if (camera->vector.x < -1 || camera->vector.x > 1)
		printf("Errfunc...........");
	if (camera->vector.y < -1 || camera->vector.y > 1)
		printf("Errfunc...........");
	if (camera->vector.z < -1 || camera->vector.z > 1)
		printf("Errfunc...........");
	camera->FOV = ft_atoi(info[2]);
	if (camera->FOV < 0 || camera->FOV > 180)
	{
		printf("Error\nField of view out of scope");
		exit(0);
	}
	// if(scene->cameras == NULL)
	// 	scene->cameras = ft_lstnew(camera);
	// else
	ft_lstadd_back(&scene->cameras, ft_lstnew(camera));
	free_2d_array(info);
}