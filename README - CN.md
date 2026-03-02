# GameEngine
此项目是用于学习的游戏引擎.

来自 TheCherno GameEngine 的视频教程。

首先关于引擎的重要文件会放在GameEngine，分为两个项目GameEngine做为引擎，SandBox做为客户端(主要启动项目)，注意GameEngine是作为DLL打包，所以涉及到GameEngine的代码请确保DLL在SandBox文件夹。

bin文件夹是输出文件夹，bin-int文件夹是编译过程中的文件(可以不用管) 在你遇到了关于DLL的报错，请在bin文件夹中的GameEngine.dll复制到SandBox。

## 关于其他

首先项目使用了第三方库SPDLOG作为日志系统，然后请注意SPD的编译是UTF-8，所以请注意GameEngine与SandBox项目属性的命令行 /UTF-8。

但是在我们使用了premake构建后请注意premake5.lua文件确保 buildoptions { "/utf-8" } 在我们修改了lua里的文件请GenerateProjects.bat重新打包解决方案

### 关于cmd提交

>git commit -m "Commit"

>git push origin main