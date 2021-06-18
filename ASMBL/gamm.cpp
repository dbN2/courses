#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;


class Char
{
	private:
		int charLevel; 
		int charHealth;
		int charStrength;
		string charItems;
	
	public:
		void saveGame(ofstream &stream);
		void loadGame(ifstream &stream);	
		void getStats();
		friend void Fight1(Char x);
		void levelUp();
};

void Intro();
void Intermission1();
	
int main()
{
	ifstream stream ("save.txt");
	ofstream ostream;
	Char player;
	player.loadGame(stream);
	Intro();
	player.getStats();
	Fight1(player);
	player.levelUp();
	player.getStats();
	player.saveGame(ostream);
	
}

void Char::saveGame(ofstream &stream)
{
		stream.open("save.txt");
		if (stream.fail())
		{
			cout<<"Error..."<<endl;
			exit(0);
		}
		stream << charLevel << endl;
		stream << charHealth << endl;
		stream << charStrength << endl;
		stream.close();
}
	
void Char::loadGame(ifstream &stream)
{
	stream.open("save.txt");
	stream >> charLevel;
	
	if ( charLevel<=0 || charLevel>9)
	{
		cout<<"New player."<<endl;
		charLevel = 1;
		charHealth = 10;
		charItems = "";
		charStrength = 2;
	}
	else
	{
		cout<< "Loading data...\n";
  		stream >> charLevel;
  		cout<<charLevel<<endl;
		stream.close();
	}
}

void Char::getStats()
{
	cout<< "Char level is: " <<charLevel << endl;
	cout<< "Char health is: " <<charHealth << endl;
	cout<< "Char items are: " <<charItems << endl;
	system("pause");
}

void Char::levelUp()
{
	charLevel++;
	charHealth+=2;
	charStrength++;
}

void Intro()  //Int
{
	cout<< "\"You're there aren't you...\"\n";
	system("pause");
	cout<< "\"Don't look at me. I'm a monster...\"\n";
	system("pause");
	cout<< "You wake up in a dark room. There are no windows...\n";
	cout<< "It feels warm and you struggle to breathe.\n";
	cout<< "You strain your ears and hear the sound of soft, melancholy guitars coming from the machine... Are you hallucinating?\n";
	cout<< "You walk to the bathroom. It feels like you've been there before.\n";
	cout<< "The lights flicker and die as you turn them on. They don't work...\n";
	cout<< "Looking in the mirror in the dim bathroom, you glance over your body...\n\n";
	system("pause");
	cout<< "It's unnerving. You're not ugly, but you look a little strange.\n";
	system("pause");
}

void Fight1(Char x)  //F1
{
	int enemyHealth = x.charLevel *10;
	cout<< "As you stare, you catch a figure moving in the mirror.\n";
	system("pause");
	cout<< "You realize it is several feet behind you.\n";
	system("pause");
	cout<< "Frozen with fear. Your heart thumping. It lunges towards you and pushes you against the sink. You grab a pair of scissors lying on the counter.\n";
	cout<< "And only then do you take in its appearance.\n\n\n";
	
	while (x.charHealth>0)
	{
		cout<< "1. Attack \n2. Special Attack \n3. Run \n";
		int choice; cin>>choice;
	
		if (choice == 1)
		{
			cout<<x.charStrength;
			enemyHealth -= x.charStrength + rand() % 5 - 2;
			cout << "You stab the creature in the chest. It doesn't make a sound...\n";
			cout << "enemy health: " << enemyHealth <<endl;
			system("pause");
			x.charHealth -= 2;
			cout << "It pitifully strikes you... .\n";
			system("pause");
		}
		else if (choice ==2)
		{
			cout << "Nothing happens. It slashes at you ... You see blood splatter.\n";
			x.charHealth-=2;
			system("pause");
		}
		else
		{
			cout << "You can't run away.\n";
			cout << "The creature sinks its teeth into your arm. You scream.\n";
			x.charHealth-=2;
			system("pause");
		}
		if (enemyHealth<=0)
		{
			cout << "The creature stares into your eyes, and crumples over. It's dead...\n";
			system("pause");
			break;
			break;
		}
		if (x.charHealth<=0)
		{
			cout << "You're dead...\n";
			system("pause");
			cout << "Friendly reminder Wolfe Cat owes me $139.\n";
			system("pause");
		}
		
	}
}

void Intermission1()
{
	
}
