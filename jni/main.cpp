#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>
#include <string>
#include <map>
#include <memory>
#include <lw.h>
#include <BeaconTile.h>
#include <netherStar.h>
bool reg=false;
bool itemsAdded=false;

static void (*Minecraft_selectLevel_real)(Level*, Minecraft*, std::string const&, std::string const&, LevelSettings const&);
static void(*Gui_render_real)(Gui*, float, bool, int, int);
static void(*Tile_initTiles_real)();
static void(*CreativeInventoryScreen_populateItem_real)(Item*, int, int);
std::map <std::string, std::string>* I18n_strings;

static void addShapedRecipe(int id, int count, int damage, std::string line1, std::string line2, std::string line3, int ingCount, char charArray[], int idArray[]) {
	std::vector<std::string> shape={ line1, line2, line3};
	std::vector<Recipes::Type> ingredients;
	for(int n=0; n<ingCount; n++) {
		Recipes::Type recipeType;
		if(idArray[n]<=256) {
		    recipeType.tile=Tile::tiles[idArray[n]];
		    recipeType.item=NULL;
		}
		else {
			recipeType.tile=NULL;
			recipeType.item=Item::items[idArray[n]];
		}
		recipeType.c=charArray[n];
		ingredients.push_back(recipeType);
	}
	Recipes::getInstance()->addShapedRecipe(ItemInstance(id, count, damage), shape, ingredients);
}

static void Minecraft_selectLevel_hook(Level* level, Minecraft* mc, std::string const& str1, std::string const& str2, LevelSettings const& settings) {
	NetherStar* netherStar = new NetherStar(NETHER_STAR_ID - 0x100, "Nether Star", 64);
	Item::items[NETHER_STAR_ID] = netherStar;
	if(!reg) {
		reg=true;
		(*I18n_strings)["tile.Beacon Tile.name"]="Beacon";
		(*I18n_strings)["item.Nether Star.name"]="Nether Star";
		char btChars[]={'g', 's', 'o'};
	    int btIngs[]={20, NETHER_STAR_ID, 49};
		addShapedRecipe(BEACON_TILE_ID, 1, 0, "ggg", "gsg", "ooo", 3, btChars, btIngs);
	}
	Minecraft_selectLevel_real(level, mc, str1, str2, settings);
}

static void Tile_initTiles_hook() {
	Tile_initTiles_real();
	BeaconTile* beaconTile = new BeaconTile(BEACON_TILE_ID, "Beacon Tile");
	TileItem* beaconTileItem=new TileItem(BEACON_TILE_ID-0x100);
}

static void Gui_render_hook(Gui* gui, float f1, bool b1, int i1, int i2) {
	Gui_render_real(gui, f1, b1, i1, i2);
}

static void CreativeInventoryScreen_populateItem_hook(Item* item, int count, int damage) {
	if(!itemsAdded) {
		CreativeInventoryScreen_populateItem_real(Item::items[BEACON_TILE_ID], 1, 0);
		CreativeInventoryScreen_populateItem_real(Item::items[NETHER_STAR_ID], 1, 0);
		itemsAdded=true;
	}
	CreativeInventoryScreen_populateItem_real(item, count, damage);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	void* CreativeInventoryScreen_populateItem=dlsym(RTLD_DEFAULT, "_ZN23CreativeInventoryScreen12populateItemEP4Itemii");
	I18n_strings = (std::map <std::string, std::string>*) dlsym(RTLD_DEFAULT, "_ZN4I18n8_stringsE");
	MSHookFunction((void*) &Gui::render, (void*) &Gui_render_hook, (void**) &Gui_render_real);
    MSHookFunction((void*) &Minecraft::selectLevel, (void*) &Minecraft_selectLevel_hook, (void**) &Minecraft_selectLevel_real);
    MSHookFunction((void*) &Tile::initTiles, (void*) &Tile_initTiles_hook, (void**) &Tile_initTiles_real);
	MSHookFunction(CreativeInventoryScreen_populateItem, (void*) &CreativeInventoryScreen_populateItem_hook, (void**) &CreativeInventoryScreen_populateItem_real);
    return JNI_VERSION_1_2;
}