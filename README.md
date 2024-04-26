# Uniwal
A light and fast C++ library for the universal model of weak antilocalization.

## Weak Antilocalization
Weak antilocalization (or localization) is a macroscopic manifestation of quantum interference. 
The wavefunction of an electron in a disordered 2D system (e.g. semiconductor thin films) can interfere with itself and make the electron a little bit more localized (weak localization) or a little bit more mobilized (weak antilocalization). 
In experimental settings this effect can be probed by measuring the resistance of the sample in the presence of an external magnetic field (magneto-resistance). 
These measurements can give us useful information about the electrons and their spins. 
This library provides a numerical model of weak antilocalization based on semiclassical Boltzmann transport which is valid under a wide range of conditions (universal). 

## Getting Started 

The code is divided into two separate parts: the `Uniwal` library and the `UniwalApp` application. 
Once installed, the library can be used in other applications or programs of your own. 
The application is just a sample code to show how to use the library and how to fit experimental data.

### Dependencies 
- **cmake**: used to configure make files and build (compile) the library and the application.
- **gtest**: used for unit testing. It is automatically fetched (downloaded and installed) by cmake.

### Clone the repository
First download the current repository and change your directory to the root `uniwal` folder where this `README.md` file is located. 

```bash 
git clone https://github.com/smfarzaneh/uniwal.git
cd uniwal
```

### Compile
Then you would need to compile the source code into binary files and executables. 
The following shell commands compile both `Uniwal` and `UniwalApp` and puts the binaries inside the `build/` subdirectory.

```bash
cmake -S . -B build/
cmake --build build/
```

### Run Tests
This is optional. 
If you want to run the unit tests on the library to make sure everything works on your system as it's supposed to, run the following command

```bash
ctest --test-dir build/ --output-on-failure
```

### Run the Application
To see the library in action run the following command to execute the `UniwalApp` application.

```bash 
./build/UniwalApp
```

