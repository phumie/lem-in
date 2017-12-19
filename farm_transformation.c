/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm_transformation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:43:59 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/12/04 10:48:38 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

static void	bfs_search(t_farm **farm)
{
	int		rooms_passed;
	int		temp_links;
	t_room	*temp_room;
	t_room	*temp_room2;

	rooms_passed = -1;
	while (++rooms_passed < (*farm)->numrooms)
	{
		temp_links = -1;
		temp_room = get_room(farm, (*farm)->queue[rooms_passed]);
		while (++temp_links < temp_room->num_linked_rooms)
		{
			if (temp_room->linked_rooms[temp_links])
			{
				temp_room2 = get_room(farm,
						temp_room->linked_rooms[temp_links]);
				if (!temp_room2->visited)
				{
					set_room(&temp_room2, temp_room);
					(*farm)->queue = add_to_queue((*farm)->queue,
							temp_room2->name);
				}
				else if (!ft_strequ(temp_room2->name, temp_room->visitedby))
					remove_both_linked((*farm)->endroom,
							&temp_room, &temp_room2);
			}
		}
	}
}

static void	cleanup_end_neighbours(t_farm **farm, t_room **end, t_room *start)
{
	t_room	*tmp;
	char	*tmp2;
	char	**linked;
	int		index;
	int		index2;

	linked = create_2d_space(start->num_linked_rooms + 1);
	index = -1;
	while (++index < start->num_linked_rooms)
	{
		tmp2 = start->linked_rooms[index];
		index2 = -1;
		if (linked_to_same_room(tmp2, *end))
			linked[index] = ft_strequ(tmp2, (*end)->name) ? start->name : tmp2;
		else
		{
			while (++index2 < (*end)->num_linked_rooms)
			{
				tmp = get_room(farm, (*end)->linked_rooms[index2]);
				if (check_ancestry(tmp, tmp2, (*farm)->numrooms))
					linked[index] = tmp->name;
			}
		}
	}
	clean_up(farm, end, linked, index);
}

void		transform_farm(t_farm **farm)
{
	t_room	*startroom;
	t_room	*endroom;

	startroom = get_room(farm, (*farm)->startroom);
	startroom->lvl = 0;
	set_room(&startroom, startroom);
	(*farm)->queue = create_2d_space((*farm)->numrooms + 1);
	(*farm)->queue = add_to_queue((*farm)->queue, startroom->name);
	bfs_search(farm);
	endroom = get_room(farm, (*farm)->endroom);
	if (!endroom->visited)
	{
		ft_putendl("Error");
		destroy_farm(farm);
		exit(0);
	}
	cleanup_end_neighbours(farm, &endroom, startroom);
	ft_putchar('\n');
}
