/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   downstream_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 23:46:55 by rfoo              #+#    #+#             */
/*   Updated: 2026/05/29 06:09:28 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	downstream_process(int pipefd[2], t_pipex *px)
{
	int	fd;

	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		handle_perror_exit("Failed to redirect to STDIN.");
	close_pipefd(pipefd);
	fd = open(px->out_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		handle_perror_exit("Failed to open file2.");
	if (dup2(fd, STDOUT_FILENO) == -1)
		handle_perror_exit("Failed to redirect to STDOUT.");
	close(fd);
	execve(px->cmd2[0], px->cmd2, px->envp);
	handle_perror_exit("Failed to execute cmd2.");
}
