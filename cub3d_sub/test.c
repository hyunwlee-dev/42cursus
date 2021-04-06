#include <stdio.h>

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
    int                     R[2];
    char                    *NO;
    char                    *SO;
    char                    *WE;
    char                    *EA;
    char                    *S;
    int                     F[3];
    int                     C[3];
    t_check                 check;
}               t_map;

void    init_struct_check(t_check *check)
{
    check->R = 0;
    check->NO = 0;
    check->SO = 0;
    check->WE = 0;
    check->EA = 0;
    check->S = 0;
    check->F = 0;
    check->C = 0;
}

void    init_struct_map(t_map *map)
{
    init_struct_check(&(map->check));
}

int main()
{
    t_map map;
    map.check.C = 1;

    return (0);
}