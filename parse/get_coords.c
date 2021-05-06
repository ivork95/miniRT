/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_coords.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 16:58:19 by ivork         #+#    #+#                 */
/*   Updated: 2021/05/06 19:39:19 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../libft/libft.h"
#include <stdio.h>

t_coordinates	get_coords(t_coordinates coordinates, char *str)
{
	char **info;

	info = ft_split(str, ',');
	if (info[0] == NULL || info[1] == NULL || info[2] == NULL)
	{
		printf("Error\nCould not read camera coordinates\n");
		exit(0);
	}
	if (info[3] != NULL)
	{
		printf("Error\nToo may arguments camera coordinates\n");
		exit(0);
	}
	coordinates.x = ft_atod(info[0]);
	coordinates.y = ft_atod(info[1]);
	coordinates.z = ft_atod(info[2]);
	free_2d_array(info);
	return (coordinates);
}