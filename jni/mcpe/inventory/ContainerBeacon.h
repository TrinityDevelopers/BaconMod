#ifndef CONTAINERBEACON_H_
#define CONTAINERBEACON_H_

#include "Container.h"
#include "FillingContainer.h"
#include "../tileentity/TileEntityBeacon.h"
#include "Slot.h"
#include <lw.h>

class ContainerBeacon : public Container {
public:
	class BeaconSlot : public Slot{
	public:
		BeaconSlot(FillingContainer* inv, int index, int yPos, int xPos) : Slot(inv, index, yPos, xPos);
		virtual bool isItemValid(ItemInstance*);
		virtual int getSlotStackLimit();
	};
private:
	TileEntityBeacon* theBeacon;
	BeaconSlot *const beaconSlot;
	int field1;
	int field2;
	int field3;
public:
	ContainerBeacon(FillingContainer*, TileEntityBeacon*);
	virtual void updateProgressBar(int, int);
	virtual TileEntityBeacon* func_148327_e();
	virtual bool canInteractWith(Player*);
};

#endif