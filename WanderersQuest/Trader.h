#ifndef TRADER_H
#define TRADER_H



#include "UnitObject.h"
#include "Settlement.h"

class Trader : public Settlement
{
public:
	Trader(ArrayPos pos, int level);

	void render(SDL_Rect& dest);
	std::shared_ptr<std::list<std::shared_ptr<UnitObject>>> use(std::shared_ptr<UnitObject>  unit);


	static SDL_Texture* trader_tex;

};

#endif

