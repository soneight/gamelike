## SOURCE
> Project Source Code Files

## Engine (Architecture in progress, TODO: move into engine subfolder later)
> OpenGL from 1.1 to 4.6 of none(00), compatibility(CB) and core(CE)

Launcher should run on OpenGL 1.1

Each game should be assign to one of OpenGL version: 1.5(00), 2.1(00), 3.3(CB), 3.3(CE), 4.3(CB), 4.3(CE), 4.6(CB), 4.6(CE)

GLFW for window creating and event handling

### SEA: Data Basic Blocks
> Scene Emote Actor scheme

- `Scene`: _Object Oriented Design because of flexibility and no pressure on performance_
- `Emote`: _Scripting, the heart of `modding` and quick game development iteration without C++ rebuilds using Lua language_
- `Actor`: _Data Oriented because of performance in some ECS implementation with best fit for current engine architecture_

### THREADS: Code Concurrency
> special systems that each should be created on separate thread

- `Action`: _main thread window creation and event handling (maybe also scripting and gui, etc)_
- `Direct`: _planner or schedular, data translator between threads below:_
  - `Visual`: _drawing and rendering related animations_
  - `Melody`: _audio processing_
  - `Motion`: _movement and physic related animations_
  - `Spirit`: _artificial intelligence_
  - `Stream`: _file processing, hardware data flow_
  - `Server`: _networking (even offline games should work through localhost interaction)_

### NIL: Behavior Events
> Notify Ignore Listen scheme

- `Notify`: _inform all subscribers that event happened_
- `Ignore`: _default state or unsubscribe_
- `Listen`: _subscribing for event_

###### Anything other than source code SHOULD avoid this folder
