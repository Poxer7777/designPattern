#include <iostream>
#include <string_view>
#include <algorithm>
using namespace std;

/*
 Strategy : 이 인터페이스는 어떤 알고리즘의 모든 지원 버전에 공통으로 적용되는 작업을 선언한다.
 해당 인터페이스에는 doAlgorithm 메서드를 선언하고 있다.
*/ 
class Strategy
{
public:
    virtual ~Strategy() = default;
    virtual string doAlgorithm(string_view data) const = 0;
};

/*
 Context:
 이 인터페이스를 사용하여 "구체적인 전략(Concrete Strategies)"에 의해
 정의된 알고리즘을 호출하고, Strategy 객체를 소유한다.
 또한 Context는 일부 작업을 Strategy 객체로 위임하고 알고리즘을 실행한다.
 "Context"는 클라이언트에게 중요한 인터페이스를 정의한다.
*/
class Context
{
    /* "Context"는 "Strategy" 중 하나의 객체에 대한 참조를 유지합니다.
        "Context"는 전략의 구체적인 클래스를 알지 않습니다.
        "Context"는 "Strategy" 인터페이스를 통해 모든 전략과 작동해야 한다..*/
private:
    unique_ptr<Strategy> strategy_;
    // "Context"는 생성자를 통해 전략을 받지만, 런타임에서 이를 변경할 수 있는 설정자(setter)를 제공하기도 한다.
public:
    explicit Context(unique_ptr<Strategy>&& strategy = {}) : strategy_(move(strategy))
    {
    }
    // "Context"는 런타임 중에 전략 객체를 교체할 수 있는 기능을 제공한다.
    void set_strategy(unique_ptr<Strategy>&& strategy)
    {
        strategy_ = move(strategy);
    }
    // "Context"는 자체적으로 알고리즘의 여러 버전을 구현하지않고, 일부 작업을 "Strategy" 객체로 위임한다.
    void doSomeBusinessLogic() const
    {
        if (strategy_) {
            cout << "Context: Sorting data using the strategy (not sure how it'll do it)\n";
            string result = strategy_->doAlgorithm("aecbd");
            cout << result << "\n";
        }
        else {
            cout << "Context: Strategy isn't set\n";
        }
    }
};

// "구체적인 전략(Concrete Strategies)"은 기본 "Strategy" 인터페이스를 따르면서 알고리즘을 구현한다.
// ConcreteStrategyA : 데이터를 정렬하는 일반적인 알고리즘을 사용한다.
// ConcreteStrategyB : 데이터를 역순으로 정렬하는 알고리즘을 사용한다.
// 이 인터페이스는 이러한 전략 객체들을 "Context"에서 상호 교환이 가능하게 만든다.
class ConcreteStrategyA : public Strategy
{
public:
    string doAlgorithm(string_view data) const override
    {
        string result(data);
        sort(begin(result), end(result));

        return result;
    }
};
class ConcreteStrategyB : public Strategy
{
    string doAlgorithm(string_view data) const override
    {
        string result(data);
        sort(begin(result), end(result), greater<>());

        return result;
    }
};

// 클라이언트 코드는 구체적인 전략을 선택하고 이를 "Context"에 전달한다.
// 클라이언트는 올바른 선택을 하기 위해 전략들간의 차이를 이해해야 한다.
void clientCode()
{
    Context context(std::make_unique<ConcreteStrategyA>());
    cout << "Client: Strategy is set to normal sorting.\n";
    context.doSomeBusinessLogic();
    cout << "\n";
    cout << "Client: Strategy is set to reverse sorting.\n";
    context.set_strategy(make_unique<ConcreteStrategyB>());
    context.doSomeBusinessLogic();
}

int main()
{
    clientCode();
    return 0;
}

