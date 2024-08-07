# FdF (Wireframe Viewer)

## 💡 About the Project

**Linux only**

The FdF project provides a graphical representation of a landscape as a 3D object, where all surfaces are outlined in lines.

## Some Examples of the Rendered 3D Landscapes

- <img src="https://github.com/redarling/FdF-42-macOS/blob/main/img2.png" alt="Screenshot 1" width="500"/>
- <img src="https://github.com/redarling/FdF-42-macOS/blob/main/img1.png" alt="Screenshot 2" width="500"/>
- <img src="https://github.com/redarling/FdF-42-macOS/blob/main/img3.png" alt="Screenshot 3" width="500"/>

## 🛠️ Installation Instructions

To get started with the FdF project, follow these steps:

1. Clone the repository using the command:

    ```bash
    git clone https://github.com/redarling/FdF-42-linux.git
    ```

2. Navigate to the project directory:

    ```bash
    cd FdF-42-linux
    ```

3. To build the project, execute the following command:

    ```bash
    make
    ```

After successful compilation, you can run the application by providing a valid map.

## Example Command

```bash
./fdf maps/elem-fract.fdf
```

## 🛠️ Features

-   3D Terrain Visualization: Represents landscapes as 3D objects with outlined surfaces by using terrain data files provided when running the application.

Example of the valid map:

      0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
      0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
      0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
      0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
      0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
      0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
      0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
      0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
      0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
      0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
      0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0

The numbers respresent the height of a point in the landscape.

-   Interactive Controls: Navigate and manipulate the 3D view using intuitive controls.

## 📝 Author
- [asyvash](https://github.com/redarling)
