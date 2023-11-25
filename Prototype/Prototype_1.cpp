#include <iostream>
#include <string>
#include <unordered_map>

// 추상 프로토타입 클래스
class Prototype {
public:
    virtual Prototype* clone() const = 0;
    virtual void info() const = 0;
};
/* 모든 구체적인 프로토타입 클래스가 구현해야 하는 메서드를 정의한 추상 클래스이다.
 ‘clone’은 객체를 복제하는 메서드이고, ‘info’는 프로토타입에 관한 정보를 출력하는 메서드이다. */

// 구체적인 프로토타입 클래스
class ConcretePrototype : public Prototype {
private:
    std::string data;

public:
    ConcretePrototype(const std::string& data) : data(data) {}

    Prototype* clone() const override {
        return new ConcretePrototype(data);
    }

    void info() const override {
        std::cout << "ConcretePrototype with data: " << data << std::endl;
    }
};
/* 살제로 복제될 객체를 나타내는 클래스이다.
 ‘clone’메서드를 통해 자기 자신을 복제하고, ‘info’ 메서드를 통해 객체에 관한 정보를 출력한다. */

// 프로토타입 관리자
class PrototypeManager {
private:
    std::unordered_map<std::string, Prototype*> prototypes;

public:
    Prototype* getPrototype(const std::string& key) {
        if (prototypes.find(key) != prototypes.end()) {
            return prototypes[key]->clone();
        }
        return nullptr;
    }

    void addPrototype(const std::string& key, Prototype* prototype) {
        prototypes[key] = prototype;
    }
};
// 프로토 타입 객체를 관리하는 클래스로, 프로토타입을 틍록하고 가져오는 기능을 제공한다.

int main() {
    PrototypeManager manager;

    // 미리 생성된 프로토타입을 등록
    manager.addPrototype("prototype_1", new ConcretePrototype("Data for Prototype 1"));
    manager.addPrototype("prototype_2", new ConcretePrototype("Data for Prototype 2"));

    // 프로토타입을 복제하여 새로운 객체 생성
    Prototype* clone1 = manager.getPrototype("prototype_1");
    Prototype* clone2 = manager.getPrototype("prototype_2");

    if (clone1 && clone2) {
        clone1->info();
        clone2->info();
    }
    else {
        std::cout << "Prototype not found." << std::endl;
    }

    return 0;
}
/* ‘PrototypeManager’를 사용하여 미리 생성된 프로토타입을 등록하고,
 ‘getPrototype’메서드를 통해 프로토타입을 복제하여 새로운 객체를 생성한다.
  이후 생성된 객체의 정보를 출력한다. */