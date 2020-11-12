#ifndef SETTLEMENT_H
#define SETTLEMENT_H

#include "CoorTypes.h"
#include "SettlementEnum.h"
#include "SDL.h"
#include <list>
#include "UnitObject.h"

// Decleration for Superclass Settlement

class Settlement
{

public:
	
	static SDL_Renderer* renderer;
	
	// factory function
	static std::unique_ptr<Settlement> make_settlement(SettlementEnum type, ArrayPos pos, int level);

	// virtual functions
	virtual std::shared_ptr<std::list<std::shared_ptr<UnitObject>>> use(std::shared_ptr<UnitObject>  unit) = 0;
	virtual void render(SDL_Rect& dest) = 0;

	ArrayPos get_pos() { return pos; };
	bool is_visited() { return visited; };
		

protected:

	Settlement(ArrayPos pos, int level);

	// Each settlement has a position in the hexmap and a level
	ArrayPos pos;
	int level;
	bool visited; // If is the first player to visit, gain more rewards
};
#endif 