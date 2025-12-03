/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_of_life.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:21:24 by ksudyn            #+#    #+#             */
/*   Updated: 2025/12/03 18:03:23 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

/* game_of_life_clean.c
   Versión refactorizada y corregida, con struct y buffers contiguos.
   Funciones usadas: atoi, read, putchar, malloc/calloc, free.
*/

//-----------------------------------------------------------
//  SEGURIDAD: Multiplicación segura para evitar overflow
//-----------------------------------------------------------

static bool safe_mul_size(size_t a, size_t b, size_t *out)
{
    if (a == 0 || b == 0) {
        *out = 0;
        return true;
    }
    if (a > SIZE_MAX / b)   // overflow
        return false;

    *out = a * b;
    return true;
}


//-----------------------------------------------------------
//  INICIALIZACIÓN
//-----------------------------------------------------------

struct game_of_life *game_init(int w, int h, int iter)
{
    if (w <= 0 || h <= 0 || iter < 0)
        return NULL;

    struct game_of_life *g = malloc(sizeof(*g));
    if (!g)
        return NULL;

    g->width = (size_t)w;
    g->height = (size_t)h;
    g->cursor_x = 0;
    g->cursor_y = 0;
    g->pen_down = false;
    g->iterations = iter;

    // tamaño total del tablero
    size_t cells;
    if (!safe_mul_size(g->width, g->height, &cells)) {
        free(g);
        return NULL;
    }

    // calloc → tablero inicial todo muerto
    g->grid = calloc(cells, 1);
    g->next = calloc(cells, 1);
    if (!g->grid || !g->next) {
        free(g->grid);
        free(g->next);
        free(g);
        return NULL;
    }
    return g;
}


//-----------------------------------------------------------
//  CONTAR VECINOS
//-----------------------------------------------------------

static int count_neighbors(const struct game_of_life *g, size_t x, size_t y)
{
    int cnt = 0;
    for (int dy = -1; dy <= 1; ++dy)
	{
        for (int dx = -1; dx <= 1; ++dx)
		{
            if (dx == 0 && dy == 0)
				continue;

            ssize_t nx = (ssize_t)x + dx;
            ssize_t ny = (ssize_t)y + dy;

            if (nx >= 0 && ny >= 0 && (size_t)nx < g->width && (size_t)ny < g->height)
			{
                cnt += g->grid[ (size_t)ny * g->width + (size_t)nx ];
            }
        }
    }
    return cnt;
}


//-----------------------------------------------------------
//  UNA ITERACIÓN DEL JUEGO DE LA VIDA
//-----------------------------------------------------------

void step_once(struct game_of_life *g)
{
    for (size_t y = 0; y < g->height; y++)
	{
        for (size_t x = 0; x < g->width; x++)
		{
            int n = count_neighbors(g, x, y);
            uint8_t alive = g->grid[y * g->width + x];
            g->next[y * g->width + x] = (alive ? (n == 2 || n == 3) : (n == 3));
        }
    }
    /* swap buffers */
    uint8_t *tmp = g->grid;
    g->grid = g->next;
    g->next = tmp;
}


//-----------------------------------------------------------
//  LECTURA DE COMANDOS Y DIBUJO
//-----------------------------------------------------------

void game_read_input(struct game_of_life *g)
{
    char c;
    while (read(0, &c, 1) > 0)
	{
        if (c == 'x')
		{
            g->pen_down = !g->pen_down;
            if (g->pen_down) g->grid[g->cursor_y * g->width + g->cursor_x] = 1;
        }
		else if (c == 'a')
		{
            if (g->cursor_x > 0) g->cursor_x--;
        }
		else if (c == 'd')
		{
            if (g->cursor_x + 1 < g->width) g->cursor_x++;
        } else if (c == 'w')
		{
            if (g->cursor_y > 0) g->cursor_y--;
        } else if (c == 's')
		{
            if (g->cursor_y + 1 < g->height) g->cursor_y++;
        }

		// si el lápiz está activo, marca la celda
        if (g->pen_down)
			g->grid[g->cursor_y * g->width + g->cursor_x] = 1;
    }
}

//-----------------------------------------------------------
//  IMPRIMIR TABLERO
//-----------------------------------------------------------
void game_print(const struct game_of_life *g)
{
    for (size_t y = 0; y < g->height; y++)
	{
        for (size_t x = 0; x < g->width; x++)
		{

            if (g->grid[y * g->width + x])
                putchar('0');
            else
                putchar(' ');
        }
        putchar('\n');
    }
}

//-----------------------------------------------------------
//  LIBERACIÓN DE MEMORIA
//-----------------------------------------------------------
void game_free(struct game_of_life *g)
{
    if (!g) return;
    free(g->grid);
    free(g->next);
    free(g);
}
