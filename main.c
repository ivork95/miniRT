/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 15:20:44 by ivork         #+#    #+#                 */
/*   Updated: 2021/05/06 20:17:16 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <mlx.h>
#include "minirt.h"
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"


// void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
//     char    *dst;

//     dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//     *(unsigned int*)dst = color;
// }

int             main(int argc, char **argv)
{
    // void    *mlx;
    // void    *mlx_win;
    // t_data  img;
	int fd;
	char *str;
	t_scene *scene;
	t_camera *camera;
	t_camera *camera2;
	t_light *light;
	t_light *light2;
	t_plane *plane;
	t_sphere *sphere;
	t_square *square;
	t_square *square2;
	t_cylinder *cylinder;
	t_triangle *triangle;
	t_triangle *triangle2;
	write(1, "testmain\n", 9);
	scene = (t_scene*)malloc(sizeof(t_scene));
	if (scene == NULL)
		return (-1); // ERROR CODE
	init_scene(scene);
	if (argc != 2)
	{
		printf("Error\nIncorrect amount of arguments ");
		return (0);
	}	
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Failed to  open  file\n");
	}
	while (get_next_line(fd, &str))
		scene = parse_scene(str, scene);

	camera = scene->cameras->content;
	camera2 = scene->cameras->next->content;
	write(1, "testmain2\n", 10);
	light = scene->lights->content;
	light2 = scene->lights->next->content;
	write(1, "testmain3\n", 10);
	plane = scene->planes->content;
	write(1, "testmain4\n", 10);
	sphere = scene->spheres->content;
	write(1, "testmain5\n", 10);
	square =  scene->squares->content;
	square2 =  scene->squares->next->content;
	write(1, "testmain6\n", 10);
	cylinder = scene->cylinders->content;
	write(1, "testmain7\n", 10);
	triangle = scene->triangles->content;
	triangle2 = scene->triangles->next->content;
	write(1, "testmain8\n", 10);


	printf("R  %d %d\n", scene->resolution[0], scene->resolution[1]);
	printf("A  %f  %d,%d,%d\n", scene->ambi_light, scene->rgb.red, scene->rgb.green, scene->rgb.blue);
	printf("C %f,%f,%f", camera->coordinates.x, camera->coordinates.y, camera->coordinates.z);
	printf("       %f,%f,%f", camera->vector.x, camera->vector.y, camera->vector.z);
	printf("   %d\n", camera->FOV);
	printf("C2 %f,%f,%f\n", camera2->coordinates.x, camera2->coordinates.y, camera2->coordinates.z);
	printf("l %f,%f,%f     %f        %d,%d,%d\n", light->coordinates.x, light->coordinates.y, light->coordinates.z,
	light->brightness, light->rgb.red, light->rgb.green, light->rgb.blue);
	printf("l2 %f,%f,%f     %f        %d,%d,%d\n", light2->coordinates.x, light2->coordinates.y, light2->coordinates.z,
	light2->brightness, light2->rgb.red, light2->rgb.green, light2->rgb.blue);
	printf("pl %f,%f,%f     %f,%f,%f   %d,%d,%d\n", plane->coordinates.x, plane->coordinates.y, plane->coordinates.z,
	plane->vector.x, plane->vector.y, plane->vector.z, plane->rgb.red, plane->rgb.green, plane->rgb.blue);
	printf("sp %f,%f,%f     %f   %d,%d,%d\n", sphere->coordinates.x, sphere->coordinates.y, sphere->coordinates.z,
	sphere->diameter, sphere->rgb.red, sphere->rgb.green, sphere->rgb.blue);
	printf("sq %f,%f,%f     %f,%f,%f    %f  %d,%d,%d\n", square->coordinates.x, square->coordinates.y, square->coordinates.z,
	square->vector.x, square->vector.y, square->vector.z, square->side,  square->rgb.red, square->rgb.green, square->rgb.blue);
	printf("sq2 %f,%f,%f     %f,%f,%f    %f  %d,%d,%d\n", square2->coordinates.x, square2->coordinates.y, square2->coordinates.z,
	square2->vector.x, square2->vector.y, square2->vector.z, square2->side,  square2->rgb.red, square2->rgb.green, square2->rgb.blue);
	printf("cy %f,%f,%f     %f,%f,%f    %f  %f  %d,%d,%d\n", cylinder->coordinates.x, cylinder->coordinates.y, cylinder->coordinates.z,
	cylinder->vector.x, cylinder->vector.y, cylinder->vector.z, cylinder->diameter, cylinder->height, 
	cylinder->rgb.red, cylinder->rgb.green, cylinder->rgb.blue);
	printf("tr %f,%f,%f     %f,%f,%f %f,%f,%f  %d,%d,%d\n", triangle->coordinates1.x, triangle->coordinates1.y, triangle->coordinates1.z, triangle->coordinates2.x, triangle->coordinates2.y, triangle->coordinates2.z,
	triangle->coordinates3.x, triangle->coordinates3.y, triangle->coordinates3.z, triangle->rgb.red, triangle->rgb.green, triangle->rgb.blue);
	printf("tr2 %f,%f,%f     %f,%f,%f %f,%f,%f  %d,%d,%d\n", triangle2->coordinates1.x, triangle2->coordinates1.y, triangle2->coordinates1.z, triangle2->coordinates2.x, triangle2->coordinates2.y, triangle2->coordinates2.z,
	triangle2->coordinates3.x, triangle2->coordinates3.y, triangle2->coordinates3.z, triangle2->rgb.red, triangle2->rgb.green, triangle2->rgb.blue);

	// mlx = mlx_init();
    // mlx_win = mlx_new_window(mlx, 500, 500, "MiniRT");
    // img.img = mlx_new_image(mlx, 500, 500);
    // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 250, 250, 0x0000FF);
    // mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    // mlx_loop(mlx);
	// free(camera);
	// free(light);
	// free(plane);
	// free(sphere);
	// free(scene);
}