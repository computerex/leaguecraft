#include <stdio.h>
#include "champion.h"
#include "Caitlyn.h"

int main()
{
	Caitlyn cait;
	printf("hp: %.2f\n", cait.stats[CHAMP_HP]);
	printf("mana: %.2f\n", cait.stats[CHAMP_RESOURCE]);
	printf("hp5: %.2f\n", cait.stats[CHAMP_HPREGEN]);
	printf("atkspeed: %.2f\n", cait.stats[CHAMP_ATKSPEED]);
	printf("armor: %.2f\n", cait.stats[CHAMP_ARMOR]);
	printf("mr: %.2f\n", cait.stats[CHAMP_MR]);
	printf("ms: %.2f\n", cait.stats[CHAMP_MOVEMENTSPEED]);
	getchar();
	return 0;
}