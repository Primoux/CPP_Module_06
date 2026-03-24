#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
  private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(ScalarConverter const &original);
	ScalarConverter &operator=(ScalarConverter const &other);

  public:
	static void convert(std::string const &s);
};
// std::ostream &operator<<(std::ostream &o, const ScalarConverter &obj);
#endif // !SCALARCONVERTER_HPP