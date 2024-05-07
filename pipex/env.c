/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:39:23 by ngaulthi          #+#    #+#             */
/*   Updated: 2024/05/06 22:56:55 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int		is_path(char *str);
static char		*try_full_path(t_cmd *cmd, char *og_path);

char	*find_valid_path(t_cmd *cmd, char **current_cmd)
{
	int		i;
	char	*path;

	i = 0;
	if (current_cmd[0] == NULL)
		return (NULL);
	if (is_path(current_cmd[0]))
		return (try_full_path(cmd, current_cmd[0]));
	while (cmd->possible_paths[i])
	{
		path = ft_strjoin(cmd->possible_paths[i], "/");
		path = ft_join_free_s1(path, current_cmd[0]);
		if (!path)
			free_and_exit("malloc failed", cmd, 0);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

char	*try_full_path(t_cmd *cmd, char *og_path)
{
	char	*path;

	if (access(og_path, X_OK) == 0)
	{
		path = ft_strdup(og_path);
		if (!path)
			free_and_exit("malloc failed", cmd, 0);
		return (path);
	}
	return (NULL);
}

static int	is_path(char *str)
{
	if (str == NULL)
		return (0);
	if (ft_strlen(str) < 2)
		return (0);
	if (str[0] == '/')
		return (1);
	if (str[0] == '.' && str[1] == '/')
		return (1);
	return (0);
}

char	*find_path(char**envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}
