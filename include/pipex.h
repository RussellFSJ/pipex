/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 17:37:01 by rfoo              #+#    #+#             */
/*   Updated: 2026/05/29 06:17:32 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/wait.h>
# include "libft.h"
# include <fcntl.h>

typedef struct s_pipex
{
	char	**cmd1;
	char	**cmd2;
	char	**envp;
	char	*in_file;
	char	*out_file;
}	t_pipex;

void	upstream_process(int pipefd[2], t_pipex *px);
void	downstream_process(int pipefd[2], t_pipex *px);
t_pipex	*init_pipex(char	**argv, char **envp);
void	close_pipefd(int pipefd[2]);
void	handle_perror_exit(const char *err_msg);
void	pipex(t_pipex *px);

#endif