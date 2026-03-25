# OrangeEngine

> A hobby game engine built from scratch using Vulkan.

## About

OrangeEngine is a bare-metal game engine written in C++. This project is a work in progress — currently following the [Vulkan Tutorial](https://vulkan-tutorial.com/) to get the graphics pipeline up and running.

## Current Features

- Vulkan instance initialization and device setup
- Vertex and fragment shader compilation via `glslc`
- Basic render pipeline following the Vulkan Tutorial

## Getting Started

### Prerequisites

- GCC, `glslc` (Vulkan SDK)
- GLFW, Vulkan, GLM
- Make

### Building

```bash
git clone https://github.com/SirOrangePeel/OrangeEngine.git
cd OrangeEngine
./compile.sh   # Compile shaders
make           # Build the engine
```

### Running

```bash
make test
# or manually:
./VulkanTest
```

## Project Structure

```
OrangeEngine/
├── shaders/
│   ├── shader.frag             # Fragment shader (GLSL)
│   └── shader.vert             # Vertex shader (GLSL)
├── src/
│   └── main.cpp                # Engine entry point
├── .gitignore
├── compile.sh                  # Shader compilation script
└── Makefile
```

## Roadmap

### Phase 1 — Vulkan Fundamentals
- [x] Instance, device & queue setup
- [x] Window surface & swap chain
- [x] Image views & render pass
- [x] Graphics pipeline & shader stages
- [x] Framebuffers & command buffers
- [x] Rendering & presentation

### Phase 2 — Geometry & Buffers
- [x] Vertex buffers
- [x] Index buffers
- [x] Uniform buffers & descriptor sets
- [ ] Texture mapping & samplers

### Phase 3 — 3D Rendering
- [ ] Depth buffering
- [ ] Loading 3D models (OBJ/glTF)
- [ ] Mipmapping
- [ ] Multisampling (MSAA)

### Phase 4 — Engine Architecture
- [ ] Scene graph
- [ ] Entity-Component System (ECS)
- [ ] Asset manager
- [ ] Camera & input system

### Phase 5 — Advanced Rendering
- [ ] Deferred rendering
- [ ] Shadow mapping
- [ ] Post-processing effects
- [ ] Physically Based Rendering (PBR)

### Phase 6 — Polish & Beyond
- [ ] Audio system
- [ ] Scripting layer
- [ ] Editor / tooling

## Resources & Inspiration

- [Vulkan Tutorial](https://vulkan-tutorial.com/)
- [Vulkan Specification](https://registry.khronos.org/vulkan/specs/latest/html/)
- [GLFW Documentation](https://www.glfw.org/docs/latest/)
- [Vulkan Guide](https://vkguide.dev/)

## License

[MIT](LICENSE)