#include "Container.h"

Slot* Container::addSlotToContainer(Slot* slot) {
	slot->slotNumber = this->getContainerSize();
	this->inventorySlots.push_back(slot);
	this->inventoryItemStacks.push_back(static_cast<void*>(nullptr));
	return slot;
}