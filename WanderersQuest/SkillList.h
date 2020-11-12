#ifndef SKILL_LIST_H
#define SKILL_LIST_H

#include <vector>
enum Skill { WEALTH, MILITARY, SCIENCE, ART, THIEF };

class UnitObject;
class SkillList
{
private:
	
public:
	SkillList();

	void change_skill(Skill skill, int change);
	static Skill random_skill();

	void print_list();

private:
	static const int NUM_OF_SKILLS = 5;
	
	int skill_values[NUM_OF_SKILLS];

	const int MAX_SKILL = 100;
	const int BASE_SKILL = 20;


};
#endif