#include "../inc/snaky.h"

void snake_init(t_screen *term, t_snake *s)
{
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(2));
    s->lenght = 3;
    for (int i = 0; i < 3; i++) {
        tail_create(&s->tail, term->y / 2, (term->x / 2) - i);
        mvprintw(term->y / 2, (term->x / 2) - i, SKIN_T);
    }
    attroff(COLOR_PAIR(2));
}

void snack_init(t_screen *term, t_snake *s)
{
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    srand(time(0));
    attron(COLOR_PAIR(3));
    s->snack_y = rand() % term->y;
    s->snack_x = rand() % term->x;
    mvprintw(s->snack_y, s->snack_x, SNACK_T);
    attroff(COLOR_PAIR(3));
}

bool ft_collision(t_screen *term, t_body **tail)
{
    t_body *tmp = (*tail)->next;

    if ((*tail)->x > term->x)
        (*tail)->x = 0;
    else if ((*tail)->y == term->y)
        (*tail)->y = 0;
    else if ((*tail)->x < 0)
        (*tail)->x = term->x;
    else if ((*tail)->y < 0)
        (*tail)->y = term->y;
    while (tmp->next) {
        if ((*tail)->x == tmp->x
        && (*tail)->y == tmp->y) {
            return 1;
        }
        tmp = tmp->next;
    }
    return (false);
}

void move_snake(int key, t_body **tail)
{
    int x = (*tail)->x;
    int y = (*tail)->y;
    if (UP(key)) {
        y--;
    }
    else if (DOWN(key)) {
        y++;
    }
    else if (LEFT(key)) {
        x--;
    }
    else if (RIGHT(key)) {
        x++;
    }
    else
        return;
    *tail = rev_rotate(tail);
    (*tail)->x = x;
    (*tail)->y = y;
    attron(COLOR_PAIR(2));
    mvprintw((*tail)->y, (*tail)->x, SKIN_T);
    attroff(COLOR_PAIR(2));
}

void snake_attitude(t_screen *term, t_snake *s)
{
    int key_pressed = 0;
    int pre_key_pressed = 0;
    int speed = 10;
    s->snack_x = -1;

    snake_init(term, s);
    nodelay(stdscr, TRUE);
    while (!ft_collision(term, &s->tail) && key_pressed != 'q') {
        if (EATEN || s->snack_x == -1) {
            (!(s->lenght % 5)) && (speed += 5);
            if (s->snack_x != -1) {
                system("afplay ./sounds/0239.wav&");
                tail_create(&s->tail, -1, -1);
                s->lenght++;
            }
            snack_init(term, s);
        }
        usleep(1000000/speed);
        if (is_key_control((key_pressed = getch()))
        && !(opposite(key_pressed, pre_key_pressed))) {
                move_snake(key_pressed, &s->tail);
            pre_key_pressed = key_pressed;
        }
        else {
            move_snake(pre_key_pressed, &s->tail);
        }
        refresh();
    }
    erase();
}
