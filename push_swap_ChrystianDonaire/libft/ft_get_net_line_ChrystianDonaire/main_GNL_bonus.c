/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_GNL_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:57:09 by cdonaire          #+#    #+#             */
/*   Updated: 2025/10/23 17:57:31 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int     fd1;
    int     fd2;
    int     fd3;
    char    *line1;
    char    *line2;
    char    *line3;

    fd1 = open("ex.txt", O_RDONLY);
    fd2 = open("ex2.txt", O_RDONLY);
    fd3 = open("ex3.txt", O_RDONLY);

    if (fd1 < 0 || fd2 < 0 || fd3 < 0)
        return (-1);
    while (1)
    {
        getchar();

        line1 = get_next_line(fd1);
        line2 = get_next_line(fd2);
        line3 = get_next_line(fd3);

        if (!line1 && !line2 && !line3)
            break;
        if (line1)
        {
            printf("FD1: %s", line1);
            free(line1);
        }
        if (line2)
        {
            printf("FD2: %s", line2);
            free(line2);
        }
        if (line3)
        {
            printf("FD3: %s", line3);
            free(line3);
        }
    }
    close(fd1);
    close(fd2);
    close(fd3);
}
