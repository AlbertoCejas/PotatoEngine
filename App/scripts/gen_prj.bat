cd ..
mkdir build

cmake -S . -B build -DCMAKE_CONFIGURATION_TYPES="Debug;Release;RelWithDebInfo" -DCMAKE_INSTALL_PREFIX=. -DCMAKE_PREFIX_PATH=%cd%/../Engine/install/

cd scripts

pause 