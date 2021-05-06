/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   light.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 15:55:37 by ivork         #+#    #+#                 */
/*   Updated: 2021/05/06 20:05:07 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../libft/libft.h"
#include <stdio.h>

void	get_light(t_scene *scene, char *str)
{
	char **info;
	t_light *light;

	light = (t_light*)malloc(sizeof(t_light));
	if (light == NULL)
		exit(0);
	info = ft_split(str + 1, ' ');
	if (info[0] == NULL || info[1] == NULL || info[2] == NULL)
	{
		printf("Error\nCould not read light information\n");
		exit(0);
	}
	light->coordinates = get_coords(light->coordinates, info[0]);
	light->rgb = get_rgb(light->rgb, info[2]);
	light->brightness = ft_atod(info[1]);
	if (light->brightness < 0 || light->brightness > 1)
	{
		printf("Error234\n");
		exit(0);
	}
	ft_lstadd_back(&scene->lights, ft_lstnew(light));
	free_2d_array(info);
}