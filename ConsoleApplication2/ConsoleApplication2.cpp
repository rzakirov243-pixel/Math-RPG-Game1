#include <iostream>
#include <cstdlib>
#include <ctime>

class Enemies {
private:
	std::string name;
	int health;
	int damage;
public:
	void set_data(std::string x, int y, int z) {
		name = x; 
		health = y;
		damage = z;
	}
	void show_info() {
		std::cout << "Name: " << name << " | Health: " << health << " | Damage: " << damage << std::endl;
	}
	bool isAviable() {
		return health > 0;  // Упрощено
	}
	void set_health(int s) {
		health -= s;
	}
	int show_health() {
		return health;
	}
	int show_damage() {
		return damage;
	}
};

int main() {
	srand(time(NULL));

	std::cout << "Вас приветствует битва 1 на 1" << std::endl;
	std::cout << "----------------------------------" << std::endl;

	Enemies User;
	User.set_data("Player", 200, 10);
	std::cout << "Ваши параметры: " << std::endl;
	User.show_info();

	int mainChoice = 0;
	bool gameRunning = true;

	while (gameRunning) {
		std::cout << "\n==== ГЛАВНОЕ МЕНЮ ====" << std::endl;
		std::cout << "1) Easy\n2) Normal\n3) Hard\n4) Extreme\n5) Boss Fight\n0) Выход" << std::endl;
		std::cin >> mainChoice;

		switch (mainChoice) {

		case 1: { // EASY LEVEL
			Enemies Slime;
			Slime.set_data("Slime", 80, 10);

			bool fighting = true;
			while (fighting) {
				std::cout << "\n----- EASY LEVEL -----" << std::endl;
				std::cout << "1) Информация о враге\n2) Начать бой\n3) Назад в меню" << std::endl;
				int choiceeasy = 0;
				std::cin >> choiceeasy;

				if (choiceeasy == 1) {
					Slime.show_info();
				}
				else if (choiceeasy == 2) {
					// БОЙ
					Enemies SlimeTemp = Slime;
					std::cout << "\n*** Битва началась! ***\n" << std::endl;

					while (SlimeTemp.isAviable() && User.isAviable()) {
						int a = 1 + rand() % 100;
						int b = 1 + rand() % 100;
						int result = a + b;
						int result_user;

						std::cout << a << " + " << b << " = ? ";
						std::cin >> result_user;

						if (result_user == result) {
							std::cout << "✓ Верно! Враг получил 10 урона!" << std::endl;
							SlimeTemp.set_health(10);
						}
						else {
							std::cout << "✗ Неправильно! Вы получили 30 урона!" << std::endl;
							User.set_health(30);
						}
						std::cout << "Ваше здоровье: " << User.show_health() << " | Враг: " << SlimeTemp.show_health() << "\n" << std::endl;
					}

					if (User.isAviable()) {
						std::cout << "=== ВЫ ВЫИГРАЛИ! ===" << std::endl;
					}
					else {
						std::cout << "=== ВЫ ПРОИГРАЛИ! ===" << std::endl;
					}
					fighting = false;  // Выход после боя
				}
				else if (choiceeasy == 3) {
					fighting = false;  // Выход в главное меню
				}
			}
			break;
		}

		case 2: { // NORMAL LEVEL
			Enemies Goblin;
			Goblin.set_data("Goblin", 100, 15);
			Enemies Wild_Wolf;
			Wild_Wolf.set_data("Wild Wolf", 90, 25);

			bool fighting = true;
			while (fighting) {
				std::cout << "\n----- NORMAL LEVEL -----" << std::endl;
				std::cout << "1) Информация о врагах\n2) Начать бой\n3) Назад в меню" << std::endl;
				int choicenormal = 0;
				std::cin >> choicenormal;

				if (choicenormal == 1) {
					Goblin.show_info();
					Wild_Wolf.show_info();
				}
				else if (choicenormal == 2) {
					// БОЙ
					Enemies GoblinTemp = Goblin;
					Enemies WolfTemp = Wild_Wolf;
					std::cout << "\n*** Битва началась! ***\n" << std::endl;

					while ((GoblinTemp.isAviable() || WolfTemp.isAviable()) && User.isAviable()) {
						int a = 1 + rand() % 100;
						int b = 1 + rand() % 100;
						int result = a + b;
						int result_user;

						std::cout << a << " + " << b << " = ? ";
						std::cin >> result_user;

						if (result_user == result) {
							std::cout << "✓ Верно! Враги получили 10 урона!" << std::endl;
							GoblinTemp.set_health(10);
							WolfTemp.set_health(10);
						}
						else {
							std::cout << "✗ Неправильно! Вы получили 40 урона!" << std::endl;
							User.set_health(40);
						}
						std::cout << "Ваше здоровье: " << User.show_health() << " | Goblin: " << GoblinTemp.show_health() << " | Wolf: " << WolfTemp.show_health() << "\n" << std::endl;
					}

					if (User.isAviable()) {
						std::cout << "=== ВЫ ВЫИГРАЛИ! ===" << std::endl;
					}
					else {
						std::cout << "=== ВЫ ПРОИГРАЛИ! ===" << std::endl;
					}
					fighting = false;  // Выход после боя
				}
				else if (choicenormal == 3) {
					fighting = false;  // Выход в главное меню
				}
			}
			break;
		}

		case 3: { // HARD LEVEL
			Enemies Ork;
			Ork.set_data("Ork Warrior", 150, 20);
			Enemies Skeleton;
			Skeleton.set_data("Skeleton Archer", 110, 30);
			Enemies Stone;
			Stone.set_data("Stone Golem", 300, 15);

			bool fighting = true;
			while (fighting) {
				std::cout << "\n----- HARD LEVEL -----" << std::endl;
				std::cout << "1) Информация о врагах\n2) Начать бой\n3) Назад в меню" << std::endl;
				int choicehard = 0;
				std::cin >> choicehard;

				if (choicehard == 1) {
					Ork.show_info();
					Skeleton.show_info();
					Stone.show_info();
				}
				else if (choicehard == 2) {
					// БОЙ
					Enemies OrkTemp = Ork;
					Enemies SkeletonTemp = Skeleton;
					Enemies StoneTemp = Stone;
					std::cout << "\n*** Битва началась! ***\n" << std::endl;

					while ((OrkTemp.isAviable() || SkeletonTemp.isAviable() || StoneTemp.isAviable()) && User.isAviable()) {
						int a = 1 + rand() % 100;
						int b = 1 + rand() % 100;
						int result = a + b;
						int result_user;

						std::cout << a << " + " << b << " = ? ";
						std::cin >> result_user;

						if (result_user == result) {
							std::cout << "✓ Верно! Враги получили 10 урона!" << std::endl;
							OrkTemp.set_health(10);
							SkeletonTemp.set_health(10);
							StoneTemp.set_health(10);
						}
						else {
							std::cout << "✗ Неправильно! Вы получили 65 урона!" << std::endl;
							User.set_health(65);
						}
						std::cout << "Ваше здоровье: " << User.show_health() << " | Ork: " << OrkTemp.show_health() << " | Skeleton: " << SkeletonTemp.show_health() << " | Stone: " << StoneTemp.show_health() << "\n" << std::endl;
					}

					if (User.isAviable()) {
						std::cout << "=== ВЫ ВЫИГРАЛИ! ===" << std::endl;
					}
					else {
						std::cout << "=== ВЫ ПРОИГРАЛИ! ===" << std::endl;
					}
					fighting = false;  // Выход после боя
				}
				else if (choicehard == 3) {
					fighting = false;  // Выход в главное меню
				}
			}
			break;
		}

		case 4: { // EXTREME LEVEL
			Enemies DarkMage;
			DarkMage.set_data("Dark Mage", 120, 45);
			Enemies VampireLord;
			VampireLord.set_data("Vampire Lord", 200, 35);
			Enemies AncientDragon;
			AncientDragon.set_data("Ancient Dragon", 500, 60);

			bool fighting = true;
			while (fighting) {
				std::cout << "\n----- EXTREME LEVEL -----" << std::endl;
				std::cout << "1) Информация о врагах\n2) Начать бой\n3) Назад в меню" << std::endl;
				int choiceextreme = 0;
				std::cin >> choiceextreme;

				if (choiceextreme == 1) {
					DarkMage.show_info();
					VampireLord.show_info();
					AncientDragon.show_info();
				}
				else if (choiceextreme == 2) {
					// БОЙ
					Enemies MageTemp = DarkMage;
					Enemies VampireTemp = VampireLord;
					Enemies DragonTemp = AncientDragon;
					std::cout << "\n*** Битва началась! ***\n" << std::endl;

					while ((MageTemp.isAviable() || VampireTemp.isAviable() || DragonTemp.isAviable()) && User.isAviable()) {
						int a = 1 + rand() % 100;
						int b = 1 + rand() % 100;
						int result = a + b;
						int result_user;

						std::cout << a << " + " << b << " = ? ";
						std::cin >> result_user;

						if (result_user == result) {
							std::cout << "✓ Верно! Враги получили 10 урона!" << std::endl;
							MageTemp.set_health(10);
							VampireTemp.set_health(10);
							DragonTemp.set_health(10);
						}
						else {
							std::cout << "✗ Неправильно! Вы получили 100 урона!" << std::endl;
							User.set_health(100);
						}
						std::cout << "Ваше здоровье: " << User.show_health() << " | Mage: " << MageTemp.show_health() << " | Vampire: " << VampireTemp.show_health() << " | Dragon: " << DragonTemp.show_health() << "\n" << std::endl;
					}

					if (User.isAviable()) {
						std::cout << "=== ВЫ ВЫИГРАЛИ! ===" << std::endl;
					}
					else {
						std::cout << "=== ВЫ ПРОИГРАЛИ! ===" << std::endl;
					}
					fighting = false;  // Выход после боя
				}
				else if (choiceextreme == 3) {
					fighting = false;  // Выход в главное меню
				}
			}
			break;
		}

		
		case 5: { // BOSS FIGHT
			Enemies DemonLord;
			DemonLord.set_data("Demon Lord", 1000, 200);

			bool fighting = true;
			while (fighting) {
				std::cout << "\n----- BOSS FIGHT -----" << std::endl;
				std::cout << "1) Информация о боссе\n2) Начать бой\n3) Назад в меню" << std::endl;
				int choiceboss = 0;
				std::cin >> choiceboss;

				if (choiceboss == 1) {
					DemonLord.show_info();
				}
				else if (choiceboss == 2) {
					// БОЙ С БОССОМ
					Enemies DemonTemp = DemonLord;
					std::cout << "\n*** ЭТО БОССОВАЯ АРЕНА! ***\n" << std::endl;

					while (DemonTemp.isAviable() && User.isAviable()) {
						int a = 1 + rand() % 100;
						int b = 1 + rand() % 100;
						int result = a + b;
						int result_user;

						std::cout << a << " + " << b << " = ? ";
						std::cin >> result_user;

						if (result_user == result) {
							std::cout << "✓ Верно! Босс получил 10 урона!" << std::endl;
							DemonTemp.set_health(10);
						}
						else {
							std::cout << "✗ Неправильно! Вы получили 200 урона!" << std::endl;
							User.set_health(200);
						}
						std::cout << "Ваше здоровье: " << User.show_health() << " | Босс: " << DemonTemp.show_health() << "\n" << std::endl;
					}

					if (User.isAviable()) {
						std::cout << "=== ВЫ ПОБЕДИЛИ БОССА! ПОЗДРАВЛЯЕМ! ===" << std::endl;
					}
					else {
						std::cout << "=== БОСС ВАС РАЗГРОМИЛ! ===" << std::endl;
					}
					fighting = false;  // Выход после боя
				}
				else if (choiceboss == 3) {
					fighting = false;  // Выход в главное меню
				}
					}
					break;
					}

					case 0: {
						std::cout << "Спасибо за игру! До встречи!" << std::endl;
						gameRunning = false;
						break;
					}

					default:
						std::cout << "Неправильный выбор. Попробуйте снова." << std::endl;
					}
				}

				return 0;
			}
