/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upstream_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 23:42:40 by rfoo              #+#    #+#             */
/*   Updated: 2026/05/29 06:09:21 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	upstream_process(int pipefd[2], t_pipex *px)
{
	int	fd;

	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		handle_perror_exit("Failed to redirect to STDOUT.");
	close_pipefd(pipefd);
	fd = open(px->in_file, O_RDONLY);
	if (fd < 0)
		handle_perror_exit("Failed to open file1.");
	if (dup2(fd, STDIN_FILENO) == -1)
		handle_perror_exit("Failed to redirect to STDIN.");
	close(fd);
	execve(px->cmd1[0], px->cmd1, px->envp);
	handle_perror_exit("Failed to execute cmd1.");
}
