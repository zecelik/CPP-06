#include <iostream>
#include <stdint.h>

struct Data {
	int n;
};

uintptr_t serialize(Data *ptr) { //serialize fonksiyonu, Data tipinde bir pointer alır ve bu pointer'ı uintptr_t tipine dönüştürür. Bu, pointer'ın hafıza adresini bir tam sayıya dönüştürür.
	return reinterpret_cast<uintptr_t>(ptr);
}
//uintptr_t bir pointer'ı bir tamsayıya dönüştürmek için kullanılır, böylece pointer'ın değeri üzerinde tamsayı işlemleri yapabilirsiniz.
Data* deserialize(uintptr_t raw) { //deserialize fonksiyonu, uintptr_t tipinde bir tam sayı alır ve bu tam sayıyı Data tipinde bir pointer'a dönüştürür. Bu, tam sayıyı bir hafıza adresine dönüştürür.
	return reinterpret_cast<Data*>(raw); //raw adlı uintptr_t türündeki bir tam sayıyı Data* türündeki bir işaretçiye dönüştürür. Bu, raw'ın bir Data nesnesinin hafıza adresini temsil ettiğini varsayar.
}//reinterpret_cast, bir türü başka bir türe dönüştürmek için kullanılır. Bu, bir türü başka bir türe dönüştürmek için güvenli bir şekilde kullanılabilir.

int main() {
	Data* data;
	uintptr_t rawData;
	Data* retData;

	data = new Data;

	std::cout << "Data             : " << data << std::endl;
	rawData = serialize(data);
	std::cout << "Raw data         : " << rawData << std::endl;
	retData = deserialize(rawData);
	std::cout << "Deserialized data: " << retData << std::endl;

	delete data;

	return 0;
}
