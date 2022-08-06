# so_long

## Introduction
In this project, we'll code a simple 2D game to get familiar with the mlx library and UI in general.

### Game Rules
The game we choose must follow a set of rules. The executable ``so_long`` will receive a map as the only argument, and this map will have a ``.ber`` filetype.

## How it Works
For the graphics part of the project we used a library called ``minilibx``. It's fairly basic and somewhat limited, but was still fun to use in the project.

<img width="1727" alt="Screen Shot 2022-08-06 at 1 36 51 PM" src="https://user-images.githubusercontent.com/89024276/183259855-5cae2e81-6cda-4cbc-9fbd-b2a7356c46a2.png">


### Installing the MLX library

* ``Linux``

If you're not using a MacOS computer from 42, you'll need to install the libraries manually. Please refer to the [official github](https://github.com/42Paris/minilibx-linux) for more details. To install it, do the following (requires root access):

```shell
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux/
make
sudo cp mlx.h /usr/include
sudo cp libmlx.a /usr/lib
```

* ``MacOS``

To install the library, you will need to first install a package manager like homebrew (check [here](https://brew.sh/)) to then install the X11 package with ``brew install Xquartz``. After that you must extract the minilibx file called ``minilibx_opengl.tgz``. Then install it to your system with the following commands (requires sudo as well):

```shell
cd minilibx_opengl
make
sudo cp mlx.h /usr/local/include
sudo cp libmlx.a /usr/local/lib
sudo reboot
```
Note: A reboot is necessary to ensure that the ``Xquartz`` is working properly. You can test if it is by running a test example with the command ``xeyes``.

### Installing the manuals

If you want quick access to the mlx manuals, it is recommended that you copy the files from the ``man`` folder in [minilibx-linux](https://github.com/42Paris/minilibx-linux) to your system manuals:

* ``Linux``
```shell
sudo cp man/man3/* /usr/share/man/man3/
```
Note: Depending on your Linux configuration, to get the manuals working (e.g. ``man mlx``) you will need to individually gzip all the manual files you just copied, e.g. ``sudo gzip /usr/share/man/man3/mlx.3``.

* ``MacOS``
```shell
sudo cp man/man3/* /usr/X11/share/man/man3
```
