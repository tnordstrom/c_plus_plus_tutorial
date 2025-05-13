/* May 12 02025 */
/* Chapter 15.x Quiz up to question f */
/* Tony Nordstrom */

#include <iostream>
#include <string>
#include <string_view>

class Monster
{
	public:
	
	enum Type
	{
		dragon,
		goblin,
		ogre,
		orc,
		skeleton,
		troll,
		vampire,
		zombie,
		maxMonsterTypes,
	};
	
	private:
	
		Type m_type{};
		std::string m_name{"???"};
		std::string m_roar{"???"};
		int m_hitPoints{};
		
	public:
	
	Monster(Type type, std::string_view name, std::string_view roar, int hitPoints)
	: m_type{ type }, m_name{ name }, m_roar{ roar }, m_hitPoints{ hitPoints }	
	{
	}
	
	constexpr std::string_view getTypeString() const
	{
		switch (m_type)
		{
			case dragon:
				return "dragon";
			case goblin:
				return "goblin";
			case ogre:
				return "ogre";
			case orc:
				return "orc";
			case skeleton:
				return "skeleton";
			case troll:
				return "troll";
			case vampire:
				return "vampire";
			case zombie:
				return "zombie";
			default:
				return "???";
		}
	}
	
	void print() const
	{
		std::cout << m_name << " the " << getTypeString();
		
		if (m_hitPoints <= 0)
		{
			std::cout << " is dead\n";
		}
		else
		{
			std::cout << " has " << m_hitPoints << " hit points and says " << m_roar << '\n';
		}
		
		return;
	}
		
};

int main()
{
	Monster skeleton( Monster::skeleton, "Bones", "Rattle", 4);
	skeleton.print();
	
	Monster vampire( Monster::vampire, "Nibblez", "Hiss", 0);
	vampire.print();
	
	return 0;
}
