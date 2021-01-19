---------------------------
- Mastercam C-Hook Wizard -
---------------------------

Installing your C-Hook:

Once you have successfully built your C-Hook project in either Debug or Release mode, 
you can install the C-Hook (.DLL) and (optional) related Function Table (.FT) file
to Mastercam by running the "InstallDebug.bat" or "InstallRelease.bat".
These batch files will copy the appropriate files to Mastercam's C-Hooks directory.

Note: 
You may wish to have these batch files run automatically upon completion of a build. 
To do this, add the batch file to your project's post-build events. In Visual Studio,
this can be achieved through Project->Properties->Build events->Post-Build Event.
If used in this manner, the Command Line within the Post-Build Event would be:
"InstallDebug.bat" or "InstallRelease.bat".
And be sure to set the "Use in Build" option to "Yes".

*Note: With Windows 7/8/10:
If Mastercam is installed under the (default location) "Program Files" folder, these batch files
may fail with an "Access Denied" error. This is because of the Windows UAC security.
You must be running "As Administrator" to copy files into the folders under the "Program Files" folder.
If you wish to use these batch files as post-build commands in your C-Hook project,
Visual Studio must be running "As Administrator".

There are a couple ways to accomplish this:

When you start Visual Studio, right click on the shortcut and select "Run as administrator".

Or you can setup Visual Studio to *always* "Run as administrator" by navigating in Windows Explorer
to Visual Studio’s DEVENV.EXE, right click on it, select Properties and on the Compatibility tab 
check the "Run this program as an administrator" option.

Where to find DEVENV.EXE will depend on where you installed Visual Studio 2017.
For Visual Studio 2017, the path also depends on the "edition" of Visual Studio you are running.
"C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\Common7\IDE\devenv.exe"
Here the "Enterprise" part of the path may be different on your system.
