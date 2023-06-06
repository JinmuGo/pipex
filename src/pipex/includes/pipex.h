/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:17:14 by jgo               #+#    #+#             */
/*   Updated: 2022/12/13 14:34:28 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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

	// error.c
void	error_handling(int L, t_argument *arg, int file[2]);

	// utils.c
void	direction_handling(int L, t_argument *arg, int fd[2], int input);
char	*check_file(char *str);

#endif
