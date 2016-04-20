## Build status

| [Linux][lin-link] |
| :---------------: |
| ![lin-badge]      |

[lin-badge]: https://travis-ci.org/nfactorial/display_manager.svg?branch=master "Travis build status"
[lin-link]:  https://travis-ci.org/nfactorial/display_manager "Travis build status"

Display Manager
===============
This library provides the core wrapper around the rendering system. The display manager
allows creation and management of display windows within which rendering may be performed.
The API is render API agnostic, allowing the high level API to remain consistent whether
OpenGL, DirectX or another rendering API is in use.

The display manager provides an API for creating a display port. A display port object represents a surface
that a cameras view will be rendered to.

Display Pipeline
================
A render pipeline represented by a display port consists of a number of render layers. Render layers allow the
pipeline to be split into a number of separate passes.

When a material is defined, it is assigned a render layer.

When a piece of geometry is supplied for rendering, the display pipeline looks up its render layer and stores
the draw request into the appropriate layer for the display port. Once all draw requests have been submitted
the display pipeline then visits each render layer in turn, and executes the queued draw operations.
