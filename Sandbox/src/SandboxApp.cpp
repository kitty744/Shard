#include <Shard.h>

class Sandbox : public Shard::Application
{
public:
    Sandbox()
    {
    }

    ~Sandbox()
    {
    }
};

Shard::Application *Shard::CreateApplication()
{
    return new Sandbox();
}