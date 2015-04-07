#ifndef BEACONTILE_H_
#define BEACONTILE_H_

#define BEACON_TILE_ID 199
#include <lw.h>

class BeaconTile : public Tile {
public:
	BeaconTile(int, std::string const&);
};

#endif