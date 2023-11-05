/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:29:03 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/05 17:55:28 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int game_start(char **map, t_game *ptr)
{
	ptr->mlx = mlx_init();
	create_map(map, ptr);
	//player_movement(map, ptr);
	// mlx_mouse_hook(ptr->win, mouse_hook, &ptr);
	mlx_hook(ptr->win, 2, 1L<<0, close_windows, &ptr);
	mlx_loop(ptr->mlx);
	return (0);
}

int	close_windows(int keycode, t_game *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	printf("Hello from key_hook!\n");
	return (0);
}

int	mouse_hook(int keycode, t_game *vars)
{
	if (keycode == 1)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	printf("Hello from mouse_hook!\n");
	return (0);
}

/*void player_movement(char **map, t_game *ptr)
{
	int		y;
	int		x;

	mlx_key_hook(ptr->win, key_hook, &ptr);
	if ()
}*/

/*int	key_hook(int keycode, t_game *ptr)
{
	printf("Hello from key_hook!\n");
	mlx_destroy_window(ptr->mlx, ptr->win);
	return (0);
}*/

int create_map(char **map, t_game *ptr)
{
	int		i;
	int		j;
	int		width;
	int		height;

	i = 0;
	height = ft_len_db_tab(map);
	width = ft_strlen(map[i]);
	ptr->win = mlx_new_window(ptr->mlx, ((width) * 16), ((height) * 16), "Hello world!");
	// ptr->win = mlx_new_window(ptr->mlx, 500, 500, "Hello world!");
	if (ptr->win == NULL)
		return (-1);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (put_image(map, ptr, &i, &j) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int put_image(char **map, t_game *ptr, int *i, int *j)
{
	if (map[*i] && map[*i][*j] == '1')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img_0, (*j) * 16, (*i) * 16);
	else if (map[*i] && map[*i][*j] == '0')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img_1, (*j) * 16, (*i) * 16);
	else if (map[*i] && map[*i][*j] == 'P')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img_2, (*j) * 16, (*i) * 16);
	else if (map[*i] && map[*i][*j] == 'E')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img_3, (*j) * 16, (*i) * 16);
	else if (map[*i] && map[*i][*j] == 'C')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img_4, (*j) * 16, (*i) * 16);
	return (0);
}
