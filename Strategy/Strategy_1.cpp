#include <iostream>
#include <string_view>
#include <algorithm>
using namespace std;

/*
 Strategy : �� �������̽��� � �˰����� ��� ���� ������ �������� ����Ǵ� �۾��� �����Ѵ�.
 �ش� �������̽����� doAlgorithm �޼��带 �����ϰ� �ִ�.
*/ 
class Strategy
{
public:
    virtual ~Strategy() = default;
    virtual string doAlgorithm(string_view data) const = 0;
};

/*
 Context:
 �� �������̽��� ����Ͽ� "��ü���� ����(Concrete Strategies)"�� ����
 ���ǵ� �˰����� ȣ���ϰ�, Strategy ��ü�� �����Ѵ�.
 ���� Context�� �Ϻ� �۾��� Strategy ��ü�� �����ϰ� �˰����� �����Ѵ�.
 "Context"�� Ŭ���̾�Ʈ���� �߿��� �������̽��� �����Ѵ�.
*/
class Context
{
    /* "Context"�� "Strategy" �� �ϳ��� ��ü�� ���� ������ �����մϴ�.
        "Context"�� ������ ��ü���� Ŭ������ ���� �ʽ��ϴ�.
        "Context"�� "Strategy" �������̽��� ���� ��� ������ �۵��ؾ� �Ѵ�..*/
private:
    unique_ptr<Strategy> strategy_;
    // "Context"�� �����ڸ� ���� ������ ������, ��Ÿ�ӿ��� �̸� ������ �� �ִ� ������(setter)�� �����ϱ⵵ �Ѵ�.
public:
    explicit Context(unique_ptr<Strategy>&& strategy = {}) : strategy_(move(strategy))
    {
    }
    // "Context"�� ��Ÿ�� �߿� ���� ��ü�� ��ü�� �� �ִ� ����� �����Ѵ�.
    void set_strategy(unique_ptr<Strategy>&& strategy)
    {
        strategy_ = move(strategy);
    }
    // "Context"�� ��ü������ �˰����� ���� ������ ���������ʰ�, �Ϻ� �۾��� "Strategy" ��ü�� �����Ѵ�.
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

// "��ü���� ����(Concrete Strategies)"�� �⺻ "Strategy" �������̽��� �����鼭 �˰����� �����Ѵ�.
// ConcreteStrategyA : �����͸� �����ϴ� �Ϲ����� �˰����� ����Ѵ�.
// ConcreteStrategyB : �����͸� �������� �����ϴ� �˰����� ����Ѵ�.
// �� �������̽��� �̷��� ���� ��ü���� "Context"���� ��ȣ ��ȯ�� �����ϰ� �����.
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

// Ŭ���̾�Ʈ �ڵ�� ��ü���� ������ �����ϰ� �̸� "Context"�� �����Ѵ�.
// Ŭ���̾�Ʈ�� �ùٸ� ������ �ϱ� ���� �����鰣�� ���̸� �����ؾ� �Ѵ�.
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

