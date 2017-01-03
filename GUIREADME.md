Executing SDx Examples in the 2016.3 SDx GUI
===============================================================================

All of the examples available in the SDx GitHub repository can be compiled by using either the provided Makefiles or the SDx GUI. Documentation on how to Makefile compilation is included in the README file of each example. This document outlines the steps to run an example application in the SDx GUI.

The steps described in this document use the hello example application as a reference. These steps apply to all example applications in the repository.

### Configure the design to be compiled by the GUI
- Change directory into the example of choice. For these instructions, the hello example is used. It is assumed the example repository has been cloned into a directory called *example*
```
    cd example/getting_started/basic/hello
```
- Execute the following command
```
    make local-files
```

### Create the Hello Application Example Project in the GUI
- Open the SDx GUI by running the following command in the terminal window
```
    sdx
```
- Create a new project for the example design. This will open the *New Project Wizard*

- In the *Templates* page, select **Empty Application**

![empty application select](./img/empty_app.png)

- In the new project, right-click on the **src** folder, and select **Import...** to start the file import Wizard

- In the *Import* wizard, select **General > File Systems** and click **Next**

![file system select](./img/filesystem.png)

- Browse to the *src* directory for the *hello example design*

- Select all of the source files and click **Finish**

![source file select](./img/src_select.png)

- In the **Project Settings** window, click **Add HW Function...***

- Select *krnl_hello* and click **OK**. This will add the accelerator function for the *hello example* to the project

![hardware function](./img/hardware_function.png)

- Build and run the application

### Configure a project with multiple kernels

Some example projects, such as *getting_started/basic/vmul_vadd*, need to be set up with more than one binary container.

As an example, the *vmul_vadd* project defines two kernels: *krnl_vadd* and *krnl_vmul*, which are expected to be found in *krnl_vadd.xclbin* and *krnl_vmul.xclbin*.

To set up the project to create these, follow these steps:
- In the **Project Settings** window, click **Add Binary Container**. This will create a new binary container.

- Click **Add HW Function...**

- Select *krnl_vmul* and click **OK**. This will add the accelerator function to the selected binary container.

- Change the name of the binary container to *krnl_vmul*. To change the name, click on the *binary_container_1* name in the **HW Functions** table, and type the new name.

- Repeat these steps to add the *krnl_vadd* accelerator function to a binary container named *krnl_vadd*.

### Configure command line arguments

Some applications use custom command line arguments, or do not need the .xlcbin file specified on the command line.

To change the command line arguments:
- In the **Run** menu, click **Run Configurations...**.

- Check that the run configuration for the current project is selected. *OpenCL > example-Default* should be selected in the tree.

- Select the **Arguments** tab.

- If the .xclbin filenames are not needed on the command line, uncheck **Automatically add binary container(s) to arguments**.

- Type any custom command line arguments in the text box.

- Click **Close** to save changes, or **Run** to save changes and then run the application.
