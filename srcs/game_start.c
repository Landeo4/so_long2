/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:29:03 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/04 16:24:38 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int game_start(char **map, t_game *ptr)
{
	(void)ptr;
	void	*mlx;

	mlx = mlx_init();
	create_map(map, mlx);
	return (0);
}

int create_map(char **map, void *mlx)
{
	int		i;
	int		j;
	void	*mlx_win;
	
	i = 0;
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (put_image(map, mlx_win, i, j, mlx) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
	return (0);
}

int put_image(char **map, void *mlx_win, int i, int j, void *mlx)
{
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;

	if (map[i][j] == '1')
		relative_path = "tiles/Wall.xpm";
	else if (map[i][j] == '0')
		relative_path = "tiles/floor.xpm";
	else if (map[i][j] == 'P')
		relative_path = "tiles/player.xpm";
	else if (map[i][j] == 'E')
		relative_path = "tiles/exit.xpm";
	else if (map[i][j] == 'C')
		relative_path = "tiles/item.xpm";
	if (mlx_win == NULL)
		return (-1);
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (img == NULL)
		return (-1);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
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
