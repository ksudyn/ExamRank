/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:07:58 by ksudyn            #+#    #+#             */
/*   Updated: 2025/11/17 18:46:25 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2::vect2()
{
    this->x = 0;
    this->y = 0;
}

vect2::vect2(int x, int y)
{
    this->x = x;
    this->y = y;
}

vect2::vect2(const vect2& other)
{
    this->x = other.x;
    this->y = other.y;
}

vect2& vect2::operator=(const vect2& other)
{
    if(this != &other)
    {
        this->x = other.x;
        this->y = other.y;
    }
    return *this;
}

vect2::~vect2()
{}


//Le da acceso por índice(permite modificar los vaores, por ejemplo to_print[0] y to_print[1])
int& vect2::operator[](int index)
{
	if (index == 0)
	{
		return this->x;
	}
	else
		return this->y;
	
}
//Le da acceso por índice( solo para lectura)
int vect2::operator[](int index) const
{
	if (index == 0)
	{
		return this->x;
	}
	else
		return this->y;
	
}

std::ostream& operator<<(std::ostream& out, const vect2& to_print)
{
    out << "{" << to_print[0] << ", " << to_print[1] << "}";
    return out;
}

// Pre-incremento: aumenta ambos componentes y devuelve *this.
//Si devuelve *this se le pasa referencia
vect2& vect2::operator++()
{
    this->x++;
    this->y++;
    return *this;
}

// Post-incremento: guarda copia, incrementa y devuelve la copia.
vect2 vect2::operator++(int)
{
    vect2 temp = *this;
    this->x++;
    this->y++;
    return temp;
}

//Pre-decremento: disminuye ambos componentes y devuelve *this.
//Si devuelve *this se le pasa referencia
vect2& vect2::operator--()
{
    this->x--;
    this->y--;
    return *this;
}

//Post-decremento: guarda copia, decrementa y devuelve la copipa.
vect2 vect2::operator--(int)
{
    vect2 temp = *this;
    this->x--;
    this->y--;
    return temp;
}

//Suma otro vector a este.
vect2& vect2::operator+=(const vect2& to_sum)
{
    this->x += to_sum.x;
    this->y += to_sum.y;
    return *this;
}

//Resta otro vector a este.
vect2& vect2::operator-=(const vect2& to_rest)
{
    this->x -= to_rest.x;
    this->y -= to_rest.y;
    return *this;
}

//Miltiplica ambos componente por to_mult.
vect2& vect2::operator*=(int to_mult)
{
    this->x *= to_mult;
    this->y *= to_mult;
    return *this;
}

// Devuelve nuevo vector multiplicado por un entero.(v * 2)
vect2 vect2::operator*(int to_mult) const
{
    vect2 temp = *this;
    temp.x = this->x * to_mult;
    temp.y = this->y * to_mult;
    return temp;
}

//Devuelve la suma de dos vectores.
vect2 vect2::operator+(const vect2& to_sum) const
{
    vect2 temp = *this;
    temp.x += to_sum.x;
    temp.y += to_sum.y;
    return temp;
}

//Devuelve la resta de dos vectores.
vect2 vect2::operator-(const vect2& to_rest) const
{
    vect2 temp = *this;
    temp.x -= to_rest.x;
    temp.y -= to_rest.y;
    return temp;
}

//Devuelve el vector opuesto.
vect2 vect2::operator-() const
{
    vect2 temp = *this;
    temp.x = -this->x;
    temp.y = -this->y;
    return temp;
}

//Devuelve true si los vectores son distintos y false si no.
bool vect2::operator!=(const vect2& no) const
{
    if(this->x != no.x || this->y != no.y)
        return (true);
    return false;
}

//Devuelve true si los vectores son iguales y false si no.
bool vect2::operator==(const vect2& yes) const
{
    if(this->x == yes.x && this->y == yes.y)
        return (true);
    return(false);
}

// Aqui se multiplica un numero por un vector cuando el número está a la izquierda (2 * v),
// antes se hace al reves y esta dentro de la clase, esto no.
// En esta multiplicacion se le da el valor a temp de to_mult
// luego temp se le da el valor de temp por el int que se le pasa y se retorna el resultado.
vect2 operator*(int num,const vect2& to_mult)
{
	vect2 temp(to_mult);
	temp *= num;
	return temp;
}


// Cuando trabajamos con this se le pone ->, cunado es con temp se pone .
// Recordar qe en las sumas y restas uno es += y otro solo + pero funcionan igual
// solo que + con temp y siendo const y += con la referencia