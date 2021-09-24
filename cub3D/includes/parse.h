/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:38:43 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/09/20 13:08:26 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include "get_next_line.h"
# include "queue.h"

typedef struct	s_check
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
}				t_check;

typedef struct	s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		c[3];
	char	**map;
	char	**map_tmp;
	char	*buf_safe;
	int		tmp_row;
	int		tmp_column;
	int		player_x;
	int		player_y;
	t_check	check;
}				t_map;

typedef struct	s_bfs
{
	t_queue		q;
	t_position	p;
	t_position	p_now;
	int			**check;
}				t_bfs;

int				parse_main(char *map_title, t_map *map);
void			init_identities(t_map *map);
int				treat_map(t_map *map);
int				check_identities(char *line, t_map *map, char **str);
int				parse_texture_floor_ceil(char *line, t_map *map);
int				check_texture_floor_ceil(char *line, t_map *map, char **str);
int				check_texture(char **str, int cnt, t_map **map);
void			check_texture_direction(char **str, t_map **map);
int				check_floor_ceil(char **str, int cnt, t_map **map);
int				check_floor(char **str, t_map **map);
int				check_ceil(char **str, t_map **map);
int				check_validation_identities(t_map map);
size_t			get_partitions(char *s, char c);
int				check_alnum_str(char *str);
void			free_array(t_map *map);
void			free_arrays(char **str, int size);
char			**allocate_map_tmp(t_map map);
void			init_map_tmp(t_map *map);
void			update_map_tmp(t_map *map);
void			get_map_tmp_row_column(t_map *map);
int				check_player_position(t_map *map, int *flag, int idx, int jdx);
int				check_correct_inside(t_map *map);
int				check_map_bfs(t_map *map, t_bfs *bfs);
int				parse_map(t_map *map);
int				free_situatioin_terminate(char *s, char **str, int size);
int				**allocate_check(t_map map);
void			free_arrays_integers(int **arr, int size);
void			init_bfs(t_map *map, t_bfs *bfs);
int				sub_bfs(t_map *map, t_bfs *bfs, int next_x, int next_y);
int				main_bfs(t_map *map, t_bfs *bfs);

#endif
