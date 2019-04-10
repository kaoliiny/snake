#ifndef SNAKY_H
# define SNAKY_H

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/select.h>
#include <strings.h>
#include <time.h>

# define SKIN_T "X"
# define SNACK_T "$"
# define EATEN (s->tail->y == s->snack_y && s->tail->x == s->snack_x)

# define UP(a) (a == 'w' || a == KEY_UP)
# define DOWN(a) (a == 's' || a == KEY_DOWN)
# define LEFT(a) (a == 'a' || a == KEY_LEFT)
# define RIGHT(a) (a == 'd' || a == KEY_RIGHT)

typedef struct s_screen
{
    int x;
    int y;
}              t_screen;

typedef struct s_user
{
    char name[15];
}              t_user;

typedef struct s_body
{
    int y;
    int x;
    struct s_body *next;
}              t_body;

typedef struct s_snake
{
    struct s_body *tail;
    int lenght;
    int snack_y;
    int snack_x;
}              t_snake;

typedef struct		s_record
{
	int				position;
	char			*name;
	int				length;
	char			*datestr;
	struct s_record	*next;
	struct s_record	*previous;
}					t_record;

void    snake_attitude(t_screen *term, t_snake *s);
void	tail_create(t_body **a, int y, int x);

void    ft_print_game_over(t_screen *term, t_snake *snake);

t_body	*rev_rotate(t_body **stack);
t_body	*ft_newlst(int y, int x);

bool    is_key_control(int c);
bool    opposite (int a, int b);

#endif
