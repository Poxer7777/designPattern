// Decorator 최종

#include <iostream>
using namespace std;

int PrintMenu()
{
	int num = 0;
	cout << "1. 캐릭터 기본 셋팅" << endl;
	cout << "2. 무기 획득 후 캐릭터 공격력" << endl;
	cout << "3. 방어구 획득 후 캐릭터 공격력" << endl;
	cout << "4. 종료" << endl;

	cout << "입력 : ";
	cin >> num;

	return num;
}

int WeaponMenu()
{
	int num2 = 0;
	
	cout << "1. 검" << endl;
	cout << "2. 활" << endl;
	cout << "3. 총" << endl;
	cout << "입력 : ";
	cin >> num2;

	return num2;
}

int DefenseMenu()
{
	int num3 = 0;

	cout << "1. 갑옷" << endl;
	cout << "2. 방패" << endl;
	cout << "입력 : ";
	cin >> num3;

	return num3;
}

class Character
{
public:
	virtual ~Character() = default;
	virtual int Attack() = 0;
	virtual int Defense() = 0;
	virtual void display() = 0;
};

class BasicCharacter : public Character
{
public:
	int Attack() override
	{
		return 20;
	}
	int Defense() override
	{
		return 10;
	}
	void display() override
	{
		cout << "[캐릭터 기본 셋팅]" << " 공격력 : " << Attack() << ", 방어력 : " << Defense() << endl;
	}
};

class ItemDecorator : public Character
{
public:
	Character* character;
	ItemDecorator(Character* character) : character(character) {}
	int Attack() override
	{
		return character->Attack();
	}
	int Defense() override
	{
		return character->Defense();
	}
	void display() override
	{
		return character->display();
	}
};

class WeaponDecorator : public ItemDecorator
{
	int attack;
public:
	WeaponDecorator(Character* character, int attack) : ItemDecorator(character), attack(attack) {}

	int Attack() override
	{
		return character->Attack() + attack;
	}

	void display() override
	{
		ItemDecorator::display();
		cout << "[무기획득] 공격력 : " << Attack() << endl;
	}
};

class Sword : public WeaponDecorator
{
public:
	Sword(Character* character) : WeaponDecorator(character, 12) {}

	void display() override
	{
		cout << "[무기획득/검] : " << Attack() << endl;
	}
};

class Bow : public WeaponDecorator
{
public:
	Bow(Character* character) : WeaponDecorator(character, 8) {}

	void display() override
	{
		cout << "[무기획득/활] : " << Attack() << endl;
	}
};

class Gun : public WeaponDecorator
{
public:
	Gun(Character* character) : WeaponDecorator(character, 18) {}

	void display() override
	{
		cout << "[무기획득/총] : " << Attack() << endl;
	}
};

class DefenseDecorator : public ItemDecorator
{
	int defense;
public:
	DefenseDecorator(Character* character, int defense) : ItemDecorator(character), defense(defense) {}

	int Defense() override
	{
		return character->Defense() + defense;
	}

	void display() override
	{
		ItemDecorator::display();
		cout << "[방어구획득] 방어력 : " << Defense() << endl;
	}
};

class Armor : public DefenseDecorator
{
public:
	Armor(Character* character) : DefenseDecorator(character, 20) {}

	void display() override
	{
		cout << "[방어구획득/갑옷] : " << Defense() << endl;
	}
};

class shield : public DefenseDecorator
{
public:
	shield(Character* character) : DefenseDecorator(character, 10) {}

	void display() override
	{
		cout << "[방어구획득/갑옷] : " << Defense() << endl;
	}
};

int main()
{
	int num = 0, num2 = 0, num3 = 0, wp = 0, df = 0;

	while (1)
	{
		system("cls");
		num = PrintMenu();

		Character* basicCharacter = new BasicCharacter();
		WeaponDecorator* weaponCharacter = new WeaponDecorator(basicCharacter, 5);
		DefenseDecorator* defenseCharacter = new DefenseDecorator(basicCharacter, 10);

		switch (num)
		{
		case 1:
			system("cls");
			basicCharacter->display();
			system("pause");
			break;
		case 2:
			system("cls");
			
			num2 = WeaponMenu();

			switch (num2)
			{
			case 1: // 검
				weaponCharacter = new Sword(basicCharacter);
				wp = weaponCharacter->Attack();
				weaponCharacter->display();
				break;
			case 2: // 활
				weaponCharacter = new Bow(basicCharacter);
				wp = weaponCharacter->Attack();
				weaponCharacter->display();
				break;
			case 3: // 총
				weaponCharacter = new Gun(basicCharacter);
				wp = weaponCharacter->Attack();
				weaponCharacter->display();
				break;
			}
			system("pause");
			break;
		case 3:
			system("cls");
			num3 = DefenseMenu();
			switch (num3)
			{
			case 1: // 갑옷
				defenseCharacter = new Armor(basicCharacter);
				df = defenseCharacter->Defense();
				defenseCharacter->display();
				break;
			case 2: // 방패
				defenseCharacter = new shield(basicCharacter);
				df = defenseCharacter->Defense();
				defenseCharacter->display();
				break;
			}
			system("pause");
			break;
		case 4:
			if (wp == 0 || df == 0)
			{
				cout << "무기, 방어구를 선택하세요." << endl;
				system("pause");
				break;
			}
			else
				cout << "[최종 공격력/방어력] : " << wp << ", " << df << endl;
			delete basicCharacter;
			delete weaponCharacter;
			delete defenseCharacter;
			return 0;
		}
	}
}