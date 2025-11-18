/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:21:29 by ksudyn            #+#    #+#             */
/*   Updated: 2025/11/18 15:59:40 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

int main(int ac, char **av)
{
	if(ac != 4)
		return 1;

	int w = atoi(av[1]);
	int h = atoi(av[2]);
	int iter = atoi(av[3]);

	char *board = calloc(w*h, 1);
	char *next = calloc(w*h, 1);

	if(!board || !next)
		return 1;

	int x = 0, y = 0, pen = 0;
	char c;

	while (read(0, &c, 1) > 0)
	{
		if(c == 'x')
			pen = !pen;
		if(c == 'a' && x > 0)
			x--;
		else if(c == 'd' && x < w -1)
			x++;
		else if(c == 'w' && y > 0)
			y--;
		else if(c == 's' && y < h -1)
			y++;
		if(pen)
			board[y * w + x] = 1;
	}

	for(int i = 0; i < iter; i++)
	{
		step(board, next, w, h);
		char *temp = board;
		board = next;
		next = temp;
	}
	
	printboard(board, w, h);
	free(board);
	free(next);
	return 0;
}
