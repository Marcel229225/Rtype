rm -rf build
mkdir ./build/ && cd ./build/
conan install .. --build=missing -s compiler.libcxx=libstdc++11 && cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
cp bin/r-type_client ..
cp bin/r-type_server ..
cpack .
tar -xzvf  r-type_server-0.1.1-Linux.tar.gz
mv r-type_server-0.1.1-Linux r-type