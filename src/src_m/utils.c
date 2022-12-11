/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:54:20 by jgo               #+#    #+#             */
/*   Updated: 2022/11/30 20:25:45 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
