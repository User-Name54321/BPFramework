# BPFramework
Framework built on SDL which is designed to provide easy access to rendering, input, and additional logic for developers looking for a decently lightweight resource which still offers basic tools.

Right now, the complete systems are:
* Rendering (Render.h)
* Window (Window.h)
* Component (Components.h + Object.h)
But more will come very soon!

## Usage
### Setup
First, you'll need to link BPF.lib, as well as sdl3.dll and sdl3_image.dll. I recommend researching this online via a Google search if you don't already know how ("*your build system* how link library"). You will also need to include at least the main header which is "Basic Program Framework.h," but there are a few more small features which aren't fully included in there in other headers.

### Library Usage
For sample of usage see test.cpp

Basically, you first need to create an Engine object which acts as a container for all systems created by the library, which you then call "init()" on. Calling "init()" creates and initializes all subsystems, which is probably a bad idea but eh whats the worst that can happen? 

After that, you can call a series of functions like "createTexture()" - which takes a path to a png/jpeg file and a name (in this example I chose "1" which was an awful choice) and loads a pointer to the SDL texture into a vector. Likewise, "createSprite()" creates a sprite with an inputted id and adds it to a container. "setTextureSprite()" takes an inputted id and a texture name, and then does some searching and linking behind the scenes to associate them with each other.

I then created a "PositionData" object, which most importantly contains 4 values which correspond to the x and y of the top left corner of the object, as well as its height and width out from that. "updatePos()" then pulls that data into a data structure in the sprite with that id.

The main game loop is contained in the while loop with the "run()" function, which does some polling and handles draw commands in the back. Every loop, "submitSprite()" must be called with an id in order to add it to the list of sprites to be drawn.

After you've finished your main execution you can call "quit()", which is implemented poorly right now but it works.

That's pretty much it; there are a few more features here and there, but they probably should see a decent bit more refinement. I also encourage you to dig into the headers to see what functions are available. Though, they aren't labelled very clearly. Sorry about that (maybe .

Thanks for looking at my project! Come again next time also!

The demo has a small 32 pixel square which renders in the top left.

<img width="1282" height="752" alt="demo" src="https://github.com/user-attachments/assets/6f206d83-ba16-435f-a901-f953c02835c7" />

### Quick Start/TLDR:
* create BPF::Engine object
* engine.init()
* while loop containing engine.run()
* engine.quit()



Made with the Simple DirectMedia Layer, SDL Image, Zlib, libpng, and libjpeg-turbo!

