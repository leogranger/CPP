#include "MutantStack.hpp"
#include "MutantStack.tpp"

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "the value at the top of stack : " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "the value at the top of stack : " << mstack.top() << std::endl;
	std::cout << "size of the stack : " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(55);
	mstack.push(737);
	mstack.push(0);
	mstack.push(22);
	std::cout << "the value at the top of stack :" << mstack.top() << std::endl;
	std::cout << "size of the stack : " << mstack.size() << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	std::cout << ".begin() -> " << *it << std::endl;
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << ".end() -> " << *ite << std::endl; //point after the last value // unbihavior comportement

	std::cout << "value of it before ++ -> " << *it << std::endl;
	++it;
	std::cout << "value of it after ++  & before -- -> " << *it << std::endl;
	--it;
	std::cout << "value of it after -- -> " << *it << std::endl;
	while (it != ite) // stop at he last cause ite is after the last value
	{
		std::cout << "Value in containers : " << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return (0);
}