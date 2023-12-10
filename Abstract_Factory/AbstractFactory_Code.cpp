#include <iostream>
using namespace std;

class Character
{
public:
    int maxHp = 200; // Healthy Point (체력)
    int maxMp = 100; // Mana Point (마나)
    int Hp = 200;
    int Mp = 100;
    int power = 5;
    string Type; // Type (속성)
    virtual void attack(Character* other) = 0;
};

// 추상 클래스
class Warroirs : public Character {};
class Archers : public Character {};
class Magician : public Character {};

// 구상 클래스
class FireWarrior : public Warroirs {
public:
    FireWarrior() {
        Type = "Fire";
    }
    void attack(Character* other) {
        if (Mp >= 10) {
            Mp -= 10;
            int Damage = power * 5;

            if (other->Type == "Water") {
                other->Hp -= Damage * 0.8;
            }
            else if (other->Type == "Grass") {
                other->Hp -= Damage * 1.2;
            }
            else {
                other->Hp -= Damage;
            }

            cout << "Fire Slash / Damage : " << Damage << endl;
        }
        else {
            cout << "Needs more Mana" << endl;
        }
    }
};
class WaterWarrior : public Warroirs {
public:
    WaterWarrior() {
        Type = "Water";
    }
    void attack(Character* other) {
        if (Mp >= 10) {
            Mp -= 10;
            int Damage = power * 5;

            if (other->Type == "Grass") {
                other->Hp -= Damage * 0.8;
            }
            else if (other->Type == "Fire") {
                other->Hp -= Damage * 1.2;
            }
            else {
                other->Hp -= Damage;
            }

            cout << "Ice Slash / Damage : " << Damage << endl;
        }
        else {
            cout << "Needs more Mana" << endl;
        }
    }
};
class GrassWarrior : public Warroirs {
public:
    GrassWarrior() {
        Type = "Grass";
    }
    void attack(Character* other) {
        if (Mp >= 10) {
            Mp -= 10;
            int Damage = power * 5;

            if (other->Type == "Fire") {
                other->Hp -= Damage * 0.8;
            }
            else if (other->Type == "Water") {
                other->Hp -= Damage * 1.2;
            }
            else {
                other->Hp -= Damage;
            }

            cout << "Natural Slash / Damage : " << Damage << endl;
        }
        else {
            cout << "Needs more Mana" << endl;
        }
    }
};

class FireArcher : public Archers {
public:
    FireArcher() {
        Type = "Fire";
    }
    void attack(Character* other) {
        if (Mp >= 5) {
            Mp -= 5;
            int Damage = power * 2;

            if (other->Type == "Water") {
                other->Hp -= Damage * 0.8;
            }
            else if (other->Type == "Grass") {
                other->Hp -= Damage * 1.2;
            }
            else {
                other->Hp -= Damage;
            }

            cout << "Fire Arrow / Damage : " << Damage << endl;
        }
        else {
            cout << "Needs more Mana" << endl;
        }
    }
};
class WaterArcher : public Archers {
public:
    WaterArcher() {
        Type = "Water";
    }
    void attack(Character* other) {
        if (Mp >= 5) {
            Mp -= 5;
            int Damage = power * 2;

            if (other->Type == "Grass") {
                other->Hp -= Damage * 0.8;
            }
            else if (other->Type == "Fire") {
                other->Hp -= Damage * 1.2;
            }
            else {
                other->Hp -= Damage;
            }

            cout << "Ice Arrow / Damage : " << Damage << endl;
        }
        else {
            cout << "Needs more Mana" << endl;
        }
    }
};
class GrassArcher : public Archers {
public:
    GrassArcher() {
        Type = "Grass";
    }
    void attack(Character* other) {
        if (Mp >= 5) {
            Mp -= 5;
            int Damage = power * 2;

            if (other->Type == "Fire") {
                other->Hp -= Damage * 0.8;
            }
            else if (other->Type == "Water") {
                other->Hp -= Damage * 1.2;
            }
            else {
                other->Hp -= Damage;
            }

            cout << "Natural Arrow / Damage : " << Damage << endl;
        }
        else {
            cout << "Needs more Mana" << endl;
        }
    }
};

class FireMagician : public Magician {
public:
    FireMagician() {
        Type = "Fire";
    }
    void attack(Character* other) {
        if (Mp >= 20) {
            Mp -= 20;
            int Damage = power * 9;

            if (other->Type == "Water") {
                other->Hp -= Damage * 0.8;
            }
            else if (other->Type == "Grass") {
                other->Hp -= Damage * 1.2;
            }
            else {
                other->Hp -= Damage;
            }

            cout << "Fire Blast / Damage : " << Damage << endl;
        }
        else {
            cout << "Needs more Mana" << endl;
        }
    }
};
class WaterMagician : public Magician {
public:
    WaterMagician() {
        Type = "Water";
    }
    void attack(Character* other) {
        if (Mp >= 20) {
            Mp -= 20;
            int Damage = power * 9;

            if (other->Type == "Grass") {
                other->Hp -= Damage * 0.8;
            }
            else if (other->Type == "Fire") {
                other->Hp -= Damage * 1.2;
            }
            else {
                other->Hp -= Damage;
            }

            cout << "Ice Blast / Damage : " << Damage << endl;
        }
        else {
            cout << "Needs more Mana" << endl;
        }
    }
};
class GrassMagician : public Magician {
public:
    GrassMagician() {
        Type = "Grass";
    }
    void attack(Character* other) {
        if (Mp >= 20) {
            Mp -= 20;
            int Damage = power * 9;

            if (other->Type == "Fire") {
                other->Hp -= Damage * 0.8;
            }
            else if (other->Type == "Water") {
                other->Hp -= Damage * 1.2;
            }
            else {
                other->Hp -= Damage;
            }

            cout << "Natural Blast / Damage : " << Damage << endl;
        }
        else {
            cout << "Needs more Mana" << endl;
        }
    }
};

// 추상 팩토리
class CharacterFactory
{
public:
    virtual Character* createWarrior() = 0;
    virtual Character* createArcher() = 0;
    virtual Character* createMagician() = 0;
};

// 구상 팩토리
class FireFactory : public CharacterFactory
{
    Character* createWarrior()
    {
        return new FireWarrior();
    };
    Character* createArcher()
    {
        return new FireArcher();
    };
    Character* createMagician()
    {
        return new FireMagician();
    };
};
class WaterFactory : public CharacterFactory
{
    Character* createWarrior()
    {
        return new WaterWarrior();
    };
    Character* createArcher()
    {
        return new WaterArcher();
    };
    Character* createMagician()
    {
        return new WaterMagician();
    };
};
class GrassFactory : public CharacterFactory
{
    Character* createWarrior()
    {
        return new GrassWarrior();
    };
    Character* createArcher()
    {
        return new GrassArcher();
    };
    Character* createMagician()
    {
        return new GrassMagician();
    };
};

void printStat(Character* ch) {
    cout << "Hp : " << ch->Hp << endl
        << "Mp : " << ch->Mp << endl
        << "Power : " << ch->power << endl
        << "Type : " << ch->Type << endl;
}

int main()
{
    CharacterFactory* fireFactory = new FireFactory;
    CharacterFactory* waterFactory = new WaterFactory;
    CharacterFactory* grassFactory = new GrassFactory;

    Character* character1 = fireFactory->createMagician();
    Character* character2 = grassFactory->createArcher();

    cout << "Charater 1" << endl;
    printStat(character1);
    cout << endl;
    cout << "Character 2" << endl;
    printStat(character2);

    cout << endl;
    character1->attack(character2);

    cout << endl << "Character 2 Hp : " << character2->Hp << endl;

    delete character1;
    delete character2;

    delete fireFactory;
    delete waterFactory;
    delete grassFactory;

    return 0;
}