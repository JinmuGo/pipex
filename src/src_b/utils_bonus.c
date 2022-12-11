/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:54:20 by jgo               #+#    #+#             */
/*   Updated: 2022/12/11 21:03:57 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	direction_handling(int L, t_argument *arg, int fd[2], int input)
{
	if (L != arg->cmd_cnt - 1)
		close(fd[0]);
	if (L == 0)
		dup2(arg->file[0], STDIN_FILENO);
	else
		dup2(input, STDIN_FILENO);
	if (L != arg->cmd_cnt - 1)
		dup2(fd[1], STDOUT_FILENO);
	else
		dup2(arg->file[1], STDOUT_FILENO);
}

char	*find_tmp_name(void)
{
	const char	*default_name = "/tmp/.tmp_file_";
	char		*file_name;
	char		*num;
	int			number;

	number = 0;
	num = ft_itoa(number);
	file_name = ft_strjoin(default_name, num);
	while (access(file_name, F_OK | W_OK) == 0)
	{
		free(file_name);
		free(num);
		num = ft_itoa(++number);
		file_name = ft_strjoin(default_name, num);
	}
	free(num);
	return (file_name);
}

char	*make_pipe_str(int pipe_num)
{
	const char		*pipe = "pipe ";
	char			*pipe_str;
	char			*tmp_str;
	int				i;

	i = 0;
	pipe_str = ft_strjoin("", pipe);
	while (i < pipe_num)
	{
		tmp_str = ft_strjoin(pipe_str, pipe);
		free(pipe_str);
		pipe_str = ft_strdup(tmp_str);
		free(tmp_str);
		i++;
	}
	tmp_str = ft_strjoin(pipe_str, "here_doc>");
	free(pipe_str);
	pipe_str = ft_strdup(tmp_str);
	free(tmp_str);
	return (pipe_str);
}
