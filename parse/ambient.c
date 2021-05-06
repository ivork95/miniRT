/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ambient.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/04 21:41:24 by ivork         #+#    #+#                 */
/*   Updated: 2021/05/06 20:31:45 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../libft/libft.h"
#include <stdio.h>

void	get_ambient(t_scene *scene, char *str)
{
	char	**arr;

	if (scene->ambi_light != -1)
	{
		printf("Error\nToo many declarations of ambient lighting\n");
		exit(0);
	}
	arr = ft_split(str + 1,  ' ');
	if (arr[0] == NULL || arr[1] == NULL)
	{
		printf("Error\nInorrect amount of arguments (Ambient lighting)\n");
		exit(0);
	}
	scene->ambi_light = ft_atod(arr[0]);
	if (scene->ambi_light == -1)
		printf("Error\nCould not get ambient lighting\n");
	scene->rgb = get_rgb(scene->rgb, arr[1]);
	free_2d_array(arr);
}