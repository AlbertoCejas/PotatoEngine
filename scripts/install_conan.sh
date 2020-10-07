sudo pip3 install setuptools
sudo pip3 install conan
conan remote add bincrafter https://api.bintray.com/conan/bincrafters/public-conan
conan remote add conan-community https://api.bintray.com/conan/conan-community/conan
conan remote add imgui_docking https://api.bintray.com/conan/ithyx/imgui
conan profile new default --detect
conan profile update settings.compiler.libcxx=libstdc++11 default