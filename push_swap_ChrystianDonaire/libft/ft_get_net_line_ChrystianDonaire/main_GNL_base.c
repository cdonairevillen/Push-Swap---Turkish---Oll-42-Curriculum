/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_GNL_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:55:10 by cdonaire          #+#    #+#             */
/*   Updated: 2025/10/23 17:56:32 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main ()
{
	int		fd;
	char	*str;

	fd = open("ex.txt", O_RDONLY);
	if(!fd)
		return (-1);
	printf("%d", fd);
	while(1)
	{
		getchar();
		str = get_next_line(fd);
		if (!str)
			break;
		printf("%s", str);
		free (str);
	}
	close(fd);
}
