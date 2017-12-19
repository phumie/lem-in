/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_transportation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:45:50 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/12/04 09:09:45 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

static int	max_moves(int *dist, int num, int ants)
{
	int	max;
	int	index;

	index = 0;
	max = -2147483648;
	while (index < num)
	{
		if ((ants / num) + (dist[index] - 1) > max)
			max = (ants / num) + (dist[index] - 1);
		index++;
	}
	return (max);
}

static int	num_of_paths_to_use(t_path *paths, int numpaths, int ants, int ret)
{
	int		dist[numpaths];
	int		moves[numpaths];
	int		index;
	int		min;
	t_path	*tmp_path;

	index = 0;
	min = 2147483647;
	tmp_path = paths;
	while (tmp_path)
	{
		dist[index++] = tmp_path->numrooms - 1;
		tmp_path = tmp_path->next;
	}
	index = 0;
	while (++index <= numpaths)
		moves[index - 1] = max_moves(dist, index, ants);
	index = 0;
	while (index < numpaths)
	{
		ret = (moves[index] < min ? index : ret);
		min = (moves[index] < min ? moves[index] : min);
		index++;
	}
	return (ret + 1);
}

static void	print_ant(t_ant *ant)
{
	char	**rooms;
	int		index;
	int		index2;

	index = 0;
	index2 = ant->path->numrooms - 1;
	rooms = ant->path->rooms;
	ft_putchar('L');
	ft_putnbr(ant->ant_num);
	ft_putchar('-');
	while (index < ant->dist)
	{
		index++;
		index2--;
	}
	ft_putstr(rooms[index2]);
	ft_putchar(' ');
}

static void	create_ants(t_farm **farm, t_path *paths, int index)
{
	int		totalpaths;
	int		paths2use;
	int		pathnum;
	t_path	*tmp;
	t_ant	*ant;

	totalpaths = count_paths(get_room(farm, (*farm)->endroom));
	paths2use = num_of_paths_to_use(paths, totalpaths, (*farm)->antsnum, 0);
	while (index++ < (*farm)->antsnum)
	{
		tmp = paths;
		pathnum = index % paths2use;
		ant = create_ant(index, pathnum ? pathnum : paths2use);
		while (ant->path_num-- > 1)
			tmp = tmp->next;
		ant->path = tmp;
		ant->to_move = (index / paths2use) + (index % paths2use ? 1 : 0);
		add_ant_to_farm(&(*farm)->ants, ant);
	}
}

void		move_ants(t_farm **farm, t_path *paths)
{
	int		round;
	int		did_they_move;
	t_ant	*ants;

	round = 1;
	create_ants(farm, paths, 0);
	while ((*farm)->antsnum)
	{
		ants = (*farm)->ants;
		did_they_move = 0;
		while (ants)
		{
			if (ants->to_move <= round && ants->dist < ants->path->numrooms)
			{
				print_ant(ants);
				ants->dist++;
				did_they_move++;
			}
			ants = ants->next;
		}
		if (!did_they_move)
			break ;
		ft_putchar('\n');
		round++;
	}
}
