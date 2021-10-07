#ifndef MINISHELL_H
# define MINISHELL_H
# include <fcntl.h>
# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"
# include <memory.h>
# include "errno.h"

int	exit_stat;

typedef struct s_lst_args
{
	int					pars_arg;
	char				*arg;
	struct s_lst_args	*next;
}						t_lst_args;

typedef struct s_buba
{
	char				**redir;
	char				**args;
	t_lst_args			*args_lst;
	int					fd[2];
	int					in;
	int					out;
	int					fork;
	pid_t				pid;
	struct s_buba	*prev;
	struct s_buba	*next;
}						t_buba;

typedef struct s_mish_save {
	t_lst_args	*args_lst;
	char		**env_mish;
	int			mish_in;
	int			mish_out;
	int			stat_buba;
	int			stat_exec;
	t_list		*env_lst;
	t_list		*first;
	char		**args;
	char		**redirs;
	char		**com_ms;
}				t_mish_save;

void		set_env(t_mish_save *mish, char **env);
void		sort_env(t_mish_save *mish);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_start_pars2(t_mish_save *mish, t_buba **head, char *str, int i);
int			redir_exec(t_mish_save *mish, char *redir, int count_redir);
char		*parser(t_mish_save *mish, char *str);
void		go_comman(t_mish_save *mish, t_buba *lst);
void		free_lst(t_list *lst);
void		free_list(t_list **lst);
void		err(char *str, char *error_message);
void		save_dups(t_mish_save *mish);
void		close_dups(t_mish_save *mish);
char		*quot2(t_mish_save *mish, char *str, int i);
char		*quot(char *str, int i);
char		*ft_slesh(char *str, int *i);

char		*find_path(char *env_var_name, char **env);
char		*path_operations(char **envp, char **args, char **path, char **tmp);
void		new_envp(t_mish_save *mish, char *found);
int			cd(t_mish_save *mish, char **args, char **env);
int			export(t_mish_save *mish, char **args);
int			unset(t_mish_save *mish, char **args);
int			echo_handler(char **str);
int			exit_mish(t_mish_save *mish, char **args);
int			name_check(t_buba *lst);
void		name_exec_check(t_mish_save *mish, t_buba *lst);

int			compare_strings(char *str, char *tmp);

t_list		*delete_lst(t_list **lst, char *found);
char		**make_arr_from_lst(t_list *lst);
void		remove_elem(t_mish_save *mish, char *found);
t_buba	*ft_lstnew_mish(char **args, char **redirs,
				t_lst_args *args_lst);
void		ft_lstadd_back_mish(t_buba **lst, t_buba *new);
t_buba	*ft_lstlast_mish(t_buba *lst);
void		clear_lst(t_buba **lst);
void		fr_lst(t_list *lst);

void		signal_child(void);
void		signal_first(void);
void		signal_pipes(void);
void		ft_signal_pipes(int s);

void		ft_arrfree(char **arr);
int			ft_arrlen(char **arr);

void		pipe_err(char *str, char *error_message, int err);
void		redir_err(t_buba *lst, char *file_name);
void		synt_err(const char *str, int i);
void		quot_err(const char *str, int i, unsigned int quot_num,
				unsigned int quot2_num);
void		pipes_correctness_error(void);

int			redir_pars(t_mish_save *mish, t_buba *lst, int type);
char		*file_name_export(const char *redir, int type);

int			char_in_string(char ch, char *chars);
int			check_spaces(const char *str);
int			slash(const char *tmp, int *i);
char		*free_strings(char *tmp, char *str);
char		*init_variables_pars(t_mish_save *mish, char *str, int *i, int *count_args);
char		*ft_sle2(t_mish_save *mish, char *str, int *i);
int		ft_start_pars1(t_mish_save *mish, char *str, t_buba **head);
int			k_search(char c);
void		question_mark(t_mish_save *mish);
char		*ft_sle(char *str, int *i);
char		**ft_lst_get_array(t_lst_args *lst);
int			ft_lstsize_args(t_lst_args *lst);
void		*ft_malloc_x(size_t size);
void		parsing_args(t_mish_save *mish, t_buba *lst);
void		exec_binary(t_mish_save *mish, t_buba *lst);
void		ft_execut(t_mish_save *mish, t_buba *lst);
void		last_exec(t_mish_save *mish, t_buba *lst);
void		pid_waiting(t_buba *start, t_buba *lst);
void		struct_lists_creating(t_mish_save *mish, t_buba **head, int count_redir,
				int count_args);
int			pure_pars(t_mish_save *mish, int *i, char *tmp, int count_args);
int			quot2_pars(t_mish_save *mish, int *i, char *tmp, int count_args);
int			redir_parser(t_mish_save *mish, int *i, char *tmp, int count_redir);
void		*ft_realloc(void *ptr, size_t size);
t_lst_args	*ft_lstnew_args(char *arg, int is_parsed);
void		ft_lstadd_back_args(t_lst_args **lst, t_lst_args *new);
t_lst_args	*ft_lstlast_args(t_lst_args *lst);
void		begin_main(t_mish_save *mish, char **env);
char		*ft_dollar(t_mish_save *mish, char *str, int j, int *i);
void		make_lvl(t_mish_save *mish);
void		free_lst_mish(t_mish_save *mish, char *str);
void		clear_mem(t_buba *lst);
void		get_arr(t_buba *el);
char		**ft_lst_get_arrayf(t_list *lst);
int	quot_pars(t_mish_save *mish, int *i, char *tmp, int count_args);
void	quot_check(const char *str, int i, unsigned int *quot_num, unsigned int *quot2_num);

#endif
