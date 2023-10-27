/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:40:15 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/27 18:26:18 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

 char **get_map(char *tmp)
 {
	char	**map;
	char	*buf;
	int		fd;
	ssize_t	byte;

	(void)map;
	buf = malloc(sizeof(char) * 500);
	if (!buf)
		return (NULL);
	buf = ft_memset(buf, 0, 500);
	fd = open(tmp, O_RDONLY);
	if (fd == -1)
	{
		free(buf);
		pr_error("mauvais fd\n");
		return (NULL);
	}
	byte = read(fd, buf, 499);
	if (byte == -1)
		ft_printf("problem\n");
	else
		buf[byte] = '\0';
	map = ft_split(buf, '\n');
	free(buf);
	return (map);
}

int verif_map_manager(char **map)
{
	if (verif_square(map) == -1)
	{
		free(map);
		return (pr_error("map is not a square\n"));
	}
	if (verif_map_outline(map) == -1)
	{
		free(map);
		return (pr_error("wrong_map_outline\n"));
	}
	/*if (verif_map_item_esc(map) == -1)
	{
		free(map);
		return (pr_error("missing_item_or_escape\n"))
	}
	if (verif_play(map) == -1)
	{
		free(map);
		return (pr_error("missing_player\n"))
	}*/
	return (1);
}

int verif_square(char **map)
{
	int i;
	int	tk;
	int jt;

	i = 0;
	tk = 0;
	jt = 0;
	while (map[i] && map[i + 1])
	{
		tk = ft_strlen(map[i]);
		jt = ft_strlen(map[i + 1]);
		if (tk != jt)
			return (-1);
		i++;
	}
	return (0);
}

int verif_map_outline(char **map)
{
	int		i;
	int		tk_l;
	int		tk_f;

	if (map_out_help(map) == -1)
	{
		ft_printf("wrong first line or last\n");
		return (-1);
	}
	i = 1;
	tk_f = 0;
	tk_l = 0;
	if (verif_map_middle(map, i ,tk_f, tk_l) == -1)
		return (-1);
	return (0);
}

int verif_map_middle(char **map, int i, int tk_f, int tk_l)
{
	int j;

	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 1)
				return (-1);
			j++;
		}
		if (map[i][0] == 1)
			tk_f = 1;
		if (map[i][j] == 1)
			tk_l = 1;
		if (tk_l != 1 && tk_f != 1)
			return (-1);
		i++;
		j = 0;
		tk_l = 0;
		tk_f = 0;
	}
	return (0);
}

/*int verif_map_outline(char **map)
{
	int		last;
	int		first;
	int		i;
	int		tk_l;
	int		tk_f;

	if (map_out_help(map) == -1)
		return (-1);
	i = 1;
	first = 0;
	last = ft_strlen(map[i]);
	tk_f = 0;
	tk_l = 0;
	while (map[i])
	{
		if (map[i][0] == 1)
			tk_f = 1;
		if (map[i][last] == 1)
			tk_l = 1;
		if (tk_l != 1 && tk_f != 1)
			return (-1);
		while (map[i][j])
		{
			
		}
	}
	return (0);
}*/

int map_out_help(char **map)
{
	int	i;
	int	last;

	i = 0;
	last = ft_strlen(map[i]);
	ft_printf("map %s\n", map[0]);
	while (map[0])
	{
		if (map[0][i] != '1')
		{
			ft_printf("first %c\n", map[0][i]);
			return (-1);
		}
		i++;
	}
	i = 0;
	while (map[last])
	{
		if (map[last][i] != '1')
			return (-1);
		i++;
	}
	return (0);
}
