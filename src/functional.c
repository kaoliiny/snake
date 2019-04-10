#include "../inc/snaky.h"

void ft_print_game_over(t_screen *term, t_snake *snake) {
    nodelay(stdscr, FALSE);
    mvprintw(term->y / 2 - 5, (term->x - 97) / 2,
    "  _|_|_|                                          ");
    printw("    _|_|                                    \n");
    mvprintw(term->y / 2 - 4, (term->x - 97) / 2,
    "_|           _|_|_|   _|_|_|  _|_|      _|_|       ");
    printw("_|    _|   _|      _|     _|_|     _|  _|_|\n");
    mvprintw(term->y / 2 - 3, (term->x - 97) / 2,
    "_|  _|_|  _|    _|   _|    _|    _|  _|_|_|_|      _| ");
    printw("   _|   _|      _|   _|_|_|_|   _|_|    \n");
    mvprintw(term->y / 2 - 2, (term->x - 97) / 2,
    "_|    _|  _|    _|   _|    _|    _|  _|            _| ");
    printw("   _|     _|  _|     _|         _|      \n");
    mvprintw(term->y / 2 - 1, (term->x - 97) / 2,
    "  _|_|_|    _|_|_|   _|    _|    _|    _|_|_|        _|");
    printw("_|         _|         _|_|_|   _|      \n");
    mvprintw(term->y / 2 + 2, (term->x - 21) / 2,
    "Your record is:%3d\n", snake->lenght);
}
