mkdir ..\build
cd ..\build

cmake -DCMAKE_CONFIGURATION_TYPES="Debug;Release;RelWithDebInfo" ..
cd .. 

cd scripts

pause 