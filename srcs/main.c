/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotillion <tpotillion@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:43:31 by tpotilli@st       #+#    #+#             */
/*   Updated: 2023/11/06 15:26:09 by tpotillion       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[], char *env[])
{
	char	**map;
	t_game	*ptr;
	(void)argc;

	ptr = malloc(sizeof(t_game));
	ptr = init_struct(ptr);
	ptr->map = map_manager(argv, env);
	map = map_manager(argv, env);
	if (verif_map_manager(map) != 1)
	{
		free_db_tab(map);
		return (0);
	}
	/*if (verif_size_img(map, ptr) == -1)
	{
		verifier la size des images
		free_db_tab(map);
		ft_printf("wrong tile size\n");
		return (0);
	}*/
	if (game_manager(map, ptr) == -1)
	{
		free_db_tab(map);
		return (-1);
	}
	ft_printf("ptr %d ptr %d\n", ptr->p_y, ptr->p_x);
	game_start(ptr->map, ptr);
	show_db_tab(map);
	free_db_tab(map);
	return (0);
	/*if (!buff)
	{
		while (buff[i])
		{
			ft_printf("%s", buff[i]);
			i++;
		}
		return (write(1, "ERROR\n", 7), -1);
	}*/
	//parsing(argv);
}

t_game *init_struct(t_game *ptr)
{
	void	*mlx;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	ptr->i = 0;
	ptr->map = NULL;
	ptr->cpt = 0;
	ptr->x = 0;
	ptr->y = 0;
	ptr->nb_item = 0;
	ptr->nb_exit = 0;
	ptr->p_x = 0;
	ptr->p_y = 0;
	ptr->p_mov = 0;
	ptr->img_0 = mlx_xpm_file_to_image(mlx, "tiles/Wall.xpm", &img_width, &img_height);
	ptr->img_1 = mlx_xpm_file_to_image(mlx, "tiles/floor.xpm", &img_width, &img_height);
	ptr->img_2 = mlx_xpm_file_to_image(mlx, "tiles/player.xpm", &img_width, &img_height);
	ptr->img_3 = mlx_xpm_file_to_image(mlx, "tiles/exit.xpm", &img_width, &img_height);
	ptr->img_4 = mlx_xpm_file_to_image(mlx, "tiles/item.xpm", &img_width, &img_height);
	return (ptr);
}

void show_db_tab(char **map)
{
	int i = 0;
	int j = 0;
	ft_printf("la map\n");
	while (map[i])
	{
		while(map[i][j])
		{
			ft_printf("%c", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
		j = 0;
	}
	return ;
}

void free_db_tab(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return ;
}
/*
char **map_manager(char *argv[])
{
	char 	**tab;
	char	*buff;
	int		fd;
	int		Buffer_size;

	Buffer_size = 5;
	fd = open(argv[2], O_RDONLY);
	if (fd == -1)
		return (NULL);
	else
	{
		buff = calloc(5, Buffer_size);
		while (read(fd, buff, Buffer_size) > 0)
		{
			buff = calloc(5, Buffer_size);
			read(fd, buff, Buffer_size);
		}
		if (!buff)
			return (NULL);
		tab = ft_split(buff, '\n');
	}
	return (tab);
}
*/

/*char **map_manager(char *argv[])
{
	char **tmp;
	char **try;
	int i;

	i = 0;
	tmp = open(argv[2], "NULL");
	if (!tmp)
		return (pr_error("error opening file\n"));
	while (read(argv[2])try[1], )
	return (tmp);
}*/

/*

void create_window()
{
	void	*mlx;

	mlx = mlx_init();
	mlx_new_window(mlx, 1920, 1080, "42");
	mlx_loop(mlx);
}
*/
/*
	void	*mlx;

	mlx = mlx_init();
	mlx_new_window(mlx, 1920, 1080, "42");
	mlx_new_image(mlx, 1920, 1080);
	mlx_loop(mlx);
}
*/

/*int main()
{
	void *mlx;
	void *mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "42"); //pointeur, taille, taille, titre
	mlx_loop(mlx);
}
*/
