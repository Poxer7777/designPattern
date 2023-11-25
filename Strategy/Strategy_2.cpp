#include <iostream>

// 전략 인터페이스
class Strategy {
public:
    virtual void execute() = 0;
};
/* 순수 가상함수 ‘execute’를 정의한다.
 이 함수는 전략 클래스드링 반드시 구현해야 하는 실행 메서드이다.
 순수 가상 함수를 사용함으로써 각 전략은 자체적인 실행 방식을 가질 수 있다. */

// 구체적인 전략 클래스들
class ConcreteStrategyA : public Strategy {
public:
    void execute() override {
        std::cout << "전략 A를 실행합니다." << std::endl;
    }
};
// 구체적인 전략 클래스
class ConcreteStrategyB : public Strategy {
public:
    void execute() override {
        std::cout << "전략 B를 실행합니다." << std::endl;
    }
};
/*실제 전략을 구현한 클래스들이다.
 각각 ‘execute’ 함수를 구현하여 전략 A와 전략 B의 구체적인 동작을 정의한다. */

// 컨텍스트 클래스
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
/* ‘Context’ 클래스는 현재 선택된 전략을 가지고 있으며, 이를 통해 실행 메서드를 호출한다.
 클라이언트가 필요에 따라 전략을 동적으로 변경할 수 있도록 ‘setStratege’ 메서드를 제공한다. */

int main() {
    ConcreteStrategyA strategyA;
    ConcreteStrategyB strategyB;

    Context context(&strategyA);

    context.executeStrategy(); // 전략 A 실행
    context.setStrategy(&strategyB);
    context.executeStrategy(); // 전략 B 실행

    return 0;
}
/* main 함수에서는 두 가지 전략 객체를 생성하고,
 초기에는 전략 A를 선택하여 Context 객체를 생성한다.*/
/* executeStrategy 메서드를 호출하여 현재 선택된 전략을 실행한다.
이후 setStrategy를 사용하여 전략을 변경하고
다시 ‘executeStrategy’를 호출하여새로운 전략을 실행한다. */