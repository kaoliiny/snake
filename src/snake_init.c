#include "../inc/snaky.h"

bool is_key_control(int c) {
    const int arr[9] = {'w', 'a', 's', 'd',
        KEY_UP, KEY_DOWN, KEY_RIGHT, KEY_LEFT};
    int i = -1;

    while (arr[++i]) {
        if (arr[i] == c)
            return (true);
    }
    return (false);
}

bool opposite (int a, int b) {
    if (UP(a) && !DOWN(b)) {
        return false;
    }
    else if (DOWN(a) && !UP(b)) {
        return false;
    }
     else if (LEFT(a) && !RIGHT(b)) {
        return false;
    }
    else if (RIGHT(a) && !LEFT(b)) {
        return false;
    }
    else {
        return true;
    }
}

inline t_body	*ft_newlst(int y, int x) {
	t_body	*new;

	if (!(new = (t_body *)malloc(sizeof(t_body))))
		return (NULL);
	else {
		new->y = y;
        new->x = x;
		new->next = NULL;
	}
	return (new);
}

void		tail_create(t_body **a, int y, int x) {
	t_body	*tmp;

	if (*a == NULL) {
		*a = ft_newlst(y, x);
		return ;
	}
	tmp = *a;
	while (tmp) {
		if (tmp->next == NULL) {
            (x == -1 && y == -1)
            && (x = tmp->x) && (y = tmp->y);
			tmp->next = ft_newlst(y, x);
			return ;
		}
		tmp = tmp->next;
	}
}

t_body	*rev_rotate(t_body **stack) {
    t_body *last_a;
	t_body *tmp;
	t_body *last;

	if (!stack) {
		return (NULL);
	}
	tmp = *stack;
	while (tmp) {
        if (tmp->next != NULL)
			last_a = tmp;
		else {
            mvprintw(tmp->y, tmp->x, " ");
			last = tmp;
			last->next = *stack;
			last_a->next = NULL;
			return (last);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
