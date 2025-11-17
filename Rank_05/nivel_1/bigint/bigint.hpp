/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:45:19 by ksudyn            #+#    #+#             */
/*   Updated: 2025/11/17 20:31:30 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <stdexcept>
#include <sstream>
#include <iostream>

class bigint
{
private:
    std::string _str;

public:
    bigint();
    bigint(unsigned int n);
    bigint(const bigint& other);
    bigint& operator=(const bigint& other);
    ~bigint(); 

    std::string get_str() const;             // Devuelve el número como string
    void validate();                         // Elimina ceros a la izquierda del número

    bigint& operator<<=(unsigned int n);     // Desplaza a la izquierda en base 10 (multiplica por 10^n)
    bigint operator<<(unsigned int n) const; // Devuelve un nuevo bigint desplazado a la izquierda
    bigint& operator>>=(const bigint& obj);  // Desplaza a la derecha en base 10 (divide por 10^n)

    bigint operator+(const bigint& other) const; // Suma dos bigints
    bigint& operator+=(const bigint& other);     // Suma y asigna

    bigint& operator++();                     // Pre-incremento (++a)
    bigint operator++(int);                   // Post-incremento (a++)

    bool operator<(const bigint& obj);        // Compara menor que
    bool operator>(const bigint& obj);        // Compara mayor que
    bool operator==(const bigint& obj);       // Compara igualdad
    bool operator!=(const bigint& obj);       // Compara desigualdad
    bool operator<=(const bigint& obj);       // Compara menor o igual
    bool operator>=(const bigint& obj);       // Compara mayor o igual
};

// Permite imprimir el número con cout (en formato decimal sin ceros delante)
std::ostream& operator<<(std::ostream& out, const bigint& to_print);
