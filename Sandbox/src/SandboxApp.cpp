#include <Shard.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class ExampleLayer : public Shard::Layer
{
public:
    ExampleLayer() : Layer("Example") {}

    void OnUpdate(Shard::Timestep ts) override
    {
        // Test GLM!
        glm::vec3 position(0.0f, 0.0f, 0.0f);
        glm::mat4 transform = glm::translate(glm::mat4(1.0f), position);

        SHARD_INFO("GLM works! Position: {0}, {1}, {2}",
                   position.x, position.y, position.z);
    }
};

class Sandbox : public Shard::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }
};

Shard::Application *Shard::CreateApplication()
{
    return new Sandbox();
}