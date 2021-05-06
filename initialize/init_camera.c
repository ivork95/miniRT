/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_camera.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/04 22:25:05 by ivork         #+#    #+#                 */
/*   Updated: 2021/05/05 14:56:18 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../libft/libft.h"

t_camera	*init_camera(t_camera *camera)
{
	camera->coordinates.x = 0;
	camera->coordinates.y = 0;
	camera->coordinates.z = 0;
	camera->vector.x = 0;
	camera->vector.y = 0;
	camera->vector.z = 0;
	camera->FOV = -1;
	return (camera);
}