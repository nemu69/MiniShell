/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <nepage-l@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/11 00:32:07 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 21:04:12 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <errno.h>
# include "../Libftprintf/includes/ft_printf.h"

# define F file

typedef struct		s_env
{
	char			*str;
	char			*content;
	struct s_env	*next;
}					t_env;

typedef struct		s_file
{
	char			*pathend;
	char			**paths;
	int				done;
	char			**envp;
	t_env			*env;
}					t_file;

int					ft_echo(char **args);
char				*ft_strndup(char *src, int y);
int					invertedcoma(char *com, int *i, char **join, char *args);
int					doublecoma(char *com, int *i, char **join, char *args);
int					ft_input(t_file *file);
int					ft_cd(char **args, t_file *file);
char				**ft_parse(char *args, char *temp, char **join);
int					iscommand(char *line, t_file *file);
char				*findpath(void);
int					ft_env(char *com, char **args, t_file *file);
int					ft_envsetup(char **envp, t_file *file);
char				**ft_getargs(char *args, t_file *file);
char				**semicolon(char **args2, int *i);
int					ft_exit(char **args2, t_file *file);
int					ft_varenv(char *args, t_file *file);

#endif
