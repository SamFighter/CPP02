#include "Point.hpp"

#define NONE	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"

void	print(Point a, Point b, Point c, Point p) {
	std::cout
		<< BLUE << "Coordinates: "
		<< "a(" << a.getX() << "," << a.getY() << ") "
		<< "b(" << b.getX() << "," << b.getY() << ") "
		<< "c(" << c.getX() << "," << c.getY() << ") "
		<< "p(" << p.getX() << "," << p.getY() << ")"
		<< NONE << std::endl << std::endl;
	if (bsp(a, b, c, p) == true)
		std::cout << GREEN << "The point lies in the triangle!" << NONE << std::endl;
	else
		std::cout << RED << "The point isn't in the triangle!" << NONE << std::endl;
	std::cout << std::endl;
}

int	main(void) {
	std::cout << YELLOW << "+--------+ POINT LIES IN THE TRIANGLE +--------+" << NONE << std::endl << std::endl;
	{
		Point	a1;
		Point	b1(0.0, 3.0);
		Point	c1(3.0, 0.0);
		Point	p1(1.0, 1.0);

		print(a1, b1, c1, p1);
	}
	std::cout << YELLOW << "+--------+ POINT ISN'T IN THE TRIANGLE +--------+" << NONE << std::endl << std::endl;
	{
		Point	a2;
		Point	b2(0.0, 3.0);
		Point	c2(3.0, 0.0);
		Point	p2(2.0, 2.0);
		print(a2, b2, c2, p2);
	}
	std::cout << YELLOW << "+--------+ POINT IS ON AN EDGE +--------+" << NONE << std::endl << std::endl;
	{
		Point	a3;
		Point	b3(0.0, 3.0);
		Point	c3(3.0, 0.0);
		Point	p3(1.0, 2.0);
		print(a3, b3, c3, p3);
	}
	std::cout << YELLOW << "+--------+ POINT IS A VERTEX +--------+" << NONE << std::endl << std::endl;
	{
		Point	a4;
		Point	b4(0.0, 3.0);
		Point	c4(3.0, 0.0);
		Point	p4(3.0, 0.0);
		print(a4, b4, c4, p4);
	}
}
