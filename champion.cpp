#include "champion.h"

Champion::Champion()
{
	for ( unsigned int i = 0; i < NUM_CHAMP_STATS; i++ )
		stats[i] = 0;
}

void Champion::init()
{
	// set starting hp/mana/dmg etc
	stats[CHAMP_HP] = stats[CHAMP_BASEHP] + stats[CHAMP_BONUSHP];
	stats[CHAMP_HPREGEN] = stats[CHAMP_BASEHPREGEN] + stats[CHAMP_BONUSHPREGEN];
	stats[CHAMP_RESOURCE] = stats[CHAMP_BASERESOURCE] + stats[CHAMP_BONUSRESOURCE];
	stats[CHAMP_RESOURCEREGEN] = stats[CHAMP_BASERESOURCEREGEN] + stats[CHAMP_BONUSRESOURCEREGEN];
	stats[CHAMP_DMG] = stats[CHAMP_BASEDMG] + stats[CHAMP_BONUSDMG];
	stats[CHAMP_ATKSPEED] = stats[CHAMP_BASEATKSPEED];
	stats[CHAMP_ARMOR] = stats[CHAMP_BASEARMOR] + stats[CHAMP_BONUSARMOR];
	stats[CHAMP_MR] = stats[CHAMP_BASEMR] + stats[CHAMP_BONUSMR];
	stats[CHAMP_MOVEMENTSPEED] = stats[CHAMP_BASEMOVEMENTSPEED] + stats[CHAMP_BONUSMOVEMENTSPEED];
	stats[CHAMP_RANGE] = stats[CHAMP_BASERANGE];
	stats[CHAMP_LIFESTEAL] = stats[CHAMP_BONUSLIFESTEAL];
	stats[CHAMP_SPELLVAMP] = stats[CHAMP_BONUSSPELLVAMP];
	stats[CHAMP_HEALMOD] = 1.;
	stats[CHAMP_LEVEL] = 0.;
}

void Champion::levelup()
{
	if ( stats[CHAMP_LEVEL] >= 18 ) return;
	stats[CHAMP_LEVEL]++;
	stats[CHAMP_HP] += stats[CHAMP_HPPERLEVEL];
	stats[CHAMP_HPREGEN] += stats[CHAMP_HPREGENPERLEVEL];
	stats[CHAMP_RESOURCE] += stats[CHAMP_RESOURCEPERLEVEL];
	stats[CHAMP_RESOURCEREGEN] += stats[CHAMP_RESOURCEREGENPERLEVEL];
	stats[CHAMP_DMG] += stats[CHAMP_DMGPERLEVEL];
	stats[CHAMP_ATKSPEED] = stats[CHAMP_BASEATKSPEED] * (stats[CHAMP_ATKSPEEDPERLEVEL]*(stats[CHAMP_LEVEL]-1)+stats[CHAMP_BONUSATKSPEED] + 100.) / 100.;
	stats[CHAMP_ARMOR] += stats[CHAMP_ARMORPERLEVEL];
	stats[CHAMP_MR] += stats[CHAMP_MRPERLEVEL];
}

bool Champion::iseffectactive(char * effectname)
{
	int len = strlen(effectname);
	for ( unsigned int i = 0; i < activeeffects.size(); i++ )
	{
		if ( strnicmp(effectname, activeeffects[i].effectname, len) == 0 )
			return true;
	}
	return false;
}
// remove all stacks of some effect
void Champion::removeeffect(char * effectname)
{
	int len = strlen(effectname);
	std::vector<PersistentEffect>::iterator itt = activeeffects.begin();
	while ( itt != activeeffects.end() )
	{
		if ( strnicmp((*itt).effectname, effectname, len) == 0 )
			activeeffects.erase(itt);
		else itt++;
	}
}

void Champion::removeeffect(int effectid)
{
	for ( unsigned int i = 0; i < activeeffects.size(); i++ )
	{
		if ( activeeffects[i].effectid == effectid )
		{
			activeeffects.erase(activeeffects.begin()+i);
			return;
		}
	}
}
