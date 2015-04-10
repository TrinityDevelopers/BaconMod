#ifndef TILEENTITYBEACON_H_
#define TILEENTITYBEACON_H_

#include "FillingContainer.h"
#include "TileEntity.h"
#include <lw.h>

class TileEntityBeacon : public TileEntity, public FillingContainer {
private:
	long long field_146016_i = 0;
	float field_146014_j = 0;
	bool field_146015_k = false;
	int field_146012l = -1;
	int field_146013_m = 0;
	int field_146010_n = 0;
	ItemInstance* field_146011_o;
	std::string field_146008_p;
	
};

#endif