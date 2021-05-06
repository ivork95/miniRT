#include "../minirt.h"
#include "../libft/libft.h"

t_scene *init_scene(t_scene *scene)
{
	scene->resolution[0] = 0;
	scene->resolution[1] = 0;
	scene->ambi_light = -1;
	scene->rgb.red = -1;
	scene->rgb.green = -1;
	scene->rgb.blue = -1; 
	scene->cameras = NULL;
	scene->spheres = NULL;
	scene->planes = NULL;
	scene->lights = NULL;
	scene->squares = NULL;
	return (scene);
}