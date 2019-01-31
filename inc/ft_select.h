//
// Created by Steve Denis on 2019-01-31.
//

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <stddef.h>
# include <stdbool.h>
# include <stdint.h>
# include <termios.h>

# define BGW "\x1B[107m\x1B[1m\x1B[30m"
# define BGEOL "\x1b[K\x1b[30m\x1b[0m"
# define BGC "\x1B[104m\x1B[1m\x1B[97m"
typedef struct termios		t_termc;
typedef struct winsize		t_wsize;

typedef struct	s_xy
{
	int			x;
	int			y;
}				t_xy;

typedef struct	s_choice
{
	char 		*name;
	size_t		length;
	t_xy		pos;
	bool		printed;
	bool		selected;
}				t_choice;

typedef struct	s_term
{
	t_termc		n_term;
	t_termc		org_term;
	t_xy		pos;
	t_xy		max;
	t_wsize		wsize;
	size_t		max_l;
	t_choice	*choices;
}				t_term;


//worker
void			print_cap(const char *id);
int				execute_tputs(int c);
void			goto_cap(const char *id, int x, int y);

//init
int				init_term(t_term *term);

//quit
void			end_select(t_term *term);

//loop
void			loop_select(t_term *term);

//window
int				print_top_bottom_bar(t_term *term);

//choices
int				fill_list_choices(char **ag, t_term *term);
#endif
