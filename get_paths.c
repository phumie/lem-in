/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:46:31 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/12/04 09:31:50 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

t_path		*create_path(int n_rooms, char *end)
{
	t_path	*path;

	if (!(path = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	path->numrooms = n_rooms;
	path->rooms = create_2d_space(n_rooms);
	path->rooms = add_room_to_linked(path->rooms, end);
	path->next = NULL;
	return (path);
}

void		add_to_paths(t_path **allpaths, t_path *a_path)
{
	a_path->next = *allpaths;
	*allpaths = a_path;
}

void		get_paths(t_farm *farm, t_path **all_paths)
{
	t_room	*room;
	t_path	*a_path;
	char	**linked;
	int		index;
	int		index2;

	linked = get_room(&farm, farm->endroom)->linked_rooms;
	index = -1;
	while (++index < get_room(&farm, farm->endroom)->num_linked_rooms)
		if ((room = get_room(&farm, linked[index])))
		{
			a_path = create_path(room->lvl + 2, farm->endroom);
			index2 = room->lvl;
			while (index2-- > 0)
			{
				a_path->rooms = add_room_to_linked(a_path->rooms, room->name);
				room = get_room(&farm, room->visitedby);
			}
			a_path->rooms = add_room_to_linked(a_path->rooms, farm->startroom);
			if (!*all_paths)
				*all_paths = a_path;
			else
				add_to_paths(all_paths, a_path);
		}
}
