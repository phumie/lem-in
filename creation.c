/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 09:14:17 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/12/04 09:14:23 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

char	**create_2d_space(int rooms)
{
	char	**linked_rooms;
	int		index;

	index = 0;
	if ((linked_rooms = (char**)malloc(sizeof(char*) * (rooms))) == NULL)
		return (NULL);
	while (index < rooms)
		linked_rooms[index++] = NULL;
	return (linked_rooms);
}

t_room	*create_room(char *name)
{
	t_room	*new_room;

	if ((new_room = (t_room*)malloc(sizeof(t_room))) == NULL)
		return (NULL);
	new_room->name = ft_strdup(name);
	new_room->linked_rooms = NULL;
	new_room->visited = 0;
	new_room->lvl = 0;
	new_room->visitedby = NULL;
	new_room->parent = NULL;
	new_room->next = NULL;
	new_room->ants = NULL;
	new_room->num_linked_rooms = 0;
	return (new_room);
}

t_farm	*create_farm(int number_of_ants)
{
	t_farm	*new_farm;

	if ((new_farm = (t_farm*)malloc(sizeof(t_room))) == NULL)
		return (NULL);
	new_farm->antsnum = number_of_ants;
	new_farm->numrooms = 0;
	new_farm->all_rooms = NULL;
	new_farm->endroom = NULL;
	new_farm->startroom = NULL;
	new_farm->cmd = NULL;
	new_farm->ants = NULL;
	new_farm->queue = NULL;
	return (new_farm);
}

void	create_link(t_farm **farm, char *line)
{
	t_room	*room1;
	t_room	*room2;
	char	**temp;

	temp = ft_strsplit(line, '-');
	room1 = get_room(farm, temp[0]);
	room2 = get_room(farm, temp[1]);
	if (room1 == NULL || room2 == NULL)
		error_exit("Invalid map. Invalid link found.", farm, NULL, line);
	if (room1->linked_rooms == NULL)
	{
		if (!(room1->linked_rooms = create_2d_space((*farm)->numrooms)))
			error_exit("Mem allocation failed.", farm, NULL, line);
	}
	if (room2->linked_rooms == NULL)
	{
		if (!(room2->linked_rooms = create_2d_space((*farm)->numrooms)))
			error_exit("Mem allocation failed.", farm, NULL, line);
	}
	room1->linked_rooms = add_room_to_linked(room1->linked_rooms, room2->name);
	room2->linked_rooms = add_room_to_linked(room2->linked_rooms, room1->name);
	room1->num_linked_rooms++;
	room2->num_linked_rooms++;
	ft_clear_2d_arr(temp);
}
