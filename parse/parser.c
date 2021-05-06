#include "../minirt.h"
#include "../libft/libft.h"
#include <stdio.h>

t_scene	*parse_scene(char *str, t_scene *scene)
{	
	if (ft_strncmp(str, "R ", 2) == 0)
		get_resolution(scene, str);
	if (ft_strncmp(str, "A ", 2) == 0)
		get_ambient(scene, str);
	if (ft_strncmp(str, "c ", 2) == 0)
		get_camera(scene, str);
	if (ft_strncmp(str, "l ", 2) == 0)
		get_light(scene, str);
	if (ft_strncmp(str, "pl ", 3) == 0)
		get_plane(scene, str);
	if (ft_strncmp(str, "sp ", 3) == 0)
		get_sphere(scene, str);
	if (ft_strncmp(str, "sq ", 3) == 0)
		get_square(scene, str);
	if (ft_strncmp(str, "cy ", 3) == 0)
		get_cylinder(scene, str);
	if (ft_strncmp(str, "tr ", 3) == 0)
		get_triangle(scene, str);
	return (scene);
}