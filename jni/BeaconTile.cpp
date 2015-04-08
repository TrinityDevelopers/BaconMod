#include <BeaconTile.h>

BeaconTile::BeaconTile(int id, std::string const& desc) : Tile(id, "glass", &Material::glass) {
	this->setDescriptionId(desc);
	this->setLightEmission(0.1F);
	this->setCategory(2);
	this->setDestroyTime(3.0F);
	this->renderLayer = Tile::glass->renderLayer;
	Tile::tiles[id] = this;
	Tile::solid[id] = false;
}

int BeaconTile::getResourceCount(Random* random) {
	return 1;
}
