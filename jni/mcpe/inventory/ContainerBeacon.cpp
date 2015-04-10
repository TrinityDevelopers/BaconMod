#include "ContainerBeacon.h"

bool ContainerBeacon::BeaconSlot::isItemValid(ItemInstance* instance)
{
	return instance == nullptr ? false : instance->item == Item::items[388] || instance->item == Item::items[264] || instance->item == Item::items[266] || instance->item == Item::items[265];
}

int ContainerBeacon::BeaconSlot::getSlotStackLimit()
{
	return 1;
}

ContainerBeacon::ContainerBeacon(FillingContainer* inventory, TileEntityBeacon* tileEntityBeacon) {
	this->theBeacon = tileEntityBeacon;
	this->addSlotToContainer(this->beaconSlot = new ContainerBeacon::BeaconSlot(tileEntityBeacon, 0, 136, 110));
	char var3 = 36;
	short var4 = 137;

	for (int var5 = 0; var5 < 3; ++var5)
	{
		for (int var6 = 0; var6 < 9; ++var6)
		{
			this->addSlotToContainer(new Slot(inventory, var6 + var5 * 9 + 9, var3 + var6 * 18, var4 + var5 * 18));
		}
	}

	for (int var5 = 0; var5 < 9; ++var5)
	{
		this->addSlotToContainer(new Slot(inventory, var5, var3 + var5 * 18, 58 + var4));
	}

	this->field1 = tileEntityBeacon->func_145998l();
	this->field2 = tileEntityBeacon->func_146007_j();
	this->field3 = tileEntityBeacon->func_146006_k();
}

void ContainerBeacon::updateProgressBar(int i1, int i2)
{
	if (i1 == 0)
	{
		this->theBeacon->func_146005_c(i2);
	}
	if (i1 == 1)
	{
		this->theBeacon->func_146001_d(i2);
	}
	if (i1 == 2)
	{
		this->theBeacon->func_146004_e(i2);
	}
}

TileEntityBeacon* ContainerBeacon::func_148327_e()
{
	return this->theBeacon;
}

bool ContainerBeacon::canInteractWith(Player* player)
{
		return this->theBeacon->isUseableByPlayer(player);
}

