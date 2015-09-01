#include "map/XMapReader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include "main.h"

namespace modou
{
    XMap* XMapReader::readMap(std::string file_path)
    {
        struct MapHeader mHeader = {.width = 32, .height=24, .tileWidth=32, .tileHeight=32};
        char line[1024] = {0};
        char rpath[1024] = {0};

        XMap *map = new XMap(mHeader.width, mHeader.height, mHeader.tileWidth, mHeader.tileHeight);
        
        XMapLayer *bg= new XMapLayer(0, 0, mHeader.width, mHeader.height, false, 0);

        FILE *file = fopen(file_path.c_str(), "r+");
        char *sub = NULL, *tmp = NULL;
        char *a;
        int px, py;
        while(fgets(line, 1024, file)!= NULL) {
            memset(rpath, 0, 1024);
            strncat(rpath, "./data/img/", 1023);
            if (line[0] == '#') {
                continue;
            }
            sub = strtok(line, " ");
            if (sub == NULL) {
                printf("line error.%s\n", line);
                continue;
            }
            px = atoi(sub);
            sub = strtok(NULL, " ");
            py = atoi(sub);
            sub = strtok(NULL, " ");
            tmp = strdup(sub);
            if (tmp[strlen(tmp)-1] == '\n') {
                tmp[strlen(tmp)-1] = '\0';
            }
            strncat(rpath, tmp, 1023);
            bg->setTile(px/32, py/32, gcn::Image::load(rpath, true));
        }
        fclose(file);
        map->addLayer(bg);
        XMapLayer *player = new XMapLayer(0, 0, mapTileSize, mapTileSize, true, 0);
        //player->setTile(640/32, 318/32, gcn::Image::load("./data/img/aa2248.png", true));
        //player->setTile(158/32, 358/32, gcn::Image::load("./data/img/aa2202.png", true));
        //player->setTile(16, 12, gcn::Image::load("./data/img/aa0638.png", true));

        map->addLayer(player);
        return map;
    }
}
