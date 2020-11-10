cd ..
mkdir build

cmake -S . -B build -DCMAKE_CONFIGURATION_TYPES="Debug;Release;RelWithDebInfo"

cd scripts
