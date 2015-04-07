#include <BeaconTile.h>

BeaconTile::BeaconTile(int id, std::string const& desc) : Tile(id, "glass", &Material::glass) {
	this->setDescriptionId(desc);
	this->setLightEmission(0.1F);
	this->setCategory(3);
	this->setDestroyTime(3.0F);
	this->renderLayer = RENDERLAYER_ALPHATEST;
	Tile::tiles[id] = this;
	Tile::solid[id] = true;
}
