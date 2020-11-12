#include "Battle.h"

Battle::Battle()
{
	ongoing = false;
}


BATTLE_RESULT Battle::single_fight(std::shared_ptr<UnitObject>  first, std::shared_ptr<UnitObject>  second)
{
	BATTLE_TYPE type = choose_attack();
	//Skill skill = choose_skill();
	switch (type)
	{
	case BATTLE_TYPE::NORMAL:
		break;
	case BATTLE_TYPE::DEFEND:
		break;
	case BATTLE_TYPE::DOMINATE:
		break;
	default:
		break;
	}
	return BATTLE_RESULT::CAPTURE;
}

//BATTLE_TYPE Battle::choose_attack()
//{

//}