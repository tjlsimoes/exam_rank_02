#ifndef FLOOD_FILL_H
# define FLOOD_FILL_H
#include <stdio.h>
typedef struct  s_point
{
int           x;
int           y;
}               t_point;

char	get_begin_char(char **tab, t_point size, t_point begin);
int		get_actual_begin_idx(t_point begin);
void  flood_fill(char **tab, t_point size, t_point begin);
#endif