/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_of_life.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:21:27 by ksudyn            #+#    #+#             */
/*   Updated: 2025/11/18 14:27:32 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"

void printboard(char *board, int w, int h);
void step(char *board, char *next, int w, int h);
