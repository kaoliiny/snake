#include "../inc/snaky.h"

void ft_errors(char *str_err, int fd)
{
    endwin();
    write(fd, str_err, strlen(str_err));
    exit(1);
}

void		records(t_user *user, t_snake *snek) {
    FILE	*pRecords = fopen("records.txt", "a");
    char	*username = user->name;
    int		record = snek->lenght;
	time_t	now;

    if (!pRecords){
        __builtin_printf("Unfortunately, the records file could not be");
        __builtin_printf(" created or updated. Chech that you have ");
        __builtin_printf("sufficient rights for that\n");
        exit(0);
    }
	time(&now);
    fprintf(pRecords, "\nUsername: %15s ||| Record: %3d ||| Date set: %s", \
			username, record, ctime(&now));
}

void end_of_game (t_screen *term, t_user *user, t_snake *snake) {
    attron(COLOR_PAIR(2));
    ft_print_game_over(term, snake);
    attroff(COLOR_PAIR(2));
    refresh();
    getch();
    records(user, snake);
}

void start_of_game(t_screen *term, t_user *user)
{
    char *str = "Hello bro!!!";
    char *str2 = "Write your name below";

    raw();
    keypad(stdscr, TRUE);
    if (has_colors() == FALSE) {
	    ft_errors("Your terminal does not support color\n", 2);
    }
	start_color();
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
    attron(COLOR_PAIR(1));
	mvprintw(term->y / 2 - 2, (term->x - strlen(str)) / 2, str);
    mvprintw(term->y / 2 - 1, (term->x - strlen(str2)) / 2, str2);
    attroff(COLOR_PAIR(1));
    mvgetnstr(term->y / 2 + 1, (term->x - strlen(str)) / 2 - 1,
        user->name, 15);
    user->name[14] = '\0';
	refresh();
}

int main(void)
{
    t_user user;
    t_screen term;
    t_snake snake;

    bzero(&term, sizeof(t_screen));
    bzero(&user, sizeof(t_user));
    bzero(&snake, sizeof(t_snake));
    initscr();
    getmaxyx(stdscr, term.y, term.x);
    if (term.y < 3 || term.x < 95) {
	    ft_errors("Screen error. Game needs a bigger screen\n", 2);
    }
    start_of_game(&term, &user);
    noecho();
    curs_set(0); /* INVISIBLE CURSOR*/
    erase();
    snake_attitude(&term, &snake);
    end_of_game(&term, &user, &snake);
    getch();
    endwin();
    return 0;
}
