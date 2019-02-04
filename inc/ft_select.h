/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:01:27 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/04 17:14:37 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <stddef.h>
# include <stdbool.h>
# include <stdint.h>
# include <termios.h>

/*
** Define unicode for box.
*/
# define BOXCG "\U0000256D"
# define BOXCD "\U0000256E"
# define BOXBT "\U00002500"
# define BOXLR "\U00002502"
# define BOXCGB "\U00002570"
# define BOXCDB "\U0000256F"

/*
** Define unicode for emoji.
*/
# define FOLDER "\U0001F4C1"
# define FILE "\U0001F4C4"
# define EXE "\U0001F4BE"
# define NOTF "\U0001F4CD"

/*
** Define colors.
*/
# define TXTB "\x1B[36m"
# define TXTR "\x1B[31m"
# define TXTM "\x1B[35m"
# define TXTN "\x1B[0m"
# define CENTER 4

/*
** Define for shortcut keyboard.
*/
# define ISARROW (buff[0] == 27 && (buff[2] == 91 || buff[2] < 70))
# define DEL (buff[0] == 27 && buff[1] == 91 && buff[2]== 51 && buff[3] == 126)
# define SUPPR (buff[0] == 127 && buff[1] == 0)
# define LEFT(x) (buff[x] == 68)
# define RIGHT(x) (buff[x] == 67)
# define UP(x) (buff[x] == 65)
# define DOWN(x) (buff[x] == 66)
# define RETURN (buff[0] == 10 && buff[1] == 0)
# define SPACE (buff[0] == 32 && buff[1] == 0)
# define IS_OPT_ARR (buff[0] == 27 && buff[1] == 27)
# define EOF (buff[0] == 4 && buff[1] == 0)

typedef struct termios		t_termc;
typedef struct winsize		t_wsize;

typedef struct		s_xy
{
	int				x;
	int				y;
}					t_xy;

typedef struct		s_choice
{
	char 			*name;
	size_t			length;
	t_xy			pos;
	int				type;
	bool			printed;
	bool			selected;
	struct s_choice	*next;
	struct s_choice	*prev;
}					t_choice;

typedef struct		s_term
{
	t_termc			n_term;
	t_termc			org_term;
	t_xy			pos;
	t_xy			max;
	t_wsize			wsize;
	int				page;
	int				max_l;
	int				max_p;
	int				qty;
	int				qty_s;
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
void				details_print(t_term *term, t_xy start, t_choice *choice);
void				print_printable_choices(t_term *term);

//print/cursor
void				move_cursor(t_term *term, char buff[]);
void				move_down(t_term *term, int right);
void				move_right(t_term *term, int down);
void				move_up(t_term *term);

//signal
void				enable_signal(t_term *term);

//interpert
void				select_item(t_term *term);
void				switch_page(t_term *term, char buff[]);

//del
int					del_elem(t_term **term);
#endif
