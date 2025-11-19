/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:45:25 by ksudyn            #+#    #+#             */
/*   Updated: 2025/11/19 20:41:53 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"

//Quita los ceros iniciales
void bigint::validate()
{
    if (this->_str.empty())
	{
		return ;
	}
    int i = 0;
    while(this->_str[i] && this->_str[i] == '0')
        i++;
    if( i > 0)
        this->_str.erase(0, i);
    //Con el erase se elimina los '0' i caracteres
}

bigint::bigint()
{
    this->_str = "0";
}

// Constructor desde un entero -> convierte el número a string
bigint::bigint(unsigned int n)
{
    if(n == 0)
    {
        this->_str = "0";
        return;
    }
    std::ostringstream os;
    os << n;
    this->_str = os.str();
    validate();
}

bigint::bigint(const bigint& other)
{
    this->_str = other._str;
}

bigint& bigint::operator=(const bigint& other)
{
    if(this != &other)
    {
        this->_str = other._str;
    }
    return *this;
}

bigint::~bigint()
{}

//Añade 0 al final, es como multiplicar por 10
//Al tener referencia modifica el objeto actual (*this), no crea uno nuevo
bigint& bigint::operator<<=(unsigned int n)
{
    if(this->_str == "0")
    {
        return *this;
    }

    this->_str.append(n, '0');
    return *this;
}

//Suma dos digito y devueleve el resultado
//Hace una atoi y un itoa en la misma funcion
bigint bigint::operator+(const bigint& other) const
{
    std::string num_1 = this->_str;
    std::string num_2 = other._str;
    std::string result = "";
    
    int i = num_1.size() - 1;
    int j = num_2.size() - 1;
    int rest = 0;

    while(i >= 0 || j >= 0 || rest)
    {
        int num_i = (i >= 0) ? num_1[i] - '0' : 0;
        int num_j = (j >= 0) ? num_2[j] - '0' : 0;

        int sum = num_i + num_j + rest;
        rest = sum /10;
        result.insert(result.begin(), char(sum % 10) + '0');
        j--;
        i--;
    }
    bigint temp;
    temp._str = result;
    return (temp);
}

//Suma otro bigint a este
bigint& bigint::operator+=(const bigint& other)
{
    *this = *this + other;

    return *this;
}

// Pre-incremento (++a) -> suma 1 y devuelve referencia
bigint& bigint::operator++()
{
    *this = *this + bigint(1);

    return *this;
}

// Post-incremento (a++) -> guarda copia, suma 1 y devuelve la copia original
bigint bigint::operator++(int)
{
    bigint temp = *this;
    *this += bigint(1);

    return temp;
}

//Añade 0 al final, es como multiplicar por 10
//Al no tener referencia crea un objeto (temp) y devuelve un nuevo bigint con el resultado.
bigint bigint::operator<<(unsigned int nbr) const
{
    bigint temp = *this;
    temp._str.append(nbr, '0');
    return temp;
}

// Convierte string numérico a número entero (solo para pequeños shifts)
static unsigned long long str_to_number(std::string str)
{
	unsigned long long result = 0;
	if (str.empty())
	{
		return 0;
	}
	for (size_t i = 0; i < str.size(); i++)
	{
		result = result * 10 + str[i] -'0';
	}
	return result;
	
}

//“Desplaza” a la derecha en base 10, o sea, quita shift dígitos del final del número.
//Equivale a dividir por 10ⁿ (solo que sin decimales).
//Al tener referencia modifica el objeto actual (*this), no crea uno nuevo
bigint& bigint::operator>>=(const bigint& obj)
{
    unsigned long long shift = str_to_number(obj._str);     // cuántas posiciones borrar
    size_t len = this->_str.size();                         // longitud actual

    // si pide borrar tantas o más posiciones que la longitud -> resultado 0
    if (shift >= len)
    {
        this->_str = "0";
        return *this;
    }

    // borrar exactamente 'shift' caracteres desde el final
    this->_str.erase(this->_str.size() - shift, this->_str.size());
    return *this;
}



bool bigint::operator<(const bigint& obj)
{
	if (this->_str.size() < obj._str.size())
	{
		return true;
	}
	return false;
	
}

bool bigint::operator>(const bigint& obj)
{
	if (this->_str.size() > obj._str.size())
	{
		return true;
	}
	return false;
}

bool bigint::operator==(const bigint& obj)
{
	if (this == &obj)
	{
		return true;
	}
	return false;
}

bool bigint::operator!=(const bigint& obj)
{
	if (this != &obj)
	{
		return true;
	}
	return false;
}

bool bigint::operator<=(const bigint& obj)
{
	if ((this < &obj) || this == &obj)
	{
		return true;
	}
	return false;
	
}

bool bigint::operator>=(const bigint& obj)
{
	if ((this > &obj) || this == &obj)
	{
		return true;
	}
	return false;
}

// Devuelve la cadena del número
std::string bigint::get_str() const
{
    return this->_str;
}

// Permite imprimir el número sin ceros a la izquierda
std::ostream& operator<<(std::ostream& out, const bigint& to_print)
{
    out << to_print.get_str();
    return out;
}