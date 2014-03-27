#ifndef _H_COMPUTEREX_LEAGUE_SIM_CHAMPION_CAITLYN_H_
#define _H_COMPUTEREX_LEAGUE_SIM_CHAMPION_CAITLYN_H_

#include "champion.h"

class Caitlyn : public Champion
{
public:
	Caitlyn();
	void autoattack(Champion * target, double dmg, double time);
	void usespell(Champion * target, double time);
	int aacounter;
};

#endif