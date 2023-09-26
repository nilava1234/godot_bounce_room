How to run:

How to import the project:
If on Linux distro run the x86 file inside of godot/bin/.
After that open Godot; and scan for projects; you will find the project inside of godot/gdextension.../demo
Simply import and open the project called demo.
To run the tests press the play button in the top right corner. This should allow you to explore the environment using a floating
user-controlled camera.\

If on other Distros
Required:
1)pip
2)scons

Steps:
1) in /godot run the command
$: scons
this should list all available executable files it could make. Choose the right one for you.
2) run the command
$: scons platform=<the one you chose> -j<# of available threads you want to use>
3) Once that's done running do the steps above.
