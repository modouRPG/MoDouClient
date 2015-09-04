MoDouClient
===========

MoDouClient

依赖
========
    sudo apt-get install libsdl1.2-dev libsdl-image1.2-dev libsdl-mixer1.2-dev libsdl-ttf2.0-dev libzip-dev libtinyxml2-dev libguichan-dev
    tmx 地图文件解析库：
    https://github.com/andrewrk/tmxparser

编译
=======
    cd src
    aclocal
    autoheader
    autoconf
    automake --add-missing
    ./configure
    make

    
ChangeLog
=========
1. 初始化依赖的库，实现登录窗口。
1. 2015-09-04 support tmx map file. 

地图实现
========
1. 地图的主要信息保存在XMap类里。一个XMap表示一张较大的地图。
2. XMap中包含一个XMapLayer的列表。表示这张地图的各层。
3. 每个XMapLayer中包含一个Tiles的列表，为这层包含的32x32的图片方阵。
3. 初始化地图的时候，将XMap中的所有XMapLayer加载进来。
3. 更具用户的视野，将需要的部分显示到界面上。
5. 地图上的角色，在按照前后顺序排好队之后绘制就可以。

Global Args
===========
In main.h file. 
Use globals namespace.
Defined in main.cpp

地图文件格式
============
1. header width height tilewidth tileheight
2. layer info

