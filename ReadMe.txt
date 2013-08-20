Notes
--------------------------------------------

Plan of Action
--------------------------------------------
1. Ladda bakgrundsbild
2. Animera bakgrundsbild
3. Ladda spelare
4. Styr och animera spelare
5. Skjut med spelare
6. Ladda fiende
7. Animera fiende
8. Skjutande fiende
9. Collision detect mellan skott och player/fiende
10. Poängräkning
11. Musik och skjutljud
12. Meny (new game)
13. Flera skepp
14. Splash screen
15. STÄDA UPP MINNET!
	static bitmaps i ship
	vector med strings istället för char* [] för filnamnen
	ta bort kommenterad kod

Buggar
	Ljuden osynkade
	Alien startar alltid på samma ställe?
	Skjuter två skott ibland
	Vid new game så fortsätter spelet animera och skeppen hamnar för långt ner när de sprängs
	Går ej stänga på kryss
	



========================================================================
    WIN32 APPLICATION : SpaceInvaders Project Overview
========================================================================

AppWizard has created this SpaceInvaders application for you.

This file contains a summary of what you will find in each of the files that
make up your SpaceInvaders application.


SpaceInvaders.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

SpaceInvaders.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

SpaceInvaders.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
AppWizard has created the following resources:

SpaceInvaders.rc
    This is a listing of all of the Microsoft Windows resources that the
    program uses.  It includes the icons, bitmaps, and cursors that are stored
    in the RES subdirectory.  This file can be directly edited in Microsoft
    Visual C++.

Resource.h
    This is the standard header file, which defines new resource IDs.
    Microsoft Visual C++ reads and updates this file.

SpaceInvaders.ico
    This is an icon file, which is used as the application's icon (32x32).
    This icon is included by the main resource file SpaceInvaders.rc.

small.ico
    This is an icon file, which contains a smaller version (16x16)
    of the application's icon. This icon is included by the main resource
    file SpaceInvaders.rc.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named SpaceInvaders.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
