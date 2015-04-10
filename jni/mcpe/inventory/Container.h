#pragma once
#include <string>
#include <vector>
#include <map>
#include <memory>
#include "Slot.h"

class ItemInstance;
class Player;

class Container {
public:
	static const int LARGE_MAX_STACK_SIZE = 64;
	Container(int);
	virtual ~Container();
	virtual ItemInstance *getItem(int);
	virtual void setItem(int, ItemInstance *);
	virtual ItemInstance removeItem(int, int);
	virtual std::string getName();
	virtual int getContainerSize();
	virtual int getMaxStackSize();
	virtual bool stillValid(Player *);
	virtual void startOpen();
	virtual void stopOpen();
	virtual std::vector<ItemInstance, std::__1::allocator<ItemInstance> > getSlotCopies();
	int containerId;
	int containerType;
public:
	std::vector<ItemInstance*> inventoryItemStacks;
	std::vector<Slot*> inventorySlots;
protected:
	virtual Slot* addSlotToContainer(Slot*);
};
