#include <iostream>

// ���� �������̽�
class Strategy {
public:
    virtual void execute() = 0;
};
/* ���� �����Լ� ��execute���� �����Ѵ�.
 �� �Լ��� ���� Ŭ�����帵 �ݵ�� �����ؾ� �ϴ� ���� �޼����̴�.
 ���� ���� �Լ��� ��������ν� �� ������ ��ü���� ���� ����� ���� �� �ִ�. */

// ��ü���� ���� Ŭ������
class ConcreteStrategyA : public Strategy {
public:
    void execute() override {
        std::cout << "���� A�� �����մϴ�." << std::endl;
    }
};
// ��ü���� ���� Ŭ����
class ConcreteStrategyB : public Strategy {
public:
    void execute() override {
        std::cout << "���� B�� �����մϴ�." << std::endl;
    }
};
/*���� ������ ������ Ŭ�������̴�.
 ���� ��execute�� �Լ��� �����Ͽ� ���� A�� ���� B�� ��ü���� ������ �����Ѵ�. */

// ���ؽ�Ʈ Ŭ����
class Context {
private:
    Strategy* strategy;

public:
    Context(Strategy* s) : strategy(s) {}

    void setStrategy(Strategy* s) {
        strategy = s;
    }

    void executeStrategy() {
        strategy->execute();
    }
};
/* ��Context�� Ŭ������ ���� ���õ� ������ ������ ������, �̸� ���� ���� �޼��带 ȣ���Ѵ�.
 Ŭ���̾�Ʈ�� �ʿ信 ���� ������ �������� ������ �� �ֵ��� ��setStratege�� �޼��带 �����Ѵ�. */

int main() {
    ConcreteStrategyA strategyA;
    ConcreteStrategyB strategyB;

    Context context(&strategyA);

    context.executeStrategy(); // ���� A ����
    context.setStrategy(&strategyB);
    context.executeStrategy(); // ���� B ����

    return 0;
}
/* main �Լ������� �� ���� ���� ��ü�� �����ϰ�,
 �ʱ⿡�� ���� A�� �����Ͽ� Context ��ü�� �����Ѵ�.*/
/* executeStrategy �޼��带 ȣ���Ͽ� ���� ���õ� ������ �����Ѵ�.
���� setStrategy�� ����Ͽ� ������ �����ϰ�
�ٽ� ��executeStrategy���� ȣ���Ͽ����ο� ������ �����Ѵ�. */