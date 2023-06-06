/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:17:14 by jgo               #+#    #+#             */
/*   Updated: 2022/12/13 14:54:41 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>

# include "libft.h"
# include "ft_printf.h"

typedef struct s_argument	t_argument;
typedef struct s_info		t_info;

enum	e_exec
{
	POSSIBLE = 1,
	IMPOSSIBLE = 0
};

struct s_info
{
	char		**whole_cmd;
	char		*abs_path;
	enum e_exec	executable;
};

struct s_argument
{
	int		cmd_cnt;
	char	**cmd_str;
	char	**envp;
	int		last_status;
	int		file[2];
	t_info	**cmd_info;
};

// utils
	// input.c
t_info	**px_parse(t_argument *arg);
t_info	**hd_parse(t_argument *arg, int argc, char **argv);

	// error.c
void	error_handling(int L, t_argument *arg, int file[2]);

	// utils.c
void	direction_handling(int L, t_argument *arg, int fd[2], int input);
char	*find_tmp_name(void);
char	*make_pipe_str(int pipe_num);
char	*check_file(char *str);
void	here_doc_prompt(const char *end_flag, const char *heredoc, int file);

#endif
