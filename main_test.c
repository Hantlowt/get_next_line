/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 13:16:47 by alhote            #+#    #+#             */
/*   Updated: 2016/02/08 09:59:06 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	int		fd[argc];
	char	*line[argc];
	int		i;

	i = 1;
	while (i < argc)
	{
		fd[i] = open(argv[i], 0);
		++i;
	}
	i = 1;
	while (i < argc)
	{
		while (get_next_line(fd[i], &line[i]))
			ft_putendl(line[i]);
		++i;
	}
	i = 1;
	while (i < argc)
	{
		close(fd[i]);
		++i;
	}
	return (0);
}
