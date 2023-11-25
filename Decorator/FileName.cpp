#include <iostream>
#include <string>

using namespace std;

// ���� �������̽�
class CarInterface {
public:
	virtual string Option() = 0;
	virtual int Price() = 0;
};

// �⺻ ���� Ŭ����
class Car : public CarInterface
{
public:
	int Price() override { return 4000; }
	string Option() override { return "�⺻"; }
};

// ���� ���ڷ����� Ŭ����
class CarDecorator : public CarInterface
{
	CarInterface* carComponent;
public:
	CarDecorator(CarInterface* carComponent) : carComponent(carComponent) {}
	~CarDecorator() { if (carComponent) delete carComponent; }

	int Price() override { return (carComponent) ? carComponent->Price() : 0; }
	string Option() override { return (carComponent) ? carComponent->Option() : ""; }
};

// ������� �ɼ� ���ڷ����� Ŭ����
class BluetoothOption : public CarDecorator
{
public:
	BluetoothOption(CarInterface* carComponent) : CarDecorator(carComponent) {}

	int Price() override { return CarDecorator::Price() + 200; }
	string Option() override { return CarDecorator::Option() + " + Bluetooth Option Addition"; }
};

// ������ �ɼ� ���ڷ����� Ŭ����
class SunroofOption : public CarDecorator
{
public:
	SunroofOption(CarInterface* carComponent) : CarDecorator(carComponent) {}

	int Price() override { return CarDecorator::Price() + 100; }
	string Option() override { return CarDecorator::Option() + " + Sunroof Option Addition"; }
};

int main()
{
	// �⺻ ���� Ŭ������ �ɼ� Ŭ������ �߰�
	CarInterface* carComponent = new SunroofOption(new BluetoothOption(new Car));

	cout << "Price : " << carComponent->Price() << endl;
	cout << "Option : " << carComponent->Option() << endl;

	return 0;
}