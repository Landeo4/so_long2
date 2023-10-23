/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:43:31 by tpotilli@st       #+#    #+#             */
/*   Updated: 2023/10/23 14:33:18 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	(void)argc;
	map_manager(argv);
	parsing(argv);
}

char **map_manager(char *argv[])
{
	
}

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
