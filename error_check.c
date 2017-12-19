/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:35:17 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/12/04 09:19:34 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

int		checknum(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}

int		is_comment(char *line)
{
	if (line[0] == '#' && line[1] != '#')
		return (1);
	else
		return (0);
}

int		is_command(char *line)
{
	if (line[0] == '#' && line[1] == '#')
		return (1);
	else
		return (0);
}

int		is_room(char *line)
{
	char	**temp;
	int		items;

	items = 0;
	temp = ft_strsplit(line, ' ');
	while (temp[items])
		items++;
	if (items != 3)
	{
		ft_clear_2d_arr(temp);
		return (0);
	}
	else
	{
		if (checknum(temp[1]) == 1 && checknum(temp[2]) == 1)
		{
			ft_clear_2d_arr(temp);
			return (1);
		}
		else
		{
			ft_clear_2d_arr(temp);
			return (0);
		}
	}
}

int		is_link(char *line)
{
	int		items;
	char	**temp;

	items = 0;
	temp = ft_strsplit(line, '-');
	while (temp[items])
		items++;
	if (items != 2)
	{
		ft_clear_2d_arr(temp);
		return (0);
	}
	else
	{
		ft_clear_2d_arr(temp);
		return (1);
	}
}
