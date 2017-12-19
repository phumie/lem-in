/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:46:31 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/12/04 09:38:09 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void	set_room(t_room **r1, t_room *r2)
{
	(*r1)->lvl = (ft_strequ(r2->name, (*r1)->name)) ? 0 : r2->lvl + 1;
	(*r1)->visitedby = ft_strdup(r2->name);
	(*r1)->visited = 1;
	if ((*r1)->lvl == 0 || (*r1)->lvl == 2)
		(*r1)->parent = ft_strdup(r2->name);
	else
		(*r1)->parent = ft_strdup(r2->parent);
}

void	remove_one_link(t_room **r1, t_room *r2)
{
	int index;

	index = -1;
	while (++index < (*r1)->num_linked_rooms)
	{
		if ((*r1)->linked_rooms[index])
		{
			if (ft_strequ((*r1)->linked_rooms[index], r2->name))
			{
				free((*r1)->linked_rooms[index]);
				(*r1)->linked_rooms[index] = NULL;
				break ;
			}
		}
	}
}

void	remove_both_linked(char *endroom, t_room **r1, t_room **r2)
{
	if (!ft_strequ(endroom, (*r1)->name) && !ft_strequ(endroom, (*r2)->name))
	{
		remove_one_link(r1, *r2);
		remove_one_link(r2, *r1);
	}
}

int		linked_to_same_room(char *room, t_room *end)
{
	int ind;

	ind = 0;
	if (ft_strequ(room, end->name))
		return (1);
	while (ind < end->num_linked_rooms)
	{
		if (end->linked_rooms[ind] && ft_strequ(room, end->linked_rooms[ind]))
			return (1);
		ind++;
	}
	return (0);
}

int		check_ancestry(t_room *temp, char *str, int min_lvl)
{
	if (ft_strequ(temp->parent, str))
	{
		if (temp->lvl < min_lvl)
		{
			min_lvl = temp->lvl;
			return (1);
		}
	}
	return (0);
}
