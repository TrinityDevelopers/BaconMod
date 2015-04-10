#ifndef SLOT_H_
#define SLOT_H_

#include <lw.h>
#include "FillingContainer.h"
#include "Container.h"

class Slot {
private:
	/* The index of the slot in the inventory. */
	const int slotIndex;
public:
	/* The inventory we want to extract a slot from. */
	FillingContainer* const inventory;

	/* the id of the slot(also the index in the inventory arraylist) */
	int slotNumber = 0;

	/* display position of the inventory slot on the screen x axis */
	int xDisplayPosition = 0;

	/* display position of the inventory slot on the screen y axis */
	int yDisplayPosition = 0;
public:
	Slot(FillingContainer*, int, int, int);
	virtual bool isItemValid(ItemInstance*);
	virtual int getSlotStackLimit();
};

#endif