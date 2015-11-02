dev=$(pwd)
nitrobin=$dev/../nitro/bin
build="/build"
target="$build/emu-make"

set -e

./mountbuild.sh

if [ ! -d $target ]; then
  mkdir $target
fi

cd $target

cmake -D"CMAKE_BUILD_TYPE=Release" -D"MAC=1" -G"Unix Makefiles" $dev

make -j 8

ls -l

cp testmame $nitrobin