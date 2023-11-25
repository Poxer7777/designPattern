#include <iostream>
using namespace std;

class Soldier
{
public:
    virtual void shoot() = 0;
};

class Archer : public Soldier { };

class HumanArcher : public Archer { 
public:
    void shoot() {
        cout << "Human : Archer shoot" << endl;
    }
};
class OrcArcher : public Archer { 
public:
    void shoot() {
        cout << "Orc : Archer shoot" << endl;
    }
};

class Rider : public Soldier { };

class HumanRider : public Rider {
public:
    void shoot() {
        cout << "Human : Rider shoot" << endl;
    }
};

class OrcRider : public Rider {
public:
    void shoot() {
        cout << "Orc : Rider shoot" << endl;
    }
};

class AbstractFactory
{
public:
    virtual Soldier* createArcher() = 0;
    virtual Soldier* createRider() = 0;
};

class OrcFactory : public AbstractFactory
{
    Soldier* createArcher()
    {
        return new OrcArcher();
    };
    Soldier* createRider()
    {
        return new OrcRider();
    };
};

class HumanFactory : public AbstractFactory
{
    Soldier* createArcher()
    {
        return new HumanArcher();
    };
    Soldier* createRider()
    {
        return new HumanRider();
    };
};

class Game
{

public:
    AbstractFactory* factory;
    Game(AbstractFactory* factory) :factory(factory) {};
};

int main()
{
    Game* human = new Game(new HumanFactory);
    Game* orc = new Game(new OrcFactory);
    Archer* humanArcher = static_cast <Archer*>(human->factory->createArcher());
    Rider* humanRider = static_cast <Rider*>(human->factory->createRider());
    Archer* orcArcher = static_cast <Archer*>(orc->factory->createArcher());
    Rider* orcRider = static_cast <Rider*>(orc->factory->createRider());
    humanArcher->shoot();
    humanRider->shoot();
    orcArcher->shoot();
    orcRider->shoot();

    return 0;
}