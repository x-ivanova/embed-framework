# embed-framework

C++ framework for Embedded systems. 

# Overview

Сервис для подсчета количества кликов по кнопке. Crow Web Server отдает HTML страницу с кнопкой и количеством кликов.  

WEB демо доступно по [ссылке](http://159.65.201.37:8080).

## Requirenments
 - C++ compiler with good C++11 support
 - CMake
 - [Crow](https://github.com/ipkn/crow) microframework for web.
 - boost library (`apt install libboost-all-dev`)

## Files
- **include/** - crow header files.
- **source/** - source files.
- **bin/** - binary file to run server.

## Web Interface description
- **source/index.html** - Main Page
- **source/sripts.js** - JavaScript AJAX requests
- **source/style.css** - CSS styles

## Web Server requests
- **/** - get index.html
- **/PATH/** - get path or file by PATH.
- **/get** - get number of clicks.
- **/make** - increment number of clicks.

## How to run binary in UBUNTU

1. Install Boots Library by putting in terminal - `sudo apt install libboost-all-dev`
2. `cd bin/`
3. `./main`
