/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:08:01 by ksudyn            #+#    #+#             */
/*   Updated: 2025/11/17 19:00:54 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class vect2
{
    private:
        int x;
        int y;
    public:
        vect2();
        vect2(int x, int y);
        vect2(const vect2& other);
        vect2& operator=(const vect2& other);
        ~vect2();

        int operator[](int index) const;
		int& operator[](int index);
        
        vect2& operator++();
        vect2 operator++(int);

        vect2& operator--();
        vect2 operator--(int);

        vect2& operator+=(const vect2& to_sum);
        vect2& operator-=(const vect2& to_rest);

        vect2& operator*=(int to_mul);
        vect2 operator*(int to_mult) const;

        vect2 operator+(const vect2& to_sum) const;
        vect2 operator-(const vect2& to_rest) const;

        vect2 operator-() const;

        bool operator!=(const vect2& no) const;
        bool operator==(const vect2& yes) const;
};
vect2 operator*(int num, const vect2& to_mult);
std::ostream& operator<<(std::ostream& out, const vect2& to_print);