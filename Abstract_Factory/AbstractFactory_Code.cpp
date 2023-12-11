#include <iostream>
using namespace std;

// 추상 클래스 : 직업군
class Character
{
public:
    int maxHp = 200; // Healthy Point (체력) : 최대 체력
    int maxMp = 100; // Mana Point (마나) : 최대 마나
    int Hp = 200; // 현재 체력
    int Mp = 100; // 현재 마나
    int power = 5; // Power : 공격력
    string Type; // Type (속성)
    virtual void attack(Character* other) = 0; // 다른 캐릭터에게 공격을 하는 함수
};

class Warroirs : public Character {};
class Archers : public Character {};
class Magician : public Character {};

// 구상 클래스 : 각 직업군의 각 속성의 구현
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

            ::cout << "Fire Slash / Damage : " << Damage << endl;
        }
        else {
            ::cout << "Needs more Mana" << endl;
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

            ::cout << "Ice Slash / Damage : " << Damage << endl;
        }
        else {
            ::cout << "Needs more Mana" << endl;
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

            ::cout << "Natural Slash / Damage : " << Damage << endl;
        }
        else {
            ::cout << "Needs more Mana" << endl;
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

            ::cout << "Fire Arrow / Damage : " << Damage << endl;
        }
        else {
            ::cout << "Needs more Mana" << endl;
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

            ::cout << "Ice Arrow / Damage : " << Damage << endl;
        }
        else {
            ::cout << "Needs more Mana" << endl;
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

            ::cout << "Natural Arrow / Damage : " << Damage << endl;
        }
        else {
            ::cout << "Needs more Mana" << endl;
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

            ::cout << "Fire Blast / Damage : " << Damage << endl;
        }
        else {
            ::cout << "Needs more Mana" << endl;
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

            ::cout << "Ice Blast / Damage : " << Damage << endl;
        }
        else {
            ::cout << "Needs more Mana" << endl;
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

            ::cout << "Natural Blast / Damage : " << Damage << endl;
        }
        else {
            ::cout << "Needs more Mana" << endl;
        }
    }
};

// 추상 팩토리 : 객체를 생성하기 위한 팩토리
class CharacterFactory
{
public:
    virtual Character* createWarrior() = 0;
    virtual Character* createArcher() = 0;
    virtual Character* createMagician() = 0;
};

// 구상 팩토리 : 추상팩토리에서 객체를 생성하는 내용 구현
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

// 캐릭터의 스탯을 출력하는 함수
void printStat(Character* ch) {
    ::cout << "Hp : " << ch->Hp << endl
        << "Mp : " << ch->Mp << endl
        << "Power : " << ch->power << endl
        << "Type : " << ch->Type << endl;
}

int main()
{
    // 각 팩토리 생성
    CharacterFactory* fireFactory = new FireFactory;
    CharacterFactory* waterFactory = new WaterFactory;
    CharacterFactory* grassFactory = new GrassFactory;

    // 캐릭터를 생성할 위치 생성
    Character* character1 = nullptr;
    Character* character2 = nullptr;

    // 생성할 캐릭터의 직업과 속성을 입력받을 변수
    int classNum = 0;
    int typeNum = 0;

    ::cout << "1. 전사 / 2. 궁수 / 3. 마법사" << endl
        << "1. 불 / 2. 물 / 3. 풀" << endl;

    // 캐릭터 1 생성
    ::cout << "캐릭터 1의 직업 : ";
    ::cin >> classNum;
    ::cout << "캐릭터 1의 속성 : ";
    ::cin >> typeNum;

    switch (classNum) {
    case 1:
        switch (typeNum) {
        case 1:
            character1 = fireFactory->createWarrior(); break;
        case 2:
            character1 = waterFactory->createWarrior(); break;
        case 3:
            character1 = grassFactory->createWarrior(); break;
        } break;
    case 2:
        switch (typeNum) {
        case 1:
            character1 = fireFactory->createArcher(); break;
        case 2:
            character1 = waterFactory->createArcher(); break;
        case 3:
            character1 = grassFactory->createArcher(); break;
        } break;
    case 3:
        switch (typeNum) {
        case 1:
            character1 = fireFactory->createMagician(); break;
        case 2:
            character1 = waterFactory->createMagician(); break;
        case 3:
            character1 = grassFactory->createMagician(); break;
        } break;
    }

    // 캐릭터 2 생성
    ::cout << "캐릭터 2의 직업 : ";
    ::cin >> classNum;
    ::cout << "캐릭터 2의 속성 : ";
    ::cin >> typeNum;

    switch (classNum) {
    case 1:
        switch (typeNum) {
        case 1:
            character2 = fireFactory->createWarrior(); break;
        case 2:
            character2 = waterFactory->createWarrior(); break;
        case 3:
            character2 = grassFactory->createWarrior(); break;
        } break;
    case 2:
        switch (typeNum) {
        case 1:
            character2 = fireFactory->createArcher(); break;
        case 2:
            character2 = waterFactory->createArcher(); break;
        case 3:
            character2 = grassFactory->createArcher(); break;
        } break;
    case 3:
        switch (typeNum) {
        case 1:
            character2 = fireFactory->createMagician(); break;
        case 2:
            character2 = waterFactory->createMagician(); break;
        case 3:
            character2 = grassFactory->createMagician(); break;
        } break;
    }

    // 생성된 캐릭터들의 스탯 출력
    ::cout << endl;
    ::cout << "Charater 1" << endl;
    printStat(character1);
    ::cout << endl;
    ::cout << "Character 2" << endl;
    printStat(character2);

    // 캐릭터 1이 캐릭터 2에게 공격
    ::cout << endl;
    character1->attack(character2);

    // 캐릭터 2의 변화된 체력 출력
    ::cout << endl << "Character 2 Hp : " << character2->Hp << endl;

    // 동적할당 메모리 삭제
    delete character1;
    delete character2;

    delete fireFactory;
    delete waterFactory;
    delete grassFactory;

    return 0;
}
