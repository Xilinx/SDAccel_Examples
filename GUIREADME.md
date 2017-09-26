Executing SDx Examples in the SDx GUI
===============================================================================

The examples available in the SDx GitHub repository can be compiled by using either the provided Makefiles or the SDx GUI. Documentation on how to Makefile compilation is included in the README file of each example. This document outlines the steps to run an example application in the SDx GUI.

To use an example in the GUI, it must be downloaded as an example template, then a new project must be created using the example template. The steps to do this are described below.

### Download the example template in the GUI
- Open the SDx GUI by running the following command in the terminal window:
```
    sdx
```

- Select *SDx Example Store...* from the *Xilinx* menu. This will open a dialog where you can download example templates.

- When the dialog is opened the first time, the example repositories will be downloaded. To download updates to the examples, click *Update*.

- After downloading the examples, the examples will show as *Installed*.

*Note:* After installing the examples, they will be available as project templates when creating a new SDx project.

- Close the dialog.


### Create the Hello Application Example Project in the GUI
- In the SDx GUI, Create a new project for the example design. This will open the *New Project Wizard*.

- In the *Templates* page, select an example that has been downloaded.

*Note:* some examples require specific hardware or runtime support, and will only be available for matching platforms and runtimes in the *New Project Wizard*.

- Finish the wizard. The project will be created with the sources and project settings required to build and run the example.

- Build and run the application.

