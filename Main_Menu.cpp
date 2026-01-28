#include "Main_Menu.h"

Main_Menu::~Main_Menu()
{
	//std::cout << "Menu DTor\n";
	if(mUserCharacter)
	{
		delete mUserCharacter;
		mUserCharacter = nullptr;
	}

	if (mSecondCharacter)
	{
		delete mSecondCharacter;
		mSecondCharacter = nullptr;
	}
}

CharacterClass Main_Menu::UserClasses(int _offset)
{
	std::vector<GameClass> classes =
	{
		{1000, CharacterClass::WARRIOR, Race::HUMAN, "Warrior"},
		{1001, CharacterClass::ARCHER, Race::HUMAN, "Archer"},
		{1002, CharacterClass::MAGE, Race::HUMAN, "Mage"},
		{1003, CharacterClass::PRIEST, Race::HUMAN, "Priest"},
		{2000, CharacterClass::WARRIOR, Race::UNDEAD, "Warrior"},
		{2001, CharacterClass::ARCHER, Race::UNDEAD, "Archer"},
		{2002, CharacterClass::MAGE, Race::UNDEAD, "Mage"},
		{2004, CharacterClass::DEATH_KNIGHT, Race::UNDEAD, "Death Knight"}
	};


	for (auto& a : classes)
	{
		if (_offset == a.classID)
		{
			return a.charClass;
		}
	}
	return CharacterClass::DEFAULT_CLASS;

}

void Main_Menu::RaceMenu()
{
	int userChoice;
	bool bValidChoice = false;
	std::string userFirstName;
	std::string userLastName;
	do {
		std::cout << "Welcome to Character select screen\nPlease select a Race:\n1 = Human\n2 = Undead\nSelection: ";
		std::cin >> userChoice;
		std::cout << "Enter Characters first name: ";
		std::cin >> userFirstName;
		std::cout << "Enter Character last name: ";
		std::cin >> userLastName;

		switch (userChoice)
		{
		case 1:
			mUserRace = Race::HUMAN;
			std::cout << "Human Choose\n";
			GenderMenu();
			bValidChoice = true;
			bRaceSelected = true;
	
			if (bCharacter1RdyCreate)
			{
				if (mUserCharacter)
				{
					delete mUserCharacter;
					mUserCharacter = nullptr;
				}
				mUserCharacter = CreateCharacter(mUserRace, userFirstName, userLastName, mGender);
			}

			if (bCharacter2RdyCreate)
			{
				if (mSecondCharacter)
				{
					delete mSecondCharacter;
					mSecondCharacter = nullptr;

				}
				mSecondCharacter = CreateCharacter(mUserRace, userFirstName, userLastName, mGender);
			}
			
			break;

		case 2:
			mUserRace = Race::UNDEAD;
			std::cout << "Undead Choose\n";
			GenderMenu();
			bValidChoice = true;
			bRaceSelected = true;

			if(bCharacter1RdyCreate)
			{
				if (mUserCharacter)
				{
					delete mUserCharacter;
					mUserCharacter = nullptr;
				}
				mUserCharacter = CreateCharacter(mUserRace, userFirstName, userLastName, mGender);
			}

			if (bCharacter2RdyCreate)
			{
				if (mSecondCharacter)
				{
					delete mSecondCharacter;
					mSecondCharacter = nullptr;
				}
				mSecondCharacter = CreateCharacter(mUserRace, userFirstName, userLastName, mGender);
			}

			break;

		default:
			break;
		}

	} while (!bValidChoice);
}

void Main_Menu::ClassMenu()
{
	int userChoice = 0;
	int offset = (mUserRace == Race::HUMAN) ? 1000 : 2000;
	int id = 0;
	bool bValidChoice = false;
	do {

		std::cout << "Please choose a class\n1 = Warrior\n2 = Archer\n3 = Mage\n4 = Priest\n5 = Death Knight\nSelection: ";
		std::cin >> userChoice;
		id = offset + (userChoice - 1);

		switch (userChoice)
		{

		case 1:

			std::cout << "Warrior chose\n";
			bValidChoice = true;

			break;

		case 2:

			std::cout << "Archer chose\n";
			bValidChoice = true;
			break;

		case 3:

			std::cout << "Mage chose\n";
			bValidChoice = true;
			break;

		case 4:

			if (mUserCharacter)
			{
				if (mUserCharacter->GetRace() == Race::HUMAN)
				{
					std::cout << "Priest chose\n";
					bValidChoice = true;
				}
				else {
					mUserCharacter->Display();
					std::cout << "------------\n";
					std::cout << "Must be human to pick this class, choose a different class\n\n";
					bValidChoice = false;
				}
			}

			if (mSecondCharacter)
			{
				if (mSecondCharacter->GetRace() == Race::HUMAN)
				{
					std::cout << "Priest chose\n";
					bValidChoice = true;
				}
				else {
			
					mSecondCharacter->Display();
					std::cout << "------------\n";
					std::cout << "Must be human to pick this class, choose a different class\n\n";
					bValidChoice = false;
				}
			}

			break;

		case 5:

			if (mUserCharacter)
			{
				if (mUserCharacter->GetRace() == Race::UNDEAD)
				{
					std::cout << "Death Knight chose\n";
					bValidChoice = true;
				}
				else {
		
					mUserCharacter->Display();
					std::cout << "------------\n";
					std::cout << "Must be undead to pick this class, choose a different class\n\n";
					bValidChoice = false;
				}
			}

			if (mSecondCharacter)
			{
				if (mSecondCharacter->GetRace() == Race::UNDEAD)
				{
					std::cout << "Death Knight chose\n";
					bValidChoice = true;
				}
				else {
					system("cls");
					mSecondCharacter->Display();
					std::cout << "------------\n";
					std::cout << "Must be undead to pick this class, choose a different class\n\n";
					bValidChoice = false;
				}
			}

			break;
		}
	} while (!bValidChoice);

	if (bCharacter1RdyCreate)
	{
		if (mUserCharacter)
		{
			mUserCharacter->SetClass(UserClasses(id));
			mUserCharacter->SetWeapon(mUserCharacter->GetClass());
			if (mUserCharacter->GetWeapon()->GetWeaponType() != WeaponType::DEFAULT_TYPE)
			{
				bWeaponSelected = true;
				bCharacter1RdyCreate = false;
			}
		}
	}

	if (bCharacter2RdyCreate)
	{
		if (mSecondCharacter)
		{
			mSecondCharacter->SetClass(UserClasses(id));
			mSecondCharacter->SetWeapon(mSecondCharacter->GetClass());
			if (mSecondCharacter->GetWeapon()->GetWeaponType() != WeaponType::DEFAULT_TYPE)
			{
				bSecondWeaponSelected = true;
				bCharacter2RdyCreate = false;
			}
		}
	}
}

void Main_Menu::GenderMenu()
{
	int userChoice;
	bool bValidChoice = false;
	do {
		std::cout << "Please select a gender\n1: Male\n2: Female\nSelection: ";
		std::cin >> userChoice;
		switch (userChoice)
		{
		case 1:
			mGender = Gender::MALE;
			std::cout << "Male chosen\n";
			bValidChoice = true;
			break;
		case 2:
			mGender = Gender::FEMALE;
			std::cout << "Female chosen\n";
			bValidChoice = true;
			break;
		default:
			break;
		}

	} while (!bValidChoice);

	
}

void Main_Menu::BeginMenu()
{
	int userChoice;
	bool bValidSelection = false;

	do {

		std::cout << "Play Game\n1: Create Character\n2: Create Second Character\n3: Play Game\n4: Exit\nSelection: ";
		std::cin >> userChoice;

	switch (userChoice)
	{
	case 1:
		bValidSelection = true;
		if (bCharacter1Complete)
		{
			system("cls");
			std::cout << "Character 1 has already been created, please select a different option\n";
			bValidSelection = false;
			break;
		}
		bCharacter1RdyCreate = true;
		RaceMenu();
		if (bRaceSelected && mUserCharacter)
		{		
			ClassMenu();
			bCharacter1Complete = true;
			bValidSelection = false;
			system("cls");
		}
		else {
			std::cout << "Please choose a race before a class\n";
			bValidSelection = false;
		}
		break;
		
	case 2:
		bValidSelection = true;
		if (bCharacter2Complete)
		{
			system("cls");
			std::cout << "Character 2 has already been created, please select a different option\n";
			bValidSelection = false;
			break;
		}
		bCharacter2RdyCreate = true;
		RaceMenu();
		if (bRaceSelected && mSecondCharacter)
		{
			ClassMenu();
			bCharacter2Complete = true;
			bValidSelection = false;
			system("cls");
		}
		else {
			std::cout << "Please choose a race before a class\n";
			bValidSelection = false;
		}
		break;

	case 3:
		if(!bCharacter1Complete && !bCharacter2Complete)
		{
			std::cout << "Please finish creating the characters\n";
			bValidSelection = false;
		}
		else {
			system("cls");
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> dis(1, 100);

			int p1 = dis(gen);
			int p2 = dis(gen);

			std::cout << mUserCharacter->GetFirstName() << " rolls " << p1 << '\n';
			std::cout << mSecondCharacter->GetFirstName() << "  rolls " << p2 << '\n';

			if (p1 > p2)
			{
				std::cout << mUserCharacter->GetFirstName() << " goes 1st" << '\n';
				bPlayer1First = true;
				bPlayer1Turn = true;
				PlayGame();
			}
			else {
				std::cout << mSecondCharacter->GetFirstName() << " goes 1st" << '\n';
				bPlayer2First = true;
				bPlayer2Turn = true;
				PlayGame();
			}
			bValidSelection = true;
		}
			break;

	case 4:
		bValidSelection = true;
		break;

	default:
		break;
	}
	
	} while (!bValidSelection);
}

void Main_Menu::PlayGame()
{
	mGameMode = SetGameMode();
	if (!mUserCharacter || !mSecondCharacter || !mGameMode) return;

	int userChoice;
	bool bValidSelection = false;
	do {
		mUserCharacter->DisplayStats();
		mSecondCharacter->DisplayStats();
		std::cout << "Please select a action\n1: Attack\n2: Exit\nSelection: ";
		std::cin >> userChoice;
		switch (userChoice)
		{
		case 1:
			if (bPlayer1First || bPlayer1Turn)
			{
				bPlayer1First = false;
				mGameMode->Attack(mUserCharacter);
				bPlayer1Turn = false;
				bPlayer2Turn = true;
			}

			else if(bPlayer2First || bPlayer2Turn)
			{
				bPlayer2First = false;
				mGameMode->Attack(mSecondCharacter);
				bPlayer2Turn = false;
				bPlayer1Turn = true;
			}
			bValidSelection = false;
			
			break;

		case 2:
			bValidSelection = true;
			break;
			
		default:
			break;
		}
		std::cin.get();
		std::cout << "Press Enter to Continue\n";
		system("cls");
		
	} while (!bValidSelection);
}

GameMode* Main_Menu::SetGameMode()
{
	return new GameMode();
}

Character* Main_Menu::CreateCharacter(Race _race, std::string _firstName, std::string _lastName, Gender _gen)
{
	switch (_race)
	{
	case Race::HUMAN:
	
		return new Human(_firstName, _lastName, 750, _gen);

	case Race::UNDEAD:
	
		return new Undead(_firstName, _lastName, 800, _gen);

	default:
		return nullptr;
	}
	
}
