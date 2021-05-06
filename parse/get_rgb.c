/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_rgb.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 16:47:10 by ivork         #+#    #+#                 */
/*   Updated: 2021/05/06 19:40:20 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../libft/libft.h"
#include <stdio.h>

t_rgb	get_rgb(t_rgb rgb, char *str)
{
	char **info;

	info = ft_split(str, ',');
	if (info[0] == NULL || info[1] == NULL || info[2] == NULL)
	{
		printf("Error\nCould not read rgb\n");
		exit(0);
	}
	if (info[3] != NULL)
	{
		printf("Error\nToo many arguments rgb\n");
		exit(0);
	}
	rgb.red = ft_atoi(info[0]);
	if (rgb.red < 0 || rgb.red > 255)
		printf("Error\nColor out of range\n");
	rgb.green = ft_atoi(info[1]);
	if (rgb.green < 0 || rgb.green > 255)
		printf("Error\nColor out of range\n");
	rgb.blue = ft_atoi(info[2]);
	if (rgb.blue < 0 || rgb.blue > 255)
		printf("Error\nColor out of range\n");
	free_2d_array(info);
	return (rgb);
}