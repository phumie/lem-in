/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:46:31 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/11/29 17:27:59 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

static t_path	*get_top_path(t_path **paths)
{
	t_path	*tmp;

	tmp = *paths;
	*paths = (*paths)->next;
	tmp->next = NULL;
	return (tmp);
}

void			sort_paths(t_path **paths)
{
	t_path	*tmp;
	t_path	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	while (*paths)
	{
		tmp = get_top_path(paths);
		if (!tmp2)
			tmp2 = tmp;
		else if (tmp->numrooms >= tmp2->numrooms)
			add_to_paths(&tmp2, tmp);
		else
		{
			while (tmp->numrooms < tmp2->numrooms)
				add_to_paths(paths, get_top_path(&tmp2));
			if (!tmp2)
				tmp2 = tmp;
			else
				add_to_paths(&tmp2, tmp);
		}
	}
	while (tmp2)
		add_to_paths(paths, get_top_path(&tmp2));
}
