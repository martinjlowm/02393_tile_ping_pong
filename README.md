# Getting started

Use the presupplied project files for either Xcode or Visual Studio, and place them in the root folder.

Xcode will look like,

<pre>
    enigma3d.app
    enigma3d.xcodeproj
    framework/
        ...
</pre>

and Visual Studio will look like,

<pre>
    game_framework.sin
    irrlicht-1.8.1/
        ...
    framework/
        ...
</pre>

For visual studio, change your game_framework.sin and change the line,

<pre>
    Project("{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}") = "game_framework", "game_framework\game_framework.vcxproj", "{B8C1C195-DAFB-40A1-8F04-E4DEDDF1173A}"
</pre>

to use the `framework` folder instead of `game_framework`, like so

<pre>
    Project("{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}") = "game_framework", "framework\game_framework.vcxproj", "{B8C1C195-DAFB-40A1-8F04-E4DEDDF1173A}"
</pre>

