/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:43:31 by tpotilli@st       #+#    #+#             */
/*   Updated: 2023/10/25 17:25:20 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[], char *env[])
{
	map_manager(argv, env);
	(void)argc;
	/*ft_printf("argv[1] %s\n", argv[1]);
	if (!buff)
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
