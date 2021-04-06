#include "get_next_line.h"
#include "queue.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  s_check
{
    int R;
    int NO;
    int SO;
    int WE;
    int EA;
    int S;
    int F;
    int C;
}               t_check;

typedef struct  s_map
{
    int     R[2];
    char    *NO;
    char    *SO;
    char    *WE;
    char    *EA;
    char    *S;
    int     F[3];
    int     C[3];
    char    **MAP;
    char    **MAP_TMP;
    char    *buf_safe;
    int     row;
    int     column;
    int     player_x;
    int     player_y;
    t_check check;
}               t_map;

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////     utils.c     ////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

size_t	get_len(char *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
			++cnt;
		while (*(s + i) != c && *(s + i))
			++i;
		if (*(s + i) == c)
			++i;
	}
	return (cnt);
}

int    isalnum_str(char *str)
{
    int idx;

    idx = 0;
    while (*(str + idx))
    {
        if (ft_isalnum(*(str + idx)))
            return (1);
        idx++;
    }
    return (0);
}

void    print_all(t_map map)
{
    printf("---------------------------\n");
    printf("---------------------------\n");
    printf("map.R[0]:%d\t", map.R[0]);
    printf("map.R[1]:%d\n", map.R[1]);
    printf("sizeof(map.R): %d\n", (int)sizeof(map.R));
    printf("map.NO:%s\n", map.NO);
    printf("map.SO:%s\n", map.SO);
    printf("map.WE:%s\n", map.WE);
    printf("map.EA:%s\n", map.EA);
    printf("map.S:%s\n", map.S);
    printf("map.F[0]:%d\t", map.F[0]);
    printf("map.F[1]:%d\t", map.F[1]);
    printf("map.F[2]:%d\n", map.F[2]);
    printf("sizeof(map.F): %d\n", (int)sizeof(map.F));
    printf("map.C[0]:%d\t", map.C[0]);
    printf("map.C[1]:%d\t", map.C[1]);
    printf("map.C[2]:%d\n", map.C[2]);
    printf("sizeof(map.C): %d\n", (int)sizeof(map.C));
    printf("map.player_x:%d\n", map.player_x);
    printf("map.player_y:%d\n", map.player_y);
    printf("---------------------------\n");
    printf("map.check.R:%d\n", map.check.R);
    printf("map.check.NO:%d\n", map.check.NO);
    printf("map.check.SO:%d\n", map.check.SO);
    printf("map.check.WE:%d\n", map.check.WE);
    printf("map.check.EA:%d\n", map.check.EA);
    printf("map.check.S:%d\n", map.check.S);
    printf("map.check.F:%d\n", map.check.F);
    printf("map.check.C:%d\n", map.check.C);
    printf("---------------------------\n");
    printf("---------------------------\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////     free.c     ////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
void    free_used_struct_map(t_map *map)
{
    free(map->NO);
    free(map->SO);
    free(map->WE);
    free(map->EA);
    free(map->S);
    free(map->buf_safe);
}

void    free_two_dimensions(char **str, int size)
{
    int idx;

    idx = 0;
    while (idx < size)
        free(str[idx++]);
    free(str);
}

int     free_situatioin_terminate(char *s, char **str, int size, t_map *map)
{
    if (!(ft_strncmp(s, "resolution", ft_strlen(s))))
        printf("[Map Parsing]Resolution 문제[ex) 1.갯수, 2.!isdigit?]\n");
    else if (!(ft_strncmp(s, "texture", ft_strlen(s))))
        printf("[Map Parsing]Texture 문제[ex) 1.갯수]\n");
    else if (!(ft_strncmp(s, "floor||ceiling", ft_strlen(s))))
        printf("[Map Parsing]Floor또는 Ceiling 문제\n");
    else if (!(ft_strncmp(s, "else", ft_strlen(s))))
        printf("[Map Parsing]WHO ARE YOU!!!!!????\n");
    else if (!(ft_strncmp(s, "map", ft_strlen(s))))
        printf("[Map Parsing]check_is_satisfied_total == false or 필요데이터들을 받는 도중 map이 들어온 경우\n");
    free_used_struct_map(map);
    free_two_dimensions(str, size);
    return (1);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////     check.c     ////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////


int     check_is_satisfied_total(t_map map)
{
    if (!map.check.R || !map.check.NO || !map.check.SO || !map.check.WE || !map.check.EA || !map.check.S || !map.check.F || !map.check.C)
        return (0);
    return (1);
}

int     check_is_resolution(char **str, int cnt, t_map **map)
{
    int idx;
    int jdx;

    idx = 1;
    if (cnt != 3)
        return (0);
    while (idx < cnt)
    {
        jdx = 0;
        while (str[idx][jdx] != '\0' && ft_isdigit(str[idx][jdx]))
            jdx++;
        if (str[idx][jdx] != '\0' && !ft_isdigit(str[idx][jdx]))
            return (0);
        idx++;
    }
    (*map)->R[0] = ft_atoi(*(str + 1));
    (*map)->R[1] = ft_atoi(*(str + 2));
    (*map)->check.R = 1;
    return (1);
}

int     check_is_texture(char **str, int cnt, t_map **map)
{
    if (cnt != 2)
        return (0);
    if (!ft_strncmp(str[0], "NO", 3))
    {
        free((*map)->NO);
        (*map)->NO = ft_strdup(*(str + 1));
        (*map)->check.NO = 1;
    }
    else if (!ft_strncmp(str[0], "SO", 3))
    {
        free((*map)->SO);
        (*map)->SO = ft_strdup(*(str + 1));
        (*map)->check.SO = 1;
    }
    else if (!ft_strncmp(str[0], "WE", 3))
    {
        free((*map)->WE);
        (*map)->WE = ft_strdup(*(str + 1));
        (*map)->check.WE = 1;
    }
    else if (!ft_strncmp(str[0], "EA", 3))
    {
        free((*map)->EA);
        (*map)->EA = ft_strdup(*(str + 1));
        (*map)->check.EA = 1;
    }
    else if (!ft_strncmp(str[0], "S", 2))
    {
        free((*map)->S);
        (*map)->S = ft_strdup(*(str + 1));
        (*map)->check.S = 1;
    }
    return (1);
}

int     check_is_floor_ceil(char **str, int cnt, t_map **map)
{
    char **arr;
    int idx;
    int jdx;

    idx = 0;
    if (cnt != 2)
        return (0);
    if (!ft_strncmp(str[0], "F", 2))
    {
        if ((int)get_len(str[1], ',') != 3)
            return (0);
        arr = ft_split(str[1], ',');
        while (idx < (int)get_len(str[1], ','))
        {
            jdx = 0;
            while (arr[idx][jdx] != '\0' && ft_isdigit(arr[idx][jdx]))
                jdx++;
            if (arr[idx][jdx] != '\0' && !ft_isdigit(arr[idx][jdx]))
                return (0);
            idx++;
        }
        (*map)->F[0] = ft_atoi(arr[0]);
        (*map)->F[1] = ft_atoi(arr[1]);
        (*map)->F[2] = ft_atoi(arr[2]);
        free_two_dimensions(arr, (int)get_len(str[1], ','));
        (*map)->check.F = 1;
    }
    else if (!ft_strncmp(str[0], "C", 2))
    {
        if ((int)get_len(str[1], ',') != 3)
            return (0);
        arr = ft_split(str[1], ',');
        while (idx < (int)get_len(str[1], ','))
        {
            jdx = 0;
            while (arr[idx][jdx] != '\0' && ft_isdigit(arr[idx][jdx]))
                jdx++;
            if (arr[idx][jdx] != '\0' && !ft_isdigit(arr[idx][jdx]))
                return (0);
            idx++;
        }
        (*map)->C[0] = ft_atoi(arr[0]);
        (*map)->C[1] = ft_atoi(arr[1]);
        (*map)->C[2] = ft_atoi(arr[2]);
        (*map)->check.C = 1;
    }
    return (1);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////     init.c     ////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

void    init_struct_map(t_map *map)
{
    ft_bzero(&(map->R), sizeof(map->R));
    map->NO = ft_strdup("");
    map->SO = ft_strdup("");
    map->WE = ft_strdup("");
    map->EA = ft_strdup("");
    map->S = ft_strdup("");
    ft_bzero(&(map->F), sizeof(map->F));
    ft_bzero(&(map->C), sizeof(map->C));
    map->MAP = 0;
    map->MAP_TMP = 0;
    map->buf_safe = ft_strdup("");
    map->row = 0;
    map->column = 0;
    map->player_x = 0;
    map->player_y = 0;
    ft_bzero(&(map->check), sizeof(map->check));
}

int    parse_identifier(char *line, t_map *map)
{
    char        **str;

    str = 0;
    if (!isalnum_str(line))
        return (0);
    str = ft_split(line, ' ');
    if (*line && ft_isalpha(str[0][0]))
    {
        if (!ft_strncmp(str[0], "R", 2))
        {
            if (!(check_is_resolution(str, (int)get_len(line, ' '), &map)))
                return (free_situatioin_terminate("resolution", str, (int)get_len(line, ' '), map));
        }
        else if (!ft_strncmp(str[0], "NO", 3) || !ft_strncmp(str[0], "SO", 3) || !ft_strncmp(str[0], "WE", 3) || !ft_strncmp(str[0], "EA", 3) || !ft_strncmp(str[0], "S", 2))
        {
            if (!(check_is_texture(str, (int)get_len(line, ' '), &map)))
                return (free_situatioin_terminate("texture", str, (int)get_len(line, ' '), map));

        }
        else if (!ft_strncmp(str[0], "F", 2) || !ft_strncmp(str[0], "C", 2))
        {
            if (!(check_is_floor_ceil(str, (int)get_len(line, ' '), &map)))
                return (free_situatioin_terminate("floor||ceiling", str, (int)get_len(line, ' '), map));
        }
        else
            return (free_situatioin_terminate("else", str, (int)get_len(line, ' '), map));
    }
    else if (*line)
    {
        if (!check_is_satisfied_total(*map) || !(map->buf_safe = gnl_strjoin(&(map->buf_safe), line)) || !(map->buf_safe = gnl_strjoin(&(map->buf_safe), "\n")))
            return (free_situatioin_terminate("map", str, (int)get_len(line, ' '), map));
    }
    free_two_dimensions(str, (int)get_len(line, ' '));
    return (0);
}

////////////////////////////////////////////////////////////////////////////////
/////////////////////////   How to do map parsing ?   //////////////////////////
////////////////////////////////////////////////////////////////////////////////

void    update_map_tmp(t_map *map)
{
    int idx;
    int jdx;

    idx = 0;
    while (idx < (int)get_len(map->buf_safe, '\n'))
    {
        jdx = 0;
        while (jdx < (int)ft_strlen(map->MAP[idx]))
        {
            if (map->MAP[idx][jdx] != ' ')
                map->MAP_TMP[idx + 1][jdx + 1] = map->MAP[idx][jdx];
            jdx++;
        }
        idx++;
    }
}

void    init_map_tmp(t_map *map)
{
    int idx;

    idx = 0;
    while (idx < map->row)
    {
        ft_memset(map->MAP_TMP[idx], 'X', map->column);
        idx++;
    }
}

char    **allocate_map_tmp(t_map map)
{
    char **result;
    int idx;
    int jdx;

    idx = 0;
    jdx = 0;
    if (!(result = (char **)malloc(sizeof(char *) * (map.row + 1))))
        return (NULL);
    result[map.row] = 0;
    while (idx < map.row)
    {
        if (!(result[idx] = (char *)malloc(sizeof(char) * (map.column + 1))))
        {
            free_two_dimensions(result, idx);
            return (NULL);
        }
        result[idx][map.column] = '\0';
        idx++;
    }
    return (result);
}

void    get_map_row_column(t_map *map)
{
    int idx;
    int jdx;

    idx = 1;
    jdx = 0;
    map->row = (int)get_len(map->buf_safe, '\n');
    map->MAP = ft_split(map->buf_safe, '\n');
    map->column = (int)ft_strlen(map->MAP[0]);
    while (idx < map->row)
    {
        if (map->column < (int)ft_strlen(map->MAP[idx]))
            map->column = (int)ft_strlen(map->MAP[idx]);
        idx++;
    }
    map->row += 2;
    map->column += 2;
}

int    check_correct_inside(t_map *map)
{
    int     idx;
    int     jdx;
    int     flag;
    char    c;

    idx = 0;
    flag = 0;
    while (idx < (int)get_len(map->buf_safe, '\n'))
    {
        jdx = 0;
        while (jdx < (int)ft_strlen(map->MAP[idx]))
        {
            c = map->MAP[idx][jdx];
            if (flag && c == 'N')
                return (1);
            if (c == 'N')
            {
                flag = 1;
                map->player_x = idx + 1;
                map->player_y = jdx + 1;
            }
            if (c != ' ' && c != '0' && c != '1' && c != '2' && c != 'N')
                return (1);
            jdx++;
        }
        idx++;
    }
    return (0);
}

int    parse_map(t_map *map)
{
    get_map_row_column(map);
    if (!(map->MAP_TMP = allocate_map_tmp(*map)) || check_correct_inside(map))
    {
        printf("[Map Parsing]allocate fail! or Not '0' or '1' or '2' or 'N' in map\n");
        free_used_struct_map(map);
        return (1);
    }
    init_map_tmp(map);
    update_map_tmp(map);
    return (0);
}

////////////////////////////////////////////////////////////////////////////////
/////////////////////////    map validity check BFS   //////////////////////////
////////////////////////////////////////////////////////////////////////////////

void    bfs(t_map *map)
{
    const int   dx[4] = {0, 0, 1, -1};
    const int   dy[4] = {1, -1, 0, 0};
    int         check[map->row][map->column];

    ft_bzero(check, sizeof(check));
    t_queue q;
    offer(&q, );
}


int main(void)
{
    char        *line;
    int         ret;
    int         fd;
    t_map       map;

    init_struct_map(&map);
    fd = open("./arguments.cub", O_RDONLY);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        if (parse_identifier(line, &map))
            return (0);
        free(line);
        line = 0;
    }
    if (parse_identifier(line, &map))
        return (0);
    free(line);
    line = 0;
    close(fd);
    if (parse_map(&map))
        return (0);
    print_all(map);
    int i = 0;
    while (i < map.row)
    {
        int j = 0;
        while (j < map.column)
        {
            printf("%c ", map.MAP_TMP[i][j]);
            j++;
        }
        i++;
        printf("\n");
    }
    bfs(&map);
    return (0);
}
