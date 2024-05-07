/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:18:57 by ngaulthi          #+#    #+#             */
/*   Updated: 2024/05/06 22:38:13 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <errno.h>

typedef struct s_cmd
{
	char	*valid_path;
	char	***command;
	int		pipe[2];
	char	*infile_fd;
	char	*outfile_fd;
	char	**possible_paths;
}	t_cmd;

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_join_free_s1(char *s1, char const *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);

void	init_all(char **argv, t_cmd *cmd, char **envp);
int		do_dup(t_cmd *cmd, int i);
int		child_process(t_cmd *cmd, char **envp, int *process_id, int i);
char	*find_path(char**envp);
char	*find_valid_path(t_cmd *cmd, char **current_cmd);
void	free_and_exit(char *err_msg, t_cmd *cmd, int i);
void	free_array(void **tab);
void	close_pipe(t_cmd *cmd);
void	free_all(t_cmd *cmd, int i);
void	free_triple(char ***big_array);

#endif