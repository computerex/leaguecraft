#ifndef H_COMPUTEREX_LEAGUE_SIM_CHAMPION_H_
#define H_COMPUTEREX_LEAGUE_SIM_CHAMPION_H_

#include <vector>

// base class for champions
// override callback functions to handle 
// events such as damage events

enum CHAMP_STATS {
 CHAMP_BASEHP, 
 CHAMP_HPPERLEVEL,
 CHAMP_BONUSHP,
 CHAMP_HP,                            

 CHAMP_BASEHPREGEN,                 
 CHAMP_HPREGENPERLEVEL,
 CHAMP_BONUSHPREGEN,
 CHAMP_HPREGEN,                      

 CHAMP_BASERESOURCE,                    
 CHAMP_RESOURCEPERLEVEL,
 CHAMP_BONUSRESOURCE,
 CHAMP_RESOURCE,                    

 CHAMP_BASERESOURCEREGEN,               
 CHAMP_RESOURCEREGENPERLEVEL,
 CHAMP_BONUSRESOURCEREGEN,
 CHAMP_RESOURCEREGEN,               

 CHAMP_BASEDMG,
 CHAMP_DMGPERLEVEL,     
 CHAMP_BONUSDMG,
 CHAMP_DMG,                         

 CHAMP_BASEATKSPEED,                
 CHAMP_ATKSPEEDPERLEVEL,
 CHAMP_BONUSATKSPEED,
 CHAMP_ATKSPEED,                    

 CHAMP_BASEARMOR,                   
 CHAMP_ARMORPERLEVEL,
 CHAMP_BONUSARMOR,
 CHAMP_ARMOR,                       

 CHAMP_BASEMR,                      
 CHAMP_MRPERLEVEL,                  
 CHAMP_BONUSMR,
 CHAMP_MR,                           

 CHAMP_BONUSCDR,
 
 CHAMP_BONUSFLATARMORPEN,
 CHAMP_BONUSPERCENTARMORPEN,
 CHAMP_BONUSMAGICPEN, 
 CHAMP_BONUSPERCENTMAGICPEN,

 CHAMP_BASEMOVEMENTSPEED,
 CHAMP_BONUSMOVEMENTSPEED,
 CHAMP_MOVEMENTSPEED,               

 CHAMP_BASERANGE,                   
 CHAMP_RANGE,                       

 CHAMP_LIFESTEAL,       
 CHAMP_BONUSLIFESTEAL,

 CHAMP_SPELLVAMP,                   
 CHAMP_BONUSSPELLVAMP, 

 CHAMP_HEALMOD,      
 CHAMP_LEVEL,

 NUM_CHAMP_STATS 

};
 
class PersistentEffect
{
public:
	PersistentEffect()
	{
		dmgtakenmod = healmod = hpregenmod = hpmod = armormod = mrmod = movementmod = atkspeedmod = atkdmgmod = dot = cdrmod = duration = start_time = maxstacks = effectid = 1;
		dot=0;
		strcpy(effectname, "deadbeef");
		buff=false;
	}
	char effectname[256];
	double dmgtakenmod, healmod, hpregenmod, hpmod, armormod, mrmod, movementmod, atkspeedmod, atkdmgmod, dot, cdrmod;
	double duration;
	double start_time;
	int maxstacks, effectid;
	bool buff;
};

class Spell
{
public:
	char name[256];
	double cooldown, casttime, lastcasttime;
	int rank; 
	std::vector<PersistentEffect> rankdependanteffects;
	std::vector<PersistentEffect> rankindependanteffects;
	bool interruptable; 
};

class Champion
{
public:
	Champion();
	// stats
	double stats[NUM_CHAMP_STATS];
	char champname[256];
	std::vector<PersistentEffect> activeeffects;

public:
	void init(); 
	void levelup();
	void heal(double hp);
	void takedmg(double dmg);
	void autoattack(Champion * target, double dmg, double time);
	void usespell(Champion * target, double time);
	

	bool iseffectactive(char * effectname);
	void removeeffect(char * effectname);
	void removeeffect(int effectid);
};

#endif
