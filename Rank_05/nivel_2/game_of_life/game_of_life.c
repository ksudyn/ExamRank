/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_of_life.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:21:24 by ksudyn            #+#    #+#             */
/*   Updated: 2025/12/30 20:05:37 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static void printboard(char *board, int width, int height)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (board[y * width + x])
				putchar('0');
			else
				putchar(' ');
		}
		putchar('\n');
	}
}

/* Cuenta los vecinos vivos de la celda (col, row).
   Las posiciones fuera del tablero son muertas */
static int count_neighbor(char *board, int width, int height, int x, int y)
{
	int count = 0;
	for (int dy = -1; dy <= 1; dy++)
	{
		for (int dx = -1; dx <= 1; dx++)
		{
			if (dy == 0 && dx == 0)
				continue;
			int neighbor_x = x + dx;
			int neighbor_y = y + dy;
			if(neighbor_x >= 0 && neighbor_x < width &&
				neighbor_y >= 0 && neighbor_y < height)
			{
				count += board[neighbor_y * width + neighbor_x];
			}
		}
	}
	return count;
}

static void step(char *board, char * next_board, int width, int height)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int n = count_neighbor(board, width, height, x, y);
			if (board[y * width + x])//fila * ancho + columna
			{
				if (n == 2 || n == 3)
					next_board[y * width + x] = 1;
				else
					next_board[y * width + x] = 0;
			}
			else
			{
				if (n == 3)
					next_board[y * width + x] = 1;
				else
					next_board[y * width + x] = 0;
			}
		}
	}
}

int main(int ac, char **av)
{
	if(ac != 4)
		return 1;

	int width = atoi(av[1]);
	int height = atoi(av[2]);
	int iter = atoi(av[3]);

	char *board = calloc(width * height, 1);
	char *next_board = calloc(width * height, 1);

	if(!board || !next_board)
		return 1;

	int x = 0, y = 0, pencil = 0;
	char c;

	while (read(0, &c, 1) > 0)
	{
		if(c == 'x')
			pencil = !pencil;
		if(c == 'a' && x > 0)
			x--;
		else if(c == 'd' && x < width -1)
			x++;
		else if(c == 'w' && y > 0)
			y--;
		else if(c == 's' && y < height -1)
			y++;
		if(pencil)
			board[y * width + x] = 1;
	}

	for(int i = 0; i < iter; i++)
	{
		step(board, next_board, width, height);
		char *temp = board;
		board = next_board;
		next_board = temp;
	}
	
	printboard(board, width, height);
	free(board);
	free(next_board);
	return 0;
}
