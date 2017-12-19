/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:02:07 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/12/04 12:15:16 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void	error_exit(char *error_msg, t_farm **farm, char *line, char *temp_line)
{
	ft_putendl(error_msg);
	destroy_farm(farm);
	free(temp_line);
	if (line)
		free(line);
	exit(0);
}

int		check_line(char *line, char *temp_line, int stage, t_farm **farm)
{
	if (is_room(temp_line))
		manage_rooms(line, temp_line, farm, stage);
	else if (is_link(temp_line))
		manage_links(line, temp_line, farm, stage);
	else if (checknum(temp_line) == 1 && stage == 1)
	{
		if (!(*farm = create_farm(ft_atoi(temp_line))))
			error_exit("Mem allocation failed.", farm, line, temp_line);
		stage = 2;
	}
	else if (is_command(temp_line) && (*farm)->cmd == NULL && stage == 2)
	{
		if (ft_strequ(temp_line, "##start") || ft_strequ(temp_line, "##end"))
			(*farm)->cmd = ft_strdup(temp_line);
	}
	else if (is_comment(temp_line) == 0)
		error_exit("Error", farm, line, temp_line);
	return (stage);
}

int		main(void)
{
	char	*line;
	char	*tmp;
	int		stage;
	t_farm	*farm;
	t_path	*paths;

	stage = 1;
	paths = NULL;
	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		tmp = ft_strtrim(line);
		stage = check_line(line, tmp, stage, &farm);
		if (!is_comment(tmp))
			ft_putendl(tmp);
		free(tmp);
	}
	free(line);
	transform_farm(&farm);
	get_paths(farm, &paths);
	sort_paths(&paths);
	move_ants(&farm, paths);
	destroy_farm(&farm);
	destroy_paths(&paths);
	return (0);
}
