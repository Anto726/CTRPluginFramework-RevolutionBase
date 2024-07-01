#include <base/entries.hpp>

#include <base/services/rainbow_service.hpp>

namespace base
{
    void entries::menu::rainbow_game(CTRPluginFramework::MenuEntry *entry)
    {
        g_rainbow_service->run();
    }
}