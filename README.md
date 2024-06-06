# R-TYPE Project 🛸👽

        
<p align="center"><br/><br/><img src="https://lh3.googleusercontent.com/x4Xo-UILE0fhEshwxc29WUlSZkJ5IQqP0WtbkL_x5TmG9BAXBZe8dBjj_dM8OdeZq8ZSUnDZ0YWrZClBdlajn6QLJLiLSiAtoIKWAg=w600"width="500"></p>

## What is R-Type Project ? 🤔

THE R-TYPE is a project that takes place during the third year of the EPITECH curriculum. It is an SHOT THEM type game 💥.
  Based on networked multi-gaming 🌐 (one 1️⃣ to four 4️⃣ players), it allows networked games with up to four simultaneous users 👤.

<p align="center"><br/><br/><img src="https://user-images.githubusercontent.com/72026933/201523882-2ae097ff-831c-4610-bbea-19adeed14f3c.png"width="200"></p>

## How the project is organized ? 🗂️

First, you will develop the core architecture of the game and deliver a working prototype, and in a second
time, you will expand several aspects the prototype toward new horizons. Then we'll use an Entity Component System (ECS) architecture. In this project, then by using our own engine we must implement a multi-thread server with a graphical client which must show our playable game. Client/server interactions are fundamental to the development of this project. Indeed, the client's role is to display all the information processed and received by the server.
  
## Which platform can handle our project ? 🎮🎮

Our R-Type project can easily work on Linux, MacOs and Linux. Our R-type is a *cross platform game* !
  
## What technologies we used for this project ? 👨🏾‍💻👩🏾‍💻
 
For this networking/graphical project we decided to use:
  - eNET 1.3.17 : for the network part,
  - SFML 2.5.1 : as the grathical library and then especially for the game (game, menu and other playable part)
  - C++ 20 : imposed by the project
  - Conan : for the installing dependencies</h4>
  
## Speaking of dependencies, which ones are necessary for the compilation and use of our project? ⛔

To use our project you must need: 
  - Conan
  - C++
  - Cmake compiler

## Then, how to install this dependencies ? 🔌

**Conan**

Make sure you have *pip* first. To install Conan using pip, you need Python>=3.6 distribution installed on your machine. After this verification go to your terminal/shell and tape :

      $ pip install conan

**C++**

- *On Linux*

To install C++ and g++ compiler, privileged access to your Ubuntu System as *root* or via *sudo* command is required. You have some ways to install it :
        
        $ sudo apt install g++

or 

        $ sudo apt install build-essential

 - *On Windows*
  
 To install C++ and g++ compiler on windows, first of all install MinGW. Then you must follow this tutorial [C++ on Windows](https://opensource.com/article/20/8/gnu-windows-mingw#:~:text=Install%20GCC%20on%20Windows&text=First%2C%20select%20mingw%2Dget%20from,application%20menu%20to%20launch%20it.&text=To%20install%20GCC%2C%20click%20the,of%20the%20mingw%2Dget%20window.)
 
**Cmake**

You can install cmake on Linux and windows by using this [tutorial](https://cmake.org/install/)

## How to compile our project ? 🔄

- *On linux*

Execute the build.sh script

      $ ./build.sh

Then two binary will be created: *r-type_client* and *r-type_server*

- *On Windows*

Launch our project with *Microsoft Visual Studio*
In the *developer shortcut powershell* type :

        $ make -C Game\Lib
        $ rm -rf build
        $ mkdir .\build\ && cd .\build\
        $ conan install .. --build=missing && cmake -DCMAKE_BUILD_TYPE=Debug ..
        $ cmake --build .
        $ mv bin\r-type_client ..
        $ mv bin\r-type_server ..
        
## USAGE 📚
 To make work our project type in your shell/powershell :
 
        $ r-type_server [port]
 
 Then in another one shell/powershell type:
 
        $ r-type_client [port] [IP]

## Norme used for GIT modification 👮🏾‍♀️
In order to be more professionnal we decide to use a norm for GIT modification, add, fix and remove.
- ADD: "First name Add: Name of the folder - File - Description of the addition".
- Fix: "First Name Fix: Folder Name - File - Description of Fix".
- Remove: "First name Remove: Name of the folder - File - Reason for removal".

## Which genius innovators are working on this project ? 👨🏾‍💻💭

- [X] Jordan AKOHA aka femi.akoha@epitech.eu
- [X] Freud LALEYE aka freud.laleye@epitech.eu
- [X] Guy HAZOUME aka guy.hazoume@epitech.eu
- [X] Héritier DAGA aka heritier.daga@epitech.eu
- [X] Marcel YOBO aka marcel.yobo@epitech.eu

# GOOD LUCK AND TO THE INFINITE AND BEYOND!
<p align="center"><br/><br/><img src="https://thumbs.gfycat.com/WastefulVeneratedBluebird-size_restricted.gif"width="500"></p>


<a href="https://img.shields.io/badge/MADE%20WITH-C++-blueviolet" alt="C++">
        <img src="https://img.shields.io/badge/MADE%20WITH-C++-blueviolet" /></a>
<a href="https://img.shields.io/badge/MADE%20WITH-CMAKE-red" alt="SFML">
        <img src="https://img.shields.io/badge/MADE%20WITH-CMAKE-red" /></a>        
<a href="https://img.shields.io/badge/MADE%20WITH-SFML-brightgreen" alt="Cmake">
        <img src="https://img.shields.io/badge/MADE%20WITH-SFML-brightgreen" /></a>
<a href="https://img.shields.io/badge/MADE%20WITH-CONAN-blueviolet" alt="Conan">
        <img src="https://img.shields.io/badge/MADE%20WITH-CONAN-blueviolet" /></a>
