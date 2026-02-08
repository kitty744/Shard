#pragma once

#include "Core.h"
#include "Window.h"
#include "../Events/Event.h"
#include "../Events/ApplicationEvent.h"
#include <memory>

namespace Shard
{

    class SHARD_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
        void OnEvent(Event &e);

        inline Window &GetWindow() { return *m_Window; }
        inline static Application &Get() { return *s_Instance; }

    private:
        bool OnWindowClose(WindowCloseEvent &e);

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        static Application *s_Instance;
    };

    // To be defined in CLIENT
    Application *CreateApplication();

}