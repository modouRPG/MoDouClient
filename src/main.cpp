#include <SDL.h>
#include <iostream>
#include <guichan.hpp>
#include "main.h"
#include "sdlhelp.hpp"
#include "helloworld.hpp"

gcn::Gui *(globals::gui) = new gcn::Gui();
modou::TmxMap *(globals::map) = NULL;
modou::XLocalPlayer *(globals::localPlayer) = NULL;
modou::LoginConn *(globals::loginConn) = new modou::LoginConn("127.0.0.1", 2048);
modou::Game *(globals::gGame) = NULL;
uint64_t globals::tick=0;

int main(int argc, char *argv[])
{
    try
    {
        sdl::init();
        modou::init();
        sdl::run();
        modou::halt();
        sdl::halt();
    }
    // Catch all Guichan exceptions.
    catch (gcn::Exception e)
    {
        std::cerr << e.getMessage() << std::endl;
        return 1;
    }
    // Catch all Std exceptions.
    catch (std::exception e)
    {
        std::cerr << "Std exception: " << e.what() << std::endl;
        return 1;
    }
    // Catch all unknown exceptions.
    catch (...)
    {
        std::cerr << "Unknown exception" << std::endl;
        return 1;
    }
    return 0;
}
