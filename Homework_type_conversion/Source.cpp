#include <iostream>


class Car {};
class Van : public Car {};

int main() {

	//Если выполнить преобразование double в int напрямую, то произойдет потеря значимости числа, так как тип данных int имеет ограниченный диапазон значений. 
	//На экран будет выведено число - 2147483648. 
	/*Это происходит из - за того, что тип int занимает 4 байта в памяти, а double - 8 байт.
		Когда число типа double преобразуется в int, происходит обрезание первых 4 байтов, 
		которые не могут быть представлены в int, а затем оставшиеся 4 байта интерпретируются как число в формате int.*/
	double i = 32200030001.1;
	int j = i;
	std::cout << j << std::endl;

	//Для снятия константности с указателя на double можно использовать const_cast:
	const double* pd;
	double* pd_nc = const_cast<double*>(pd);

    Van van;

    // Upcast
    Car* car_ptr = &van;

    // Successful downcast
    Van* van_ptr = dynamic_cast<Van*>(car_ptr);

    // Unsuccessful downcast with pointer
    Car* car_ptr2 = new Car();
    Van* van_ptr2 = dynamic_cast<Van*>(car_ptr2);
    if (van_ptr2 == nullptr) {
        std::cout << "Downcast failed with pointer" << std::endl;
    }

    // Unsuccessful downcast with reference
    Car& car_ref = van;
    try {
        Van& van_ref = dynamic_cast<Van&>(car_ref);
    }
    catch (std::bad_cast& e) {
        std::cout << "Downcast failed with reference" << std::endl;
    }

    // Undefined behavior downcast
    //Car* car_ptr3 = new Van();
    //Van* van_ptr3 = static_cast<Van*>(car_ptr3);
    //delete car_ptr3;
    //van_ptr3->some_method();  // undefined behavior


    //Плюсы агрегации классов:

   /* Простота и понятность кода.
        Гибкость и возможность создавать классы, способные использовать различные объекты, не наследуя их.
        Лучшая защита от ошибок, поскольку каждый класс имеет свою область видимости, а также возможность изменять один класс без влияния на другой.
        
     Минусы агрегации классов :

    Объекты могут существовать отдельно друг от друга, что усложняет их взаимодействие.
        Необходимость управлять жизненным циклом объектов.
        Плюсы композиции классов :

    Возможность предоставления нового интерфейса, объединяя функциональность нескольких классов.*/
    return 0;
}