/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:20:22 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/12/04 10:13:11 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../libft/libft.h"

typedef	struct		s_path
{
	int				numrooms;
	char			**rooms;
	struct s_path	*next;
}					t_path;

typedef struct		s_ant
{
	int				ant_num;
	int				path_num;
	int				to_move;
	int				dist;
	t_path			*path;
	struct s_ant	*next;
}					t_ant;

typedef struct		s_room
{
	char			*name;
	char			**linked_rooms;
	char			*visitedby;
	char			*parent;
	int				num_linked_rooms;
	int				lvl;
	int				visited;
	t_ant			*ants;
	struct s_room	*next;
}					t_room;

typedef struct		s_farm
{
	int				antsnum;
	int				numrooms;
	t_room			*all_rooms;
	t_ant			*ants;
	char			*endroom;
	char			*startroom;
	char			*cmd;
	char			**queue;
}					t_farm;

int					checknum(char *str);
int					is_comment(char *line);
int					is_command(char *line);
int					is_room(char *line);
int					is_link(char *line);
t_room				*get_room(t_farm **farm, char *room_name);
void				add_room_to_farm(t_farm **farm, char *new_room);
int					manage_rooms(char *line,
					char *tmp, t_farm **farm, int stage);
int					manage_links(char *line,
					char *tmp, t_farm **farm, int stage);
void				error_exit(char *error_msg,
					t_farm **farm, char *line, char *tmp);
int					check_line(char *line, char *tmp, int stage, t_farm **farm);
t_room				*get_room(t_farm **farm, char *room_name);
char				**add_room_to_linked(char **room_list, char *new_room);
t_room				*create_room(char *name);
t_farm				*create_farm(int number_of_ants);
t_ant				*create_ant(int antnum, int pathnum);
t_path				*create_path(int n_rooms, char *name);
void				add_to_paths(t_path **allpaths, t_path *a_path);
char				**create_2d_space(int rooms);
void				create_link(t_farm **farm, char *line);
void				set_room(t_room **r1, t_room *r2);
void				remove_one_link(t_room **r1, t_room *r2);
void				remove_both_linked(char *endroom, t_room **r1, t_room **r2);
void				clean_up(t_farm **farm, t_room **end, char **rooms, int n);
int					check_ancestry(t_room *temp, char *str, int min_lvl);
int					linked_to_same_room(char *room, t_room *end);
void				transform_farm(t_farm **farm);
void				get_paths(t_farm *farm, t_path **paths);
void				sort_paths(t_path **paths);
int					count_paths(t_room *end);
void				add_ant_to_farm(t_ant **allants, t_ant *ant);
void				move_ants(t_farm **farm, t_path *paths);
void				destroy_farm(t_farm **farm);
void				destroy_paths(t_path **paths);
char				**add_to_queue(char **queue, char *name);

#endif
