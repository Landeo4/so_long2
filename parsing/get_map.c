/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:10:13 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/25 18:00:32 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **map_manager(char *argv[], char *env[])
{
	char	*tmp;
	char	*map;
	char	**final_map;
	int		lenght;

	tmp = ft_get_path(env);
	if (!tmp)
		return (NULL);
	lenght = get_lenght(tmp, argv);
	map = malloc(sizeof(char) * lenght);
	final_map = ft_split(map, '\n');
	return (final_map);
}

int	get_lenght(char *tmp, char *argv[])
{
	int		i;
	int		j;
	char	*path;
	int		fd;
	int		lenght;

	i = 4;
	lenght = ft_strlen(argv[1]);
	fd = ft_strlen(tmp) - 4;
	fd = fd + lenght;
	ft_printf("fd %d lenght %d\n", fd, lenght);
	ft_printf("argv %s\ntmp %s\n", argv[1], tmp);
	path = malloc(sizeof(char)* (fd  + 1));
	while (tmp[i])
	{
		path[j] = tmp[i];
		i++;
		j++;
	}
	i = 0;
	path[j] = '/';
	j++;
	while (argv[1][i])
	{
		path[j] = argv[1][i];
		j++;
		i++;
	}
	path[j] = '\0';
	free(tmp);
	ft_printf("path: %s", path);
	fd = open(path, O_RDONLY);
	read(fd, path, O_RDONLY);
	return (lenght);
}

char	*ft_get_path(char **env)
{
	int		i;
	char	*path;
	char	*dos;
	int		j;

	i = 0;
	j = 0;
	while (ft_strncmp(env[i], "PWD", 3) != 0)
		i++;
	dos = "/maps";
	path = malloc(sizeof(char) * ft_strlen(env[i]) + 6);
	while (env[i][j])
	{
		path[j] = env[i][j];
		j++;
	}
	i = 0;
	while (dos[i])
	{
		path[j] = dos[i];
		i++;
		j++;
	}
	return (path);
}

char *str_join_free(char *path, char *cmd)
{
	char *str;
	
	str = ft_strjoin(path, cmd);
	free(path);
	return (str);
}
