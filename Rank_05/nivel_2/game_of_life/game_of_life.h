/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_of_life.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:21:27 by ksudyn            #+#    #+#             */
/*   Updated: 2025/12/03 17:38:13 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdlib.h>
#include <unistd.h> /* read */
#include <stdint.h> /* uint8_t */
#include <limits.h> /* SIZE_MAX */
#include <stdbool.h>
#include <stdio.h>

//-----------------------------------------------------------
//  ESTRUCTURA PRINCIPAL DEL JUEGO
//-----------------------------------------------------------
struct game_of_life
{
    size_t width;
    size_t height;
    size_t cursor_x;
    size_t cursor_y;
    bool pen_down;
    int iterations;
    uint8_t *grid; /* width * height bytes, 0 o 1 */
    uint8_t *next; /* buffer temporal para el siguiente paso */
};

void game_free(struct game_of_life *g);
void game_print(const struct game_of_life *g);
void game_read_input(struct game_of_life *g);
void step_once(struct game_of_life *g);
struct game_of_life *game_init(int w, int h, int iter);
