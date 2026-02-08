#pragma once

#ifdef SHARD_PLATFORM_LINUX

extern Shard::Application *Shard::CreateApplication();

int main(int argc, char **argv)
{
    Shard::Log::Init();
    SHARD_CORE_WARN("Initialized Log!");

    auto app = Shard::CreateApplication();
    app->Run();
    delete app;

    return 0;
}

#endif