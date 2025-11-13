/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:45:23 by ksudyn            #+#    #+#             */
/*   Updated: 2025/11/13 19:02:58 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"


int main()
{ 
	const bigint a(42);
	bigint b(21), c, d(1337), e(d);

	std::cout << "(c <<= 10) = " << (c <<= 10) << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "(c += a) = " << (c += a) << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "++b = " << ++b << std::endl;
	std::cout << "b++ = " << b++ << std::endl;
	std::cout << "(b << 10) + 42 = " << (b << 10) + 42 << std::endl;
	std::cout << "(d <<= 4) = " << (d <<= 4) << std::endl;
	std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "(d < a) = " << (d < a) << std::endl;
	std::cout << "(d > a) = " << (d > a) << std::endl;
	std::cout << "(d == a) = " << (d == a) << std::endl;
	std::cout << "(d != a) = " << (d != a) << std::endl;
	std::cout << "(d <= a) = " << (d <= a) << std::endl;
	std::cout << "(d >= a) = " << (d >= a) << std::endl;
}