# PcdPlyConverter

## purpose
convert .pcd file -> .ply file  
convert .ply file -> .pcd file

## usage
git clone or download zip of this repository.  
Just DoubleClick pcd_ply_converter in bin directory.

## tested environment
macOS Sierra (Version 10.12.2)  
if you compile it by yourself, it works on any platforms (didn't confirm it though)

## for development (for compile it by yourself)
install pcl (if you use mac, "brew install pcl" is all you should do)
```
git clone git@github.com:RyoheiKomiyama/PcdPlyConverter.git
cd PcdPlyConverter
mkdir build
cd build
cmake ..
make
```
