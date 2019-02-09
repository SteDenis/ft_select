#include <termcap.h>
#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct termios origtermios;

void ft_reset_term()
{
	tcsetattr(STDIN_FILENO, TCSANOW, &origtermios);
}

void ft_raw_on()
{
	struct termios raw;
	tcgetattr(STDIN_FILENO, &origtermios);

	raw = origtermios;
	raw.c_lflag &= ~(ECHO | ICANON);
	raw.c_cc[VMIN] = 1;
	raw.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int		ft_execute_term(int c)
{
	write(1, &c, 1);
	return 0;
}
int		main()
{
	char buf[1024];
	char *str, *str2, *str3, *str4;
	int i = 0;
	int v = 0;
	tgetent(buf, getenv("TERM"));
	str = tgetstr("cl", NULL);
	tputs(str, 0, ft_execute_term);
	ft_raw_on();
	str2 = tgetstr("cm", NULL);
	str3 = tgetstr("kr", NULL);
	str4 = tgetstr("im", NULL);
	tputs(str4, 0, ft_execute_term);
	char *underline_cmd = tgetstr("us", NULL);
	tputs(underline_cmd, 1, ft_execute_term);
	write(1, "\033[39;49m\033[39;49m\033(B\033[m\033[H\033[2J\033(B\033[0;7m GNU nano 2.0.6 File: test \033[23;30H[ New File ]\r\033[24d^G\033(B\033[m Get Help\033(B\033[0;7m^O\033(B\033[m WriteOut\033(B\033[0;7m^R\033(B\033[m Read Fil\033(B\033[0;7m^Y\033(B\033[m Prev Pag\033(B\033[0;7m^K\033(B\033[m Cut Text\033", 200);
	tputs(tgoto(str2, 0, 0), 1, ft_execute_term);
	char c[4];
	while (read(STDIN_FILENO, &c, 4) > 0){
		i = (i < 0) ? 0 : i;
		v = (v < 0) ? 0 : v;
		if (strcmp(c, "\e[B") == 0 && i >= 0)
			tputs(tgoto(str2, v, ++i), 1, ft_execute_term);
		if (strcmp(c, "\e[A") == 0 && i >= 0)
			tputs(tgoto(str2, v, --i), 1, ft_execute_term);
		if (strcmp(c, "\e[C") == 0 && v >= 0)
			tputs(tgoto(str2, ++v, i), 1, ft_execute_term);
		if (strcmp(c, "\e[D") == 0 && v >= 0)
			tputs(tgoto(str2, --v, i), 1, ft_execute_term);
	}
	ft_reset_term();
	tputs(str, 0, ft_execute_term);
	return (0);
}
