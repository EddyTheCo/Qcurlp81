
# Simple Curl-P-81 trinary hash 


[TOC]

This repo implements a library for hashing using a simple version of Curl-P-81 for doing POW according to this [TIP](https://github.com/iotaledger/tips/blob/main/tips/TIP-0012/tip-0012.md)


## Installing the library 

### From source code
```
git clone https://github.com/EddyTheCo/Qcurlp81.git 

mkdir build
cd build
qt-cmake -G Ninja -DCMAKE_INSTALL_PREFIX=installDir -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTING=OFF -DBUILD_DOCS=OFF ../Qcurlp81

cmake --build . 

cmake --install . 
```
where `installDir` is the installation path.
One can choose to build or not the tests and the documentation with the `BUILD_TESTING` and `BUILD_DOCS` variables.

### From GitHub releases
Download the releases from this repo. 

## Adding the libraries to your CMake project 

```CMake
include(FetchContent)
FetchContent_Declare(
	Qtcurlp81	
	GIT_REPOSITORY https://github.com/EddyTheCo/Qcurlp81.git
	GIT_TAG vMAJOR.MINOR.PATCH 
	FIND_PACKAGE_ARGS MAJOR.MINOR CONFIG  
	)
FetchContent_MakeAvailable(Qtcurlp81)
target_link_libraries(<target> <PRIVATE|PUBLIC|INTERFACE> Qtcurlp81::qcurlp81)
```


## API reference

You can read the [API reference](https://eddytheco.github.io/Qcurlp81/) here, or generate it yourself like
```
cmake -DBUILD_DOCS=ON ../
cmake --build . --target doxygen_docs
```

## Contributing

We appreciate any contribution!


You can open an issue or request a feature.
You can open a PR to the `develop` branch and the CI/CD will take care of the rest.
Make sure to acknowledge your work, and ideas when contributing.
