#include "Application.h"
#include "Log.h"

namespace Shard
{

    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        SHARD_CORE_INFO("Application running!");
        while (true)
        {
            // Game loop will go here
        }
    }

}