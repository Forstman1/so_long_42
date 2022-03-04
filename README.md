# `SO_LONG` Project Description

_**Disclaimer:** OK, This is my first `README`, so don't expect that mush. Anyways, let's get started._

First things first, i'm using the Minilibix Library developed by 42 Network.

It's what I used to create the Graphical Interface, for the first part, all I did was putting images in the screen.
Note that dynamic, i.e. it should work with any VALID map that ends with the `.ber` file extension, e.g.: 

```text
map.ber
fd.ber
```
should be good but it need to follow some rule.

## Rules of the map

Needs to:
- Be triangle or rectangle.
- Be surrounded by walls.
- Have at least 1 exit.
- Have at least 1 collectible.
 Have at least 1 Player.

That's basically all ther is for the essentials, if any of these rules are Invalid, it means that there's Misconfiguration in the map.

The map can be composed of only these 5 characters:
1. Player
2. Exit
3. Collectible 
4. Wall
5. Empty Space

![alt text](https://github.com/Forstman1/so_long/blob/main/so_long_final/img_bonus/grass1.png)
![alt text](https://github.com/Forstman1/so_long/blob/main/so_long_final/img_bonus/pixil3.png)
![alt text](https://github.com/Forstman1/so_long/blob/main/so_long_final/img_bonus/enemy3.png)
![alt text](https://github.com/Forstman1/so_long/blob/main/so_long_final/img_bonus/door%20(1).png)


## How to Play 

It's actually pretty easy, just go to your terminal and type in the following command:

```bash
$ make
```

then :

```bash
$ make execute
```
and the game should be up and running !

### Game Legend:
- `W`: Move up
- `S`: Move down
- `D`: Move to the right
- `A`: Move to the left
- `Esc`: Exit the Game
 
You need to collect all the keys _(cherries in our case)_ to open the door and go through it, and you should'nt touch any of the enemies, if you do, you're gonna start over

![alt text](https://github.com/Forstman1/so_long/blob/main/so_long_final/img_bonus/game.png)

## How you can create your own so_long

This is the part where 42 students can pay attention the most.

First thing first u need to now how to use milibix library, it so important for you to know all the functions because they can be very useful.
Here's some links that can really help you :
- [Minilibix Library](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)

### The Functions you're gonna need & What are they for - 101

1. `mlx_init()` : It's basically the initialization of the connection between your terminal and the correct graphical system. It return a `void *` which holds the location of our current MLX instance. Tt is the Key Stone for all the other _comming_ minilibix functions, so without it we can't use them. 
2. `mlx_new_window()` : As it says in its name, It's the function that create the window and it takes 4 arguments, First one is of course the `void *` returned by `mlx_init()`, the 2nd one is the width of the window, the 3rd one is the height of window, and the 4th one of the name _aka Title_ of the window. 


