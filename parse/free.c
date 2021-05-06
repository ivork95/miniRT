/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/06 18:02:51 by ivork         #+#    #+#                 */
/*   Updated: 2021/05/06 19:40:02 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
void	free_2d_array(char **str)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (str[i] != NULL)
		i++;
	while (n < i)
	{
		free(str[n]);
		n++;
	}
	free(str);
	return ;
}