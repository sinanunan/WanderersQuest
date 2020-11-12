#ifndef SKILL_LIST_H
#define SKILL_LIST_H

class UnitObject;
class SkillList
{
private:
	enum Skill { WEALTH, MILITARY, SCIENCE, ART, THIEF };

public:
	SkillList(UnitObject player);

	void change_skill(UnitObject player, Skill skill, int increment);

private:
	static const int NUM_OF_SKILLS = 5;
	int skill_values[NUM_OF_SKILLS];


};
#endif