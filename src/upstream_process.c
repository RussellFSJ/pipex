/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upstream_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 23:42:40 by rfoo              #+#    #+#             */
/*   Updated: 2026/05/24 15:43:33 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	upstream_process(char *in_file, char **cmd1, char **envp)
{
	int	fd;

	fd = open(in_file, O_RDONLY);
	if (fd < 0)
	{
		perror("Failed to open file1.");
		exit(1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("Failed to redirect to STDIN.");
		exit(1);
	}
	close(fd);
	execve(cmd1[0], cmd1, envp);
	perror("Failed to execute cmd1.");
	exit(1);
}
