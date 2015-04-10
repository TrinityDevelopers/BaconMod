#include "Slot.h"

Slot::Slot(FillingContainer* inventory, int index, int xPos, int yPos) {
	this->inventory = inventory;
	this->slotIndex = index;
	this->xDisplayPosition = xPos;
	this->yDisplayPosition = yPos;
}

bool Slot::isItemValid(ItemInstance* instance) {
	return true;
}

int Slot::getSlotStackLimit() {
	return this->inventory->getMaxStackSize;
}