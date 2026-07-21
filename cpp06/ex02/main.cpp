#include "Base/Base.hpp"

Base*	generate(void)
{
	Base	*p;
	int	randomNb = rand() % 3;

	switch (randomNb)
	{
		case 0:
			p = new A;
			break ;
		case 1:
			p = new B;
			break ;
		case 2:
			p = new C;
			break ;
	}
	return (p);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "It is A." << std::endl;
		return;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "It is B." << std::endl;
		return;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "It is C." << std::endl;
		return;
	}
}

void	identify(Base& p)
{
	try{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "It is A." << std::endl;
	}
	catch (std::exception& e){}
	try{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "It is B." << std::endl;
	}
	catch (std::exception& e){}
	try{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "It is C." << std::endl;
	}
	catch (std::exception& e){}
}

int	main(void)
{
	std::srand(std::time(NULL));

	Base *p = generate();
	Base &r = *p;

	identify(p);
	identify(r);

	delete (p);
	return(0);
}