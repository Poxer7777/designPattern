#include <iostream>
#include <string>
#include <unordered_map>

// �߻� ������Ÿ�� Ŭ����
class Prototype {
public:
    virtual Prototype* clone() const = 0;
    virtual void info() const = 0;
};
/* ��� ��ü���� ������Ÿ�� Ŭ������ �����ؾ� �ϴ� �޼��带 ������ �߻� Ŭ�����̴�.
 ��clone���� ��ü�� �����ϴ� �޼����̰�, ��info���� ������Ÿ�Կ� ���� ������ ����ϴ� �޼����̴�. */

// ��ü���� ������Ÿ�� Ŭ����
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
/* ������ ������ ��ü�� ��Ÿ���� Ŭ�����̴�.
 ��clone���޼��带 ���� �ڱ� �ڽ��� �����ϰ�, ��info�� �޼��带 ���� ��ü�� ���� ������ ����Ѵ�. */

// ������Ÿ�� ������
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
// ������ Ÿ�� ��ü�� �����ϴ� Ŭ������, ������Ÿ���� �v���ϰ� �������� ����� �����Ѵ�.

int main() {
    PrototypeManager manager;

    // �̸� ������ ������Ÿ���� ���
    manager.addPrototype("prototype_1", new ConcretePrototype("Data for Prototype 1"));
    manager.addPrototype("prototype_2", new ConcretePrototype("Data for Prototype 2"));

    // ������Ÿ���� �����Ͽ� ���ο� ��ü ����
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
/* ��PrototypeManager���� ����Ͽ� �̸� ������ ������Ÿ���� ����ϰ�,
 ��getPrototype���޼��带 ���� ������Ÿ���� �����Ͽ� ���ο� ��ü�� �����Ѵ�.
  ���� ������ ��ü�� ������ ����Ѵ�. */