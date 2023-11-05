/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:29:03 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/05 13:58:37 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int game_start(char **map, t_game *ptr)
{

	ptr->mlx = mlx_init();
	create_map(map, ptr);
	return (0);
}

int create_map(char **map, t_game *ptr)
{
	int		i;
	int		j;
	int		width;
	int		height;

	i = 0;
	height = ft_len_db_tab(map);
	width = ft_strlen(map[i]);
	(void)width;
	(void)height;
	ft_printf("wi %d\n", width);
	ft_printf("wi %d\n", height);
	ptr->win = mlx_new_window(ptr->mlx, ((width) * 16), ((height) * 16), "Hello world!");
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
	mlx_loop(ptr->mlx);
	return (0);
}

int put_image(char **map, t_game *ptr, int *i, int *j)
{
	if (map[*i][*j] == '1')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img_0, (*i) * 16, (*j) * 16);
	else if (map[*i][*j] == '0')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img_1, (*i) * 16, (*j) * 16);
	else if (map[*i][*j] == 'P')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img_2, (*i) * 16, (*j) * 16);
	else if (map[*i][*j] == 'E')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img_3, (*i) * 16, (*j) * 16);
	else if (map[*i][*j] == 'C')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img_4, (*i) * 16, (*j) * 16);
	return (0);
}

/*void game_start(char **map, t_game *ptr)
{
	(void)map;
	(void)ptr;
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}*/

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/*vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close_windows, &vars);
	mlx_loop(vars.mlx);*/

int	close_windows(t_game *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}
