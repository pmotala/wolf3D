# Wolf3d - @WeThinkCode_
Wolf3D is a neigh perfect recreation of the Classic Wolfenstein3D FPS game.

### What is FDF?
[Wolf3D][1] is an individual project at [WeThinkCode_][2] that requires us to recreate the popular game, that had a maze like map, as well as enemies and so forth.it uses some of the funtions found in the [Libft][3] library. It also uses a graphics library, [Minilibx][4] in this case.

### What is in the Project?

Take a look in the [Project instructions][1]. The project has 2 sections:

1.  **Main Programme:** A basic programme that reads the given map, and displays a maze with different colored walls, and allow movement.
2.  **Bonus Additions:** Adding more features to the game, to bring it closer to the original.

### The Mechanics behind it all?

The goal is to create a program called wolf3D from the source files, and use that to render out the maps given.

To create that file, after downloading/cloning this project, **cd** into the project, copy all the files from the sub folders to the root directory and finally, call make:

	git clone https://github.com/pmotala/wolf3D
	cd wolf3D
	make

You should see a *wolf3D* file and some object files (.o).


Now to clean up (removing the .o files and the .c files from the root), call the function:
	make clean

### How do I use the programme?

You have to tell the file where your map file resides, for example:

`wolf3D maps/map1`

`wolf3D` is the name of programme you've compiled. 
`maps/map1` is the directory to your map file.

you can find map files here: [Maps][5].

Enjoy.

[1]: https://github.com/pmotala/fdf/blob/master/document/wolf3d.en.pdf "Wolf3D PDF"
[2]: https://www.wethinkcode.co.za "WeThinkCode_"
[3]: https://github.com/pmotala/libft "Libft"
[4]: https://github.com/dannywillems/minilibx "Minilibx"
[5]: https://github.com/pmotala/fdf/blob/master/maps/