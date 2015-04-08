#ifndef BEACONTILE_H_
#define BEACONTILE_H_

#define BEACON_TILE_ID 138
#include <lw.h>

class BeaconTile : public Tile {
public:
	BeaconTile(int, std::string const&);
	virtual int getResourceCount(Random*);
};

#endif