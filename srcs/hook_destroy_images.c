/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_destroy_images.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:07:13 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/06 11:12:38 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_windows_mouse(int keycode, t_game *vars, char **map)
{
	int i;
	int j;

	if (keycode == 1)
	{
		i = 0;
		while (map[i])
		{
			j = 0;
			while (map[i][j])
			{
				mlx_destroy_window(vars->mlx, vars->win);
				j++;
			}
			i++;
		}
		exit(0);
	}
	printf("Hello from mouse_hook!\n");
	return (0);
}

int	close_windows_esc(int keycode, t_game *vars, char **map)
{
	int i;
	int j;

	if (keycode == 65307)
	{
		i = 0;
		while (map[i])
		{
			j = 0;
			while (map[i][j])
			{
				mlx_destroy_window(vars->mlx, vars->win);
				j++;
			}
			i++;
		}
		exit(0);
	}
	return (0);
}
