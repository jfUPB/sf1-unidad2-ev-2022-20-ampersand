#line 1 "/home/pop-os/sf1-unidad2-ev-2022-20-ampersand/Evaluacion_Unidad2/Library/PackageCache/com.unity.toolchain.linux-x86_64@2.0.2/Documentation~/snippets/choosingbuilding.md"
## Choosing the correct toolchain package

When you install a package to build the Linux IL2CPP player, choose the com.unity.toolchain.* package the based on your host (Editor) platform:

- Linux x86_64: com.unity.toolchain.linux-x86_64
- MacOS x86_64: com.unity.toolchain.macos-x86_64-linux-x86_64
- Windows x86_64: com.unity.toolchain.win-x86_64-linux-x86_64

## Building a Linux IL2CPP player

When you have installed your toolchain package, go to **Project Settings** &gt; **Player** &gt; **Configuration** and set the **ScriptingBackend** to **IL2CPP**.

To build your project go to **File** &gt; **Build Settings**, in the **Target Platform** dropdown select **Linux,** then click **Build** or **Build and Run.** 
