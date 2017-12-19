/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm_destruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:46:31 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/12/04 09:21:48 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void		destroy_paths(t_path **path)
{
	t_path	*tmp;
	int		index;

	if (*path)
	{
		while (*path)
		{
			tmp = *path;
			*path = (*path)->next;
			index = -1;
			while (++index < tmp->numrooms)
				free(tmp->rooms[index]);
			free(tmp->rooms);
			free(tmp);
		}
	}
}

static void	destroy_ants(t_ant **ants)
{
	t_ant	*tmp;

	if (*ants)
	{
		while (*ants)
		{
			tmp = *ants;
			*ants = (*ants)->next;
			free(tmp);
		}
	}
}

static void	destroy_rooms(t_room **rooms)
{
	t_room	*tmp;
	int		index;

	if (*rooms)
	{
		while (*rooms)
		{
			tmp = *rooms;
			*rooms = (*rooms)->next;
			free(tmp->name);
			tmp->name = NULL;
			free(tmp->parent);
			tmp->parent = NULL;
			free(tmp->visitedby);
			tmp->visitedby = NULL;
			index = -1;
			while (++index < tmp->num_linked_rooms)
			{
				if (tmp->linked_rooms[index])
					free(tmp->linked_rooms[index]);
			}
			free(tmp->linked_rooms);
			free(tmp);
		}
	}
}

void		destroy_farm(t_farm **farm)
{
	if (*farm)
	{
		if ((*farm)->startroom)
			ft_strdel(&(*farm)->startroom);
		if ((*farm)->endroom)
			ft_strdel(&(*farm)->endroom);
		destroy_rooms(&(*farm)->all_rooms);
		destroy_ants(&(*farm)->ants);
		if ((*farm)->cmd)
			free((*farm)->cmd);
		if ((*farm)->queue)
			ft_clear_2d_arr((*farm)->queue);
		free(*farm);
		*farm = NULL;
	}
}
