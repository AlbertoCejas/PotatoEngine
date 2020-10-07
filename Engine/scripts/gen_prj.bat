cd ..
mkdir build

cmake -S . -B build -DCMAKE_CONFIGURATION_TYPES="Debug;Release;RelWithDebInfo" -DCMAKE_INSTALL_PREFIX=install

cd scripts
