# SO_LONG

ok this is my first ReadMe im doing so don't expect that mush anyways let's get started.

First things first im using the Minilibix Library developed by 42 Network.

this how i was using that graphical interface, for the first part all i what i did is putting images in the screen
with any map it should be dynamic that means any map was put in the .ber file exemple : 
map.ber
fd.ber
should be good but it need to follow some rule.

## Rules of the map
- needs to be triangle or rectangle.
- needs to be surrounded by walls.
- have at least 1 exit.
- have at least 1 collectible.
- have at least 1 Player.

that's for the things it should the map have if it's not that means there is Misconfiguration in the map.

The map can be composed of only these 5 characters: Player, Exit, Collectible, Wall, Empty Space.

![alt text](https://github.com/Forstman1/so_long/blob/main/so_long_final/img_bonus/grass1.png)
![alt text](https://github.com/Forstman1/so_long/blob/main/so_long_final/img_bonus/pixil3.png)
![alt text](https://github.com/Forstman1/so_long/blob/main/so_long_final/img_bonus/enemy3.png)
![alt text](https://github.com/Forstman1/so_long/blob/main/so_long_final/img_bonus/door%20(1).png)


## How to Play 

it's easy just go to your terminal and the following command ``` Make ``` then ```Make execute``` then the game will be running !
- To Move up ```W```, To Move down ```S```, To Move right ```D```, To Move left ```A```, ```ECHAP``` to exit the Game
- You need to collect all key's to open the door and go through it and you should not touch the enemies if you did you gonna start over


![alt text](https://github.com/Forstman1/so_long/blob/main/so_long_final/img_bonus/game.png)

## how you can create your own so_long

this is the part where 42 students can pay attention the most.

First thing first u need to now how to use milibix library, it so important for you to know all the functions because so good to know them i
will drop some links here tha can really help you [Minilibix Library](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)

### The Functions That you gonna Need What are they for

1. ```mlx_init()``` : What is does is it key stone for all the other minilibix so with out it you can't use other function it's the connection between your terminal and correct graphical system and it return a void * which holds the location of our current MLX instance
2. ```mlx_new_window()``` : As it say in the name it's the function that create the window and it takes 4 arguments, First one of course VOID * that is returned by mlx_init() and second one is the width of the window and third one is the height of window and firth one of the name of the window 


