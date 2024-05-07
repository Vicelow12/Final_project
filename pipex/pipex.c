/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:17:04 by ngaulthi          #+#    #+#             */
/*   Updated: 2024/05/06 22:18:36 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_all(char **argv, t_cmd *cmd, char **envp)
{
	if (pipe(cmd->pipe) == -1)
		perror("Failed to create pipe");
	cmd->possible_paths = ft_split(find_path(envp), ':');
	if (!cmd->possible_paths)
		free_and_exit("failed to find PATH=", cmd, 1);
	cmd->infile_fd = argv[1];
	cmd->outfile_fd = argv[4];
	cmd->command = malloc(sizeof(char **) * 3);
	if (!cmd->command)
		free_and_exit("failed to malloc", cmd, 1);
	cmd->command[0] = ft_split(argv[2], ' ');
	cmd->command[1] = ft_split(argv[3], ' ');
	cmd->command[2] = NULL;
	if (!cmd->command[0] || !cmd->command[1])
		free_and_exit("failed to malloc", cmd, 1);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	cmd;
	pid_t	process_id[2];
	int		status;
	int		i;

	if (argc != 5)
		return (perror("error\ninvalid number of arguments"), 1);
	ft_memset(&cmd, 0, sizeof(cmd));
	init_all(argv, &cmd, envp);
	i = 0;
	while (i < 2)
	{
		child_process(&cmd, envp, &process_id[i], i);
		i++;
	}
	close_pipe(&cmd);
	i = 0;
	while (i < 2)
	{
		if (waitpid(process_id[i], &status, 0) == -1)
			free_and_exit("Waitpid failed", &cmd, 0);
		i++;
	}
	free_all(&cmd, 0);
	return (status);
}
