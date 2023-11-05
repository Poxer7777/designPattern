#include <iostream>
using namespace std;

/*
 Abstract Product들은 제품 패밀리를 구성하는 개별 연관 Product들의 집합에 대한 인터페이스들을 선언한다.
*/
class AbstractProductA {
public:
    virtual ~AbstractProductA() {};
    virtual string UsefulFunctionA() const = 0;
};

/*
 Concrete Product들은 변형들로 그룹화된 Abstract Product들의 다양한 구현들이다.
 각 Abstract Product는 주어진 모든 변형에 구현되어야 한다.
*/
class ConcreteProductA1 : public AbstractProductA {
public:
    string UsefulFunctionA() const override {
        return "The result of the product A1.";
    }
};

class ConcreteProductA2 : public AbstractProductA {
    string UsefulFunctionA() const override {
        return "The result of the product A2.";
    }
};

/*
 모든 Product는 상호작용이 가능하지만 동일한 Concrete Product간에만 가능하다.
*/
class AbstractProductB {
public:
    virtual ~AbstractProductB() {};
    virtual string UsefulFunctionB() const = 0;
    /*
     A 제품과의 콜라보도 가능하다.
    */
    virtual string AnotherUsefulFunctionB(const AbstractProductA& collaborator) const = 0;
};

class ConcreteProductB1 : public AbstractProductB {
public:
    string UsefulFunctionB() const override {
        return "The result of the product B1.";
    }
    /*
     B1은 A1에서만 올바르게 작동한다.
     그럼에도 Abstract Product A의 모든 인스턴스를 받아들인다.
    */
    string AnotherUsefulFunctionB(const AbstractProductA& collaborator) const override {
        const string result = collaborator.UsefulFunctionA();
        return "The result of the B1 collaborating with ( " + result + " )";
    }
};

class ConcreteProductB2 : public AbstractProductB {
public:
    string UsefulFunctionB() const override {
        return "The result of the product B2.";
    }
    /*
     B2은 A2에서만 올바르게 작동한다.
     그럼에도 Abstract Product A의 모든 인스턴스를 받아들인다.
    */
    string AnotherUsefulFunctionB(const AbstractProductA& collaborator) const override {
        const string result = collaborator.UsefulFunctionA();
        return "The result of the B2 collaborating with ( " + result + " )";
    }
};

/*
 Abstract Factory 인터페이스는 서로 다른 추상 제품을 반환하는 방법을 선언한다.
 이 제품들은 패밀리라고 불리며 높은 수준의 테마 또는 개념으로 관련되어 있다.
 한 패밀리의 Product는 일반적으로 서로 콜라보할 수 있다.
 제품군은 여러 가지 변형을 가질 수 있지만 한 가지 변형의 Product는 다른 Produce와 호환되지 않는다.
 */
class AbstractFactory {
public:
    virtual AbstractProductA* CreateProductA() const = 0;
    virtual AbstractProductB* CreateProductB() const = 0;
};

/*
 Concrete Factory는 단일 변형에 속하는 Products를 생산한다.
 Factory는 결과적인 Product의 호환성을 보장한다.
 Concrete Factory의 방법의 Method는 Abstract Product을 반환하지만
 Method 내부에는 Concrete Product가 인스턴스화된다.
*/
class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* CreateProductA() const override {
        return new ConcreteProductA1();
    }
    AbstractProductB* CreateProductB() const override {
        return new ConcreteProductB1();
    }
};

class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* CreateProductA() const override {
        return new ConcreteProductA2();
    }
    AbstractProductB* CreateProductB() const override {
        return new ConcreteProductB2();
    }
};

/*
 Client Code는 Abstract Factory와 Abstract Product를 통해서만 Factory나 Product와 함께 작동한다.
 Factory나 Product 하위 Class를 Client Code에 전달할 수 있다.
 */
void ClientCode(const AbstractFactory& factory) {
    const AbstractProductA* product_a = factory.CreateProductA();
    const AbstractProductB* product_b = factory.CreateProductB();
    cout << product_b->UsefulFunctionB() << "\n";
    cout << product_b->AnotherUsefulFunctionB(*product_a) << "\n";
    delete product_a;
    delete product_b;
}

int main() {
    cout << "Client: Testing client code with the first factory type:\n";
    ConcreteFactory1* f1 = new ConcreteFactory1();
    ClientCode(*f1);
    delete f1;
    cout << endl;
    cout << "Client: Testing the same client code with the second factory type:\n";
    ConcreteFactory2* f2 = new ConcreteFactory2();
    ClientCode(*f2);
    delete f2;
    return 0;
}