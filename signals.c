#include "minishell.h"

void	c_quit(int sig)
{
	if (sig == SIGQUIT)
		write(1, "Quit: 3", 7);
	write(1, "\n", 1);
}

void	ft_signal_pipes(int s)
{
	signal(SIGINT, SIG_IGN);
	(void)s;
}

void	signal_pipes(void)
{
	signal(SIGINT, ft_signal_pipes);
	signal(SIGQUIT, c_quit);
}

void	signal_child(void)
{
	signal(SIGTERM, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, c_quit);
}

void	signal_first(void)
{
	signal(SIGTERM, SIG_IGN);
	signal(SIGINT, c_quit);
	signal(SIGQUIT, SIG_IGN);
}
