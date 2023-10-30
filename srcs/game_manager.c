/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:18:32 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/30 18:18:13 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int game_manager(char **map, t_game *ptr)
{
	// int		tk_e;
	// int		tk_i;
	// int		cpt_collect;
	char		**tmp;

	// tk_e = 1;
	// tk_i = 0;
	// cpt_collect = nb_other(map);
	ptr = player_pos(map, ptr);
	if (ptr->p_x == -1)
		return (-1);
	tmp = cpy_map(map);
	show_db_tab(tmp);
	/*while ()
	{
		
	}*/
	free_db_tab(tmp);
	return (0);
}

t_game *player_pos(char **map, t_game *ptr)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				ptr->p_x = j;
				ptr->p_y = i;
				return (ptr);
			}
			j++;
		}
		j = 0;
		i++;
	}
	ptr->p_x = -1;
	return (ptr);
}

/*int nb_other(char **map)
{
	
}*/

char **cpy_map(char **map)
{
	int		i;
	int		j;
	int		len;
	char	**tmp;

	i = 0;
	len = 0;
	while (map[i])
	{
		i++;
		len++;
	}
	i = 0;
	tmp = malloc(sizeof (char *) * len + 1);
	if (!tmp)
		return (NULL);
	while (map[i])
	{
		tmp[i] = malloc(sizeof(char) * (ft_strlen(map[i]) + 1));
		if (!tmp[i])
			return (NULL);
		j = 0;
		while (map[i][j])
		{
			tmp[i][j] = map[i][j];
			j++;
		}
		tmp[i][j] = '\0';
		i++;
	}
	return (tmp);
}

/*char **map_creator(char **map)
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
}*/

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