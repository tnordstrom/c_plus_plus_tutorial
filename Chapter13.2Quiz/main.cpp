/* Tony Nordstrom */
/* December 16 02024 */
/* C++ Tutorial 13.2 Quiz */
/* To build: g++ -Wall -o "main" "main.cpp" */
/* To run: ./main.exe */

namespace Monsters
{
    enum MonsterType
    {
        orc,
        goblin,
        troll,
        ogre,
        skeleton,
    };
};

int main(void)
{
    [[maybe_unused]] Monsters::MonsterType monster { Monsters::troll };
    
    return 0;
}


