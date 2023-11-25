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

    // ���� �޼���
    Prototype* clone() const override {
        return new ConcretePrototype(*this);
    }

    // ���� ��� �޼���
    void printInfo() const override {
        std::cout << "Info: " << info << std::endl;
    }
};

int main() {
    // ���� ������Ÿ�� ��ü ����
    ConcretePrototype original("Original Info");
    original.printInfo();

    // ������Ÿ���� �����Ͽ� ���ο� ��ü ����
    Prototype* cloned = original.clone();
    cloned->printInfo();

    // �޸� ���� ������ ���� ������ ��ü�� ����
    delete cloned;

    return 0;
}

