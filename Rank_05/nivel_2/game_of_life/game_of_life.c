/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_of_life.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:21:24 by ksudyn            #+#    #+#             */
/*   Updated: 2025/11/18 15:59:19 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

static int count_neighbor(char *board, int w, int h, int x, int y)
{
    int cnt = 0;
	for (int dy = -1; dy <= 1; dy++)
	{
        for (int dx = -1; dx <= 1; dx++)
		{
            if (dy == 0 && dx == 0)
				continue;
			int nx = x + dx;
			int ny = y + dy;
			if(nx >= 0 && nx < w && ny >= 0 && ny < h)
            cnt += board[ny * w + nx];
		}
	}
	return cnt;
}

void printboard(char *board, int w, int h)
{
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            if (board[y * w + x])
                putchar('0');
            else
                putchar(' ');
        }
        putchar('\n');
    }
}

void step(char *board, char * next, int w, int h)
{
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			int n = count_neighbor(board, w, h, x, y);
			if (board[y * w + x])
			{
				if (n == 2 || n == 3)
					next[y * w + x] = 1;
				else
					next[y * w + x] = 0;
			}
			else
			{
				if (n == 3)
					next[y * w + x] = 1;
				else
					next[y * w + x] = 0;
			}
		}
	}
}
