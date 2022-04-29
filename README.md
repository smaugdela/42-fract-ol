# 42-fract-ol
My first graphical project at 42! I must create a fractal displayer program.

# Mandatory Instructions
 - You must use the MiniLibX, the 42's library dedicated to graphical software.
 - Global variables are forbidden.
 - Your program must offer the Julia set and the Mandelbrot set.
 - The mouse wheel zooms in and out, almost infinitely (within the limits of the computer). This is the very principle of fractals.
 - You must be able to create different Julia sets by passing different parameters to the program.
 - A parameter is passed on the command line to define what type of fractal will be displayed in a window.
 - You must use at least have a few colors to show the depth of each fractal.
 - Pressing ESC must close the window and quit the program in a clean way.
 - Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.
 - The use of the images functions of the MiniLibX is mandatory.

See the subject located in misc/en.subject.pdf for more details.

# How to Use
Clone the repository in the location of your choice, go inside it, then compile using make bonus command:
```
cd 42-fract-ol
make bonus
```
You can then launch the program using as arguments the name of the fractal set you want to see, and a letter corresponding to the color.
```
./fractol_bonus Mandelbrot R
```
```
Color arguments:
W -> Black and White
S -> Greyscale
R -> Red-scale
G -> Green-scale
B -> Blue-scale
P -> Full color spectrum
L -> Lagoon-ish spectrum
F -> Flame-ish spectrum
```
You could also add 2 floats numbers as arguments if you use Julia fractal, as it is interactive (that means you choose the default value for computation when starting Julia).
```
./fractol_bonus Julia P -0.5 -0.1
```

Enjoy!

# Gallery
