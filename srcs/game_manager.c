/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:18:32 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/30 13:45:30 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int game_manager(char **map)
{
	char **map_lit;

	map_lit = map_creator(map);
}

char **map_creator(char **map)
{
	char	**lit_map;
	int		i;
	int		j;

	j = 0;
	i = 0;
	lit_map = malloc(sizeof(char *) * ft_strlen(map[i]));
	while (map[i])
	{
		while (map[i][j])
		{
			lit_map[i][j] = map[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (lit_map);
}

/*
int game_manager(char **map)
{
	void	*mlx;
	void	*img;
	char	*relative_path = "./";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	mlx_new_window(mlx, 1920, 1080, "42");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
}
*/