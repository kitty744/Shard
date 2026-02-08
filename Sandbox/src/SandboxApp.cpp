#include <Shard.h>

class Sandbox : public Shard::Application
{
public:
    Sandbox()
    {
        SHARD_INFO("Sandbox created!");
    }

    ~Sandbox()
    {
    }
};

Shard::Application *Shard::CreateApplication()
{
    return new Sandbox();
}