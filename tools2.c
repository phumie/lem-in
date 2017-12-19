/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:46:31 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/12/04 09:42:00 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void	clean_up(t_farm **farm, t_room **end, char **rooms, int n)
{
	t_room	*tmp;
	int		index;
	int		index2;
	int		found;

	index = -1;
	while (++index < (*end)->num_linked_rooms)
	{
		index2 = -1;
		found = 0;
		tmp = get_room(farm, (*end)->linked_rooms[index]);
		while (++index2 < n)
		{
			if (rooms[index2])
				found += (ft_strequ(rooms[index2], tmp->name)) ? 1 : 0;
		}
		if (!found)
		{
			remove_one_link(end, tmp);
			remove_one_link(&tmp, *end);
		}
	}
	free(rooms);
}

int		count_paths(t_room *end)
{
	int		paths;
	int		index;

	paths = 0;
	index = 0;
	while (index < end->num_linked_rooms)
	{
		if (end->linked_rooms[index])
			paths++;
		index++;
	}
	return (paths);
}
