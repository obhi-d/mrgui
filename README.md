# MrUI

MrUI is a retained mode GUI system, that renders vertex buffers (only). 

## Design Principles and Goals

The obvious thing to state is this project is inspired from imgui, which is a fantastic library.

### Retained Mode

 - Renders vertex buffers that can be directly uploaded to GPU and kept as is until modified
 - Get notification when rendering needs to be refreshed by IO
 - MrUI renders non-indexed triangle arrays.
 - OS independent, MrUI only cares about inputs through IO for interactivity

### Event System

  - Lightweight event system that fires notification based on IO updates
  - IO can also be queried for changes, if no event callbacks exists

### Panels

  - Panels are region in conceptual space you are drawing to
  - Panels have a world coordinate placement (if they are for a specific OS window, it can just be the window position)
  - Panel also can be given a max size it is allowed to draw to (data outside is clipped)
  - Every coordinate inside a panel is relative to the panel
  - You can create drawing data for a panel and render it complete on a OS window
  - Panels can exist inside other Panels
  - If a Panel is allowed to overflow the content region, it will send notification 
    - This it to allow you to either clip the data or draw the panel in a seperate OS window for example
  - Panels can be made moveable, in which case they will send notification to adjust their world coordinate.

### Flow

  - UI element placement follows directional flow and alignment rules
  - You can declare elements using horizontal flow, or vertical flow
  - You can optionally align elements on column boundaries or Panel boundaries
    - Each element will occupy a single column by default 

### Declarative

  - Using neoscript, declare panels 
  - Register code to listen to events from said panels
  - Optionally register code to provide data for controls within the panel 

### IO

  - IO will rely on already refined user inputs
    - Key sequences (@todo IME)
    - Mouse inputs
    - Gamepad inputs
  - IO will determine if rendering needs to be updated
  

### Behaviour 

  - Panel behaviour system can change panel transition rendering (hide/show/maximize/minimize) 
    - This is to allow animation for example
  - Allow pre-render modification/transformation during transition
    - Transition is defined as a timeframe when UI elements are unaffected by IO
    
### Lightweight

  - Static library (eventually will migarete to C++ modules)
  - **16 bit** mode by default to render coordinates and uv in half precision
  - Color is always sampled from textures and not encoded in vertices for better vertex packing

### Clean and Maintainable

  - Consistent coding style 
    - Follow std c++ naming conventions, use clang-format)
  - No straddling between language boundary
    - Stick to C++ using its latest features 

