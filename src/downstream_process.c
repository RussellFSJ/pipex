/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   downstream_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 23:46:55 by rfoo              #+#    #+#             */
/*   Updated: 2026/05/24 15:43:29 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	downstream_process(char *out_file, char **cmd2, char **envp)
{
	int	fd;

	fd = open(out_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("Failed to open file2.");
		exit(1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("Failed to redirect to STDOUT.");
		exit(1);
	}
	close(fd);
	execve(cmd2[0], cmd2, envp);
	perror("Failed to execute cmd2.");
	exit(1);
}
