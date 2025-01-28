/* Tony Nordstrom */
/* January 27 02025 */
/* Chapter 13.x quiz question 1 */

#include <iostream>

enum Race
{
	Ogre,
	Dragon,
	Orc,
	Giant_Spider,
	Slime
};

struct Monster
{
	Race type;
	std::string name;
	int health;
};
	
/* From Chapter 13.5 Overloading operator<< to print an enumerator */
constexpr std::string_view getMonsterRace(Race type)
{
	switch(type)
	{
		case Ogre: return "Ogre";
		case Dragon: return "Dragon";
		case Orc: return "Orc";
		case Giant_Spider: return "Giant Spider";
		case Slime: return "Slime";
		default: return "Unknown";
	}
}

std::ostream& operator<<(std::ostream& out, Race type)
{
	out << getMonsterRace(type);
	return out;
}

void printMonster(Monster &data)
{
	std::cout << "This " << data.type << " is named " << data.name << " and has " << data.health << " health.\n";

	return;
}

int main ( void )
{
	Monster monster1 { Ogre, "Biff", 145 };
	Monster monster2 { Slime, "Goo", 23 };
	
	printMonster(monster1);
	printMonster(monster2);
	
	return 0;
}
