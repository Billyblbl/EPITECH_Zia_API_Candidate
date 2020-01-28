# EPITECH_Zia_API_Candidate

Candidate for the Zia {EPITECH} project common API in EPITECH-Paris

Group:

- guillaume.astorgis@epitech.eu,
- maxime.tarel@epitech.eu,
- darius.kohen@epitech.eu,
- maxime.cailliau@epitech.eu,
- baptiste.liger@epitech.eu

This API is allows a Zia core to dynamicaly load & unload modules at runtime.

## Layer Model

A description of the API's Layer Model can be found [here](docs/LayerModel.md)

## Modules Specs

Modules specifications & cross-modules symbols are defined [here](docs/Modules.md)

## Import

This API is meant to be imported in a project as a git submodule.
At the root of your project's repository, run
```
git submodule add https://github.com/Billyblbl/EPITECH_Zia_API_Candidate.git <directory_name>
```
replacing **<directory_name>** with the name of the directory you want it to stay in

Then run
```
git submodule update --init --recursive
```
to update the newly added submodule and all of its own submodule dependencies.

## Project Build Configuration

This API is designed around a cmake style build. To include it in your build, simply add the following lines in your project's CMakeLists.txt:
```cmake
add_subdirectory(<directory_name>)
target_link_libraries(<target_name> ZIAAPI)
```
replacing **<directory_name>** with the name of the directory of the submodule, and **<target_name>** by the name of the cmake target that you want to link ZIAAPI with


