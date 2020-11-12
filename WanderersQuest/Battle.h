#ifndef BATTLE_H
#define BATTLE_H

#include "UnitObject.h"
#include "SkillList.h"
enum class BATTLE_RESULT { KILL, CAPTURE, DIE, DOMINATE };
enum class BATTLE_TYPE {NORMAL, DEFEND, DOMINATE};

class Battle
{

public:
	
	Battle();

	static BATTLE_RESULT single_fight(std::shared_ptr<UnitObject>  first, std::shared_ptr<UnitObject>  second);

	static BATTLE_TYPE choose_attack() { return BATTLE_TYPE::DEFEND; };

	bool is_ongoing() { return ongoing; };
	
private:

	BATTLE_TYPE type;
	Skill skill;

	bool ongoing;
};


#endif 
