# GameEngine
The Game Engine For study

Video tutorial from TheCherno GameEngine. 

Firstly, the important files related to the engine will be placed in the "GameEngine" directory. They are divided into two projects: "GameEngine" as the engine and "SandBox" as the client (the main startup project). Note that "GameEngine" is packaged as a DLL, so please ensure that the code related to "GameEngine" is placed in the "SandBox" folder. 

The "bin" folder is the output folder, and the "bin-int" folder contains the files generated during the compilation process (you can ignore these). If you encounter any errors related to DLLs, please copy the "GameEngine.dll" file from the "bin" folder to the "SandBox".

## Regarding Other Matters 

Firstly, the project uses the third-party library SPDLOG as the logging system. Then, please note that the compilation of SPD is in UTF-8 format. Therefore, please pay attention to the command line /UTF-8 in the properties of the GameEngine and Sandbox projects.