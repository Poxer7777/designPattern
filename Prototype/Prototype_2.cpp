#include <iostream>
#include <string>

class Prototype {
public:
    virtual Prototype* clone() const = 0;
    virtual void printInfo() const = 0;
    virtual ~Prototype() {}
};

class ConcretePrototype : public Prototype {
private:
    std::string info;

public:
    ConcretePrototype(const std::string& info) : info(info) {}

    // 복제 메서드
    Prototype* clone() const override {
        return new ConcretePrototype(*this);
    }

    // 정보 출력 메서드
    void printInfo() const override {
        std::cout << "Info: " << info << std::endl;
    }
};

int main() {
    // 원본 프로토타입 객체 생성
    ConcretePrototype original("Original Info");
    original.printInfo();

    // 프로토타입을 복제하여 새로운 객체 생성
    Prototype* cloned = original.clone();
    cloned->printInfo();

    // 메모리 누수 방지를 위해 복제된 객체는 삭제
    delete cloned;

    return 0;
}

