#include "SkillList.h"
#include "UnitObject.h"

SkillList::SkillList()
{
	for (int i = 0; i < NUM_OF_SKILLS; i++) {
		skill_values[i] = BASE_SKILL;
	}
}

void SkillList::change_skill(Skill skill, int change)
{

}

Skill SkillList::random_skill()
{
	int num = rand() % NUM_OF_SKILLS;

	return Skill(num);
}




void SkillList::print_list()
{
	std::cout << "Skills " << std::endl
		<< "WEALTH: " << skill_values[WEALTH] << std::endl
		<< "MILITARY: " << skill_values[WEALTH] << std::endl
		<< "SCIENCE: " << skill_values[WEALTH] << std::endl
		<< "ART: " << skill_values[WEALTH] << std::endl
		<< "THIEF: " << skill_values[WEALTH] << std::endl;
}

