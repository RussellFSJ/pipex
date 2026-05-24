/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 17:37:01 by rfoo              #+#    #+#             */
/*   Updated: 2026/05/24 15:43:59 by rfoo             ###   ########.fr       */
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

void	upstream_process(char *in_file, char **cmd1, char **envp);
void	downstream_process(char *out_file, char **cmd2, char **envp);
int		pipex(char **argv, char **envp);

#endif