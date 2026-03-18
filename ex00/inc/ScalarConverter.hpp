#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
  private:
	

  public:
	// CONSTRUCTOR
	// ScalarConverter();
	// ~ScalarConverter();
	// ScalarConverter(ScalarConverter const &original);

	// OPERATOR
	// ScalarConverter &operator=(ScalarConverter const &other);
	// MEMBER FUNCTION
	static void convert(std::string const &s);
	// EXCEPTIONS
	class intOverflow : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
};
// std::ostream &operator<<(std::ostream &o, const ScalarConverter &obj);
#endif // !SCALARCONVERTER_HPP