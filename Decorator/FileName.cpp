#include <iostream>
#include <string>

using namespace std;

// 차량 인터페이스
class CarInterface {
public:
	virtual string Option() = 0;
	virtual int Price() = 0;
};

// 기본 차량 클래스
class Car : public CarInterface
{
public:
	int Price() override { return 4000; }
	string Option() override { return "기본"; }
};

// 차량 데코레이터 클래스
class CarDecorator : public CarInterface
{
	CarInterface* carComponent;
public:
	CarDecorator(CarInterface* carComponent) : carComponent(carComponent) {}
	~CarDecorator() { if (carComponent) delete carComponent; }

	int Price() override { return (carComponent) ? carComponent->Price() : 0; }
	string Option() override { return (carComponent) ? carComponent->Option() : ""; }
};

// 블루투스 옵션 데코레이터 클래스
class BluetoothOption : public CarDecorator
{
public:
	BluetoothOption(CarInterface* carComponent) : CarDecorator(carComponent) {}

	int Price() override { return CarDecorator::Price() + 200; }
	string Option() override { return CarDecorator::Option() + " + Bluetooth Option Addition"; }
};

// 선루프 옵션 데코레이터 클래스
class SunroofOption : public CarDecorator
{
public:
	SunroofOption(CarInterface* carComponent) : CarDecorator(carComponent) {}

	int Price() override { return CarDecorator::Price() + 100; }
	string Option() override { return CarDecorator::Option() + " + Sunroof Option Addition"; }
};

int main()
{
	// 기본 차량 클래스에 옵션 클래스들 추가
	CarInterface* carComponent = new SunroofOption(new BluetoothOption(new Car));

	cout << "Price : " << carComponent->Price() << endl;
	cout << "Option : " << carComponent->Option() << endl;

	return 0;
}