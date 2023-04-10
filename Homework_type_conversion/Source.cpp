#include <iostream>


class Car {};
class Van : public Car {};

int main() {

	//���� ��������� �������������� double � int ��������, �� ���������� ������ ���������� �����, ��� ��� ��� ������ int ����� ������������ �������� ��������. 
	//�� ����� ����� �������� ����� - 2147483648. 
	/*��� ���������� �� - �� ����, ��� ��� int �������� 4 ����� � ������, � double - 8 ����.
		����� ����� ���� double ������������� � int, ���������� ��������� ������ 4 ������, 
		������� �� ����� ���� ������������ � int, � ����� ���������� 4 ����� ���������������� ��� ����� � ������� int.*/
	double i = 32200030001.1;
	int j = i;
	std::cout << j << std::endl;

	//��� ������ ������������� � ��������� �� double ����� ������������ const_cast:
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


    //����� ��������� �������:

   /* �������� � ���������� ����.
        �������� � ����������� ��������� ������, ��������� ������������ ��������� �������, �� �������� ��.
        ������ ������ �� ������, ��������� ������ ����� ����� ���� ������� ���������, � ����� ����������� �������� ���� ����� ��� ������� �� ������.
        
     ������ ��������� ������� :

    ������� ����� ������������ �������� ���� �� �����, ��� ��������� �� ��������������.
        ������������� ��������� ��������� ������ ��������.
        ����� ���������� ������� :

    ����������� �������������� ������ ����������, ��������� ���������������� ���������� �������.*/
    return 0;
}