/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:21:29 by ksudyn            #+#    #+#             */
/*   Updated: 2025/12/03 18:10:35 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

int main(int argc, char **argv)
{
    if (argc != 4) return 1;
    int w = atoi(argv[1]);
    int h = atoi(argv[2]);
    int it = atoi(argv[3]);
    struct game_of_life *g = game_init(w, h, it);
    if (!g) return 1;
    game_read_input(g);
    for (int i = 0; i < g->iterations; ++i) step_once(g);
    game_print(g);
    game_free(g);
    return 0;
}
