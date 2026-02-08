# Shard Engine

A modern, lightweight game engine built in C++ for Linux, inspired by Hazel Engine.

## Building

### Prerequisites

**Linux (Ubuntu/Debian):**

```bash
sudo apt update
sudo apt install build-essential git cmake
sudo apt install libglfw3-dev libgl1-mesa-dev libglu1-mesa-dev
sudo apt install libspdlog-dev libfmt-dev
```

**Premake5:**

```bash
wget https://github.com/premake/premake-core/releases/download/v5.0.0-beta2/premake-5.0.0-beta2-linux.tar.gz
tar -xzf premake-5.0.0-beta2-linux.tar.gz
sudo mv premake5 /usr/local/bin/
```

### Build Instructions

```bash
# Clone the repository
git clone https://github.com/kitty744/Shard
cd Shard

# Generate project files
premake5 gmake2

# Build
make

# Run the Sandbox demo
./bin/Debug-linux-x86_64/Sandbox/Sandbox
```

### Build Configurations

- **Debug** - Full debug symbols, no optimization
- **Release** - Optimized with debug symbols
- **Dist** - Fully optimized distribution build

To build a specific configuration:

```bash
make config=release
```

## Usage

Create a new application by inheriting from `Shard::Application`:

```cpp
#include <Shard.h>

class MyApp : public Shard::Application
{
public:
    MyApp()
    {
        SHARD_INFO("MyApp started!");
    }

    ~MyApp()
    {
    }
};

Shard::Application* Shard::CreateApplication()
{
    return new MyApp();
}
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Credits

See [CREDITS.md](CREDITS.md) for a list of contributors and acknowledgments.

## Inspiration

This engine is inspired by [Hazel Engine](https://github.com/TheCherno/Hazel) by TheCherno. Check out his amazing [Game Engine series](https://www.youtube.com/playlist?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT) on YouTube!

## Contact

Project Link: [https://github.com/kitty744/Shard](https://github.com/kitty744/Shard)
