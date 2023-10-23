/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:40:15 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/23 14:14:46 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool verif_map_outline(char *argv[])
{
	int i;
	int	j;

	j = 0;
	i = 0;
	while (argv[i])
	{
		if (argv[i][j] != 1)
			return (pr_error("map is wrong"));
		else
			while (argv[i][j])
			{
				if (argv[i][j] != 0)
					return (pr_error("map is wrong"));
				j++;
			}
		j = 0;
		i++;
	}
	return (0);
}
