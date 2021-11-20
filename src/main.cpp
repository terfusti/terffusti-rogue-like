
#include <SDL.h>
#include <libtcod.h>

#include <cstdlib>

int main(int argc, char** argv)
{
    auto params = TCOD_ContextParams{};
    params.tcod_version = TCOD_COMPILEDVERSION;
    params.argc = argc;
    params.argv = argv;
    params.vsync = 1;
    params.sdl_window_flags = SDL_WINDOW_RESIZABLE;
    params.window_title = "Terfusti Rogue Like";

    auto console = tcod::Console{ 80, 85 };
    params.console = console.get();

    auto context = tcod::new_context(params);

    while (true)
    {
        
        console.clear();
        tcod::print(console, { 0, 0 }, "Thor says hello!", TCOD_red, std::nullopt);
        context->present(console);

        SDL_Event event{};
        SDL_WaitEvent(nullptr);
        while (SDL_PollEvent)
        {
            switch (event.type)
            {
            case SDL_QUIT:
                std::exit(EXIT_SUCCESS);
                break;
            
            default:
                break;
            }
        }
        
    }
    
    return 0;
}