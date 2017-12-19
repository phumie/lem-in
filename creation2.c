/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:20:30 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/12/04 09:14:59 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

t_ant		*create_ant(int num, int p_num)
{
	t_ant	*ant;

	if (!(ant = (t_ant*)malloc(sizeof(t_ant))))
		return (NULL);
	ant->ant_num = num;
	ant->path_num = p_num;
	ant->path = NULL;
	ant->to_move = 0;
	ant->dist = 1;
	ant->next = NULL;
	return (ant);
}
