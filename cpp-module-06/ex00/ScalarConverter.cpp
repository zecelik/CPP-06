#include "ScalarConverter.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { *this = other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }

void ScalarConverter::convert(const std::string& literal) 
{
	std::string specialTypes[6] = {
		"-inff", "+inff", "nanf", //-inff ve -inf: Negatif sonsuzluk. Bir sayının değeri negatif sonsuzluğa giderse, bu değerler kullanılır. -inff float türü için, -inf ise double türü için kullanılır.
		"-inf", "+inf", "nan" //+inff ve +inf: Pozitif sonsuzluk. Bir sayının değeri pozitif sonsuzluğa giderse, bu değerler kullanılır. +inff float türü için, +inf ise double türü için kullanılır.
		//nanf ve nan: Not a Number (Sayı Değil). (örneğin 0'a bölme) veya sonuç sayısal bir değeri temsil edemezse, nanf float türü için, nan ise double türü için kullanılır.

	};
	std::string toChar = ""; 
	int toInt = 0; 
	float toFloat = 0;
	double toDouble = 0;

	//if is a char
	if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) { //stringin tek karakter olup olmadığını kontrol eder ve karakterin basılabilir olup olmadığını kontrol eder ve karakterin sayısal olup olmadığını kontrol eder
		toChar = literal[0]; 
		std::cout << "char1: " << toChar << std::endl;
		std::cout << "int1: " << static_cast<int>(toChar[0]) << std::endl; //static_cast C++'ta bir tür dönüşüm operatörüdür.
		std::cout << "float1: " << static_cast<float>(toChar[0]) << ".0f" << std::endl;
		std::cout << "double1: " << static_cast<double>(toChar[0]) << ".0" << std::endl;
		return;
	}
   
	toInt = std::atoi(literal.c_str()); //c_str s stringe dönüştürür atoi fonksiyonu stringi int türüne dönüştürür

	// check if it is float or int / double
	if (literal[literal.length() - 1] == 'f') {
		toFloat = std::atof(literal.c_str()); // atof fonksiyonu stirngi double türüne dönüştürür sonran tofloata atarak otomatik floata dönüştürür
		toDouble = static_cast<double>(toFloat);
	} else {
		toDouble = std::atof(literal.c_str());
		toFloat = static_cast<float>(toDouble);
	}

	for (int i = 0; i < 6; ++i) {
		if (literal == specialTypes[i]) { //specialTypes dizisindeki herhangi biriyle eşleşirse toChar'ı "imposible" yapar. çünkü birv sayıyı temsil etmediğiiçin char türüne dönüştürülemez.
			toChar = "imposible"; break;
		}
	}
	
	if (toChar == "" && std::isprint(toInt)) { //toChar'ın boş olup olmadığını ve toInt'in yazdırılabilir bir karakter olup olmadığını kontrol eder.
		toChar = "'"; //tek tırnak ekler
		toChar += static_cast<char>(toInt); 
		toChar += "'";
	} 
	else if (toChar == "") {
		toChar = "Non displayable";
	}


	std::cout << "char2: " << toChar << std::endl; 
	if (toChar == "imposible") { //./out nanf
		std::cout << "int2: imposible" << std::endl;
	} 
	else 
		std::cout << "int3: " << toInt << std::endl;
	
	
		if (toChar != "imposible") {
			std::cout << "float2: " << toFloat << ".0f" << std::endl;
			std::cout << "double2: " << toDouble << ".0" << std::endl;
		} else {
			std::cout << "float3: " << toFloat << "f" << std::endl;
			std::cout << "double3: " << toDouble << std::endl;
		}
	
	
}
