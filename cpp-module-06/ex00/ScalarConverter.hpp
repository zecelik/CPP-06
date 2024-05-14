#ifndef SCALAR_HPP_
# define SCALAR_HPP_

# include <string>

class ScalarConverter {
	public:
		~ScalarConverter();

		static void convert(const std::string& literal);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);

		//static bool tryChar(const std::string& literal);
		//static bool tryInt(const std::string& literal);
		//static bool tryFloat(const std::string& literal);
		//static bool tryDouble(const std::string& literal);
};

#endif
