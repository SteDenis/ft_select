//
// Created by Steve Denis on 2019-01-31.
//

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <stddef.h>
# include <stdbool.h>
# include <stdint.h>
# include <termios.h>

# define BGW "\x1B[1;48;5;219m\x1B[1m\x1B[30m"
# define BGEOL "\x1b[K\x1b[30m\x1b[0m"
# define REV "\x1B[107m\x1B[38;5;0m\x1B[21m"
# define BGC "\x1B[104m\x1B[1m\x1B[97m"
/*
** Define for shortcut keyboard.
*/
# define ISARROW (buff[0] == 27 && (buff[2] == 91 || buff[2] < 70))
# define LEFT(x) (buff[x] == 68)
# define RIGHT(x) (buff[x] == 67)
# define UP(x) (buff[x] == 65)
# define DOWN(x) (buff[x] == 66)
# define RETURN (buff[0] == 10 && buff[1] == 0)
# define IS_OPT_ARR (buff[0] == 27 && buff[1] == 27)
# define EOF (buff[0] == 4 && buff[1] == 0)

typedef struct termios		t_termc;
typedef struct winsize		t_wsize;

typedef struct		s_xy
{
	size_t			x;
	size_t			y;
}					t_xy;

typedef struct		s_choice
{
	char 			*name;
	size_t			length;
	t_xy			pos;
	bool			printed;
	bool			selected;
	struct s_choice	*next;
}					t_choice;

typedef struct		s_term
{
	t_termc			n_term;
	t_termc			org_term;
	t_xy			pos;
	t_xy			max;
	t_wsize			wsize;
	size_t			max_l;
	size_t			qty;
	t_choice		*choices;
}					t_term;


//worker
void				print_cap(const char *id);
int					execute_tputs(int c);
void				goto_cap(const char *id, int x, int y);

//init
int					init_term(t_term *term);

//quit
void				end_select(t_term *term);

//loop
void				loop_select(t_term *term);

//window
int					print_top_bottom_bar(t_term *term);

//choices
int					fill_list_choices(char **ag, t_term *term);

//print/choices
void				print_list_choices(t_term *term);
void				calculate_start_print(t_term *term);

//print/cursor
void				move_cursor(t_term *term, char buff[]);
#endif
