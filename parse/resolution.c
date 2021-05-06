/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   resolution.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/04 21:36:51 by ivork         #+#    #+#                 */
/*   Updated: 2021/05/06 20:32:05 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../minirt.h"
#include "../libft/libft.h"


void	get_resolution(t_scene *scene, char *str)
{
	char **arr;
	if (scene->resolution[0] != 0 || scene->resolution[1] != 0)
	{
		printf("Too many declarations of resolution\n");
		exit(0);
	}
	arr = ft_split(str + 1, ' ');
	scene->resolution[0] = ft_atoi(arr[0]);
	if (scene->resolution[0] == 0)
		printf("Error\nCould not get Resolution\n");
	scene->resolution[1] = ft_atoi(arr[1]);
	if (scene->resolution[1] == 0)
		printf("Error\nCould not get Resolution\n");
	if (arr[2] != NULL)
		printf("Error\nToo many arguments (Resolution)\n");
	free_2d_array(arr);
}