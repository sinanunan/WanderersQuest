#include "SkillList.h"
#include "UnitObject.h"

SkillList::SkillList(UnitObject player)
{
	for (int i = 0; i < NUM_OF_SKILLS; i++) {
		// increase based on character
		skill_values[i] = 0;
	}
}

void SkillList::change_skill(UnitObject player, Skill skill, int increment)
{

}
