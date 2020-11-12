#include "Settlement.h"
#include "Arena.h"
#include "Trader.h"

SDL_Renderer* Settlement::renderer = NULL;

// Constructor for settlement
// Each settlement has a position, level and starts not visited
Settlement::Settlement(ArrayPos pos, int level) : pos(pos), level(level)
{
	visited = false;
}

// Settlement factory function
std::unique_ptr<Settlement> Settlement::make_settlement(SettlementEnum type, ArrayPos pos, int level)
{

	switch (type)
	{
	case SettlementEnum::ARENA:
		return std::make_unique<Arena>(pos, level);
		break;
	case SettlementEnum::TRADER:
		return std::make_unique<Trader>(pos, level);
		break;
	case SettlementEnum::TRAINER:
		break;
	default:
		break;
	}
}
