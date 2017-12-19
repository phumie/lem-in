/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 09:32:49 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/12/04 09:33:49 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void	manage_commands(char *line, t_farm **farm)
{
	char	**split;

	split = ft_strsplit(line, ' ');
	if (ft_strcmp((*farm)->cmd, "##start") == 0)
	{
		if ((*farm)->startroom != NULL)
			free((*farm)->startroom);
		(*farm)->startroom = ft_strdup(split[0]);
	}
	else
	{
		if ((*farm)->endroom != NULL)
			free((*farm)->endroom);
		(*farm)->endroom = ft_strdup(split[0]);
	}
	free((*farm)->cmd);
	(*farm)->cmd = NULL;
	ft_clear_2d_arr(split);
}

int		manage_rooms(char *line, char *temp_line, t_farm **farm, int stage)
{
	if (stage != 2)
		error_exit("Error", farm, line, temp_line);
	else
	{
		if ((*farm)->cmd != NULL)
			manage_commands(temp_line, farm);
		add_room_to_farm(farm, temp_line);
	}
	return (stage);
}

int		manage_links(char *line, char *temp_line, t_farm **farm, int stage)
{
	stage = ((*farm)->startroom && (*farm)->endroom) ? 3 : 2;
	if (stage != 3)
		error_exit("Error", farm, line, temp_line);
	else
		create_link(farm, temp_line);
	return (stage);
}
