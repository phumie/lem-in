/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:04:15 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/12/04 09:07:54 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

t_room	*get_room(t_farm **farm, char *room_name)
{
	t_room	*temp;

	temp = (*farm)->all_rooms;
	while (temp)
	{
		if (ft_strequ(temp->name, room_name))
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

char	**add_room_to_linked(char **room_list, char *new_room)
{
	int		index;

	index = 0;
	while (room_list[index] != NULL)
		index++;
	room_list[index] = ft_strdup(new_room);
	return (room_list);
}

void	add_room_to_farm(t_farm **farm, char *new_room)
{
	t_room	*temp;
	char	**split;

	split = ft_strsplit(new_room, ' ');
	temp = create_room(split[0]);
	if ((*farm)->all_rooms == NULL)
		(*farm)->all_rooms = temp;
	else
	{
		temp->next = (*farm)->all_rooms;
		(*farm)->all_rooms = temp;
	}
	(*farm)->numrooms++;
	ft_clear_2d_arr(split);
}

char	**add_to_queue(char **queue, char *str)
{
	int		index;

	index = 0;
	while (queue[index])
		index++;
	queue[index] = ft_strdup(str);
	return (queue);
}

void	add_ant_to_farm(t_ant **allants, t_ant *ant)
{
	t_ant	*tmp;

	if (!*allants)
		*allants = ant;
	else
	{
		tmp = *allants;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ant;
	}
}
