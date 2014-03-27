#include "Caitlyn.h"

Caitlyn::Caitlyn()
{
	strcpy(champname, "Caitlyn");
	// set the base stats
	stats[CHAMP_BASEHP] = 390;
	stats[CHAMP_HPPERLEVEL] = 80;
	stats[CHAMP_BASEHPREGEN] = 4.75;
	stats[CHAMP_HPREGENPERLEVEL] = 0.55;
	stats[CHAMP_BASERESOURCE] = 255;
	stats[CHAMP_RESOURCEPERLEVEL] = 35;
	stats[CHAMP_BASERESOURCEREGEN] = 6.5;
	stats[CHAMP_RESOURCEREGENPERLEVEL] = 0.55;
	stats[CHAMP_BASEDMG] = 47;
	stats[CHAMP_DMGPERLEVEL] = 3.;
	stats[CHAMP_BASEATKSPEED] = 0.668;
	stats[CHAMP_ATKSPEEDPERLEVEL] = 3; 
	stats[CHAMP_BASEARMOR] = 13;
	stats[CHAMP_ARMORPERLEVEL] = 3.5;
	stats[CHAMP_BASEMR] = 30;
	stats[CHAMP_MRPERLEVEL] = 0.;
	stats[CHAMP_BASEMOVEMENTSPEED] = 325;
	stats[CHAMP_BASERANGE] = 650; 
	// initiate
	init();
	levelup();
	aacounter=0;
}

void Caitlyn::autoattack(Champion * target, double dmg, double time)
{

	int targethits=6;
	// implement her passive
	// check if headshot is active
	if ( iseffectactive("Headshot") )
	{
		
	}
	else
	{
		if ( stats[CHAMP_LEVEL] < 7 ) // 1..6 bonus dmg procs on 8th hit
		{
			targethits=8;
		} else if ( stats[CHAMP_LEVEL] < 13 ) // 7..12  bonus dmg procs on 7th hit
		{
			targethits=7;
		}
		if ( aacounter >= targethits )
		{
			PersistentEffect eff;
			eff.atkdmgmod=50; // 50% atk dmg increase
			eff.duration=9001; // over 9000
			strcpy(eff.effectname, "Headshot");
			eff.effectid=activeeffects.size();
			eff.start_time=time;
			activeeffects.push_back(eff);
			aacounter=0;
		}
	}

}
