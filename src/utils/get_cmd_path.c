/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 15:19:22 by rfoo              #+#    #+#             */
/*   Updated: 2026/05/30 17:14:24 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_all_paths(char **envp);
static char	*join_cmd_path(const char *dir, const char *cmd);

char	*get_cmd_path(char *cmd, char **envp)
{
	char	*all_paths;
	char	**paths;
	char	*cmd_path;

	all_paths = get_all_paths(envp);
	if (!all_paths)
		return (NULL);
	paths = ft_split(all_paths, ':');
	if (!paths)
		return (NULL);
	while (*paths)
	{
		cmd_path = join_cmd_path(*paths, cmd);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		paths++;
	}
	return (NULL);
}

static char	*get_all_paths(char **envp)
{
	char	*all_paths;

	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			all_paths = *envp + 5;
			break;
		}
		envp++;
	}
	if (!all_paths)
		return (NULL);
	return (all_paths);
}

static char	*join_cmd_path(const char *dir, const char *cmd)
{
	char	*partial_path;
	char	*cmd_path;

	partial_path = ft_strjoin(dir, "/");
	if (!partial_path)
		return (NULL);
	cmd_path = ft_strjoin(partial_path, cmd);
	free(partial_path);
	if (!cmd_path)
		return (NULL);
	return (cmd_path);
}
