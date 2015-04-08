#include <lw.h>
#include <netherStar.h>

NetherStar::NetherStar(int id, std::string const& name, int maxStack) : Item(id) {
	this->setIcon("nether_star", 0);
	this->setDescriptionId(name);
	this->setMaxStackSize(maxStack);
	this->setCategory(3);
}

