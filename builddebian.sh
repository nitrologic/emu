emu=$(pwd)
nitrobin=$emu/../../bin

target="/build/emu"

set -e

if [ ! -d $target ]; then
  mkdir $target
fi

cd $target

cmake -D"CMAKE_BUILD_TYPE=Release" -D"PI=1" -G"Unix Makefiles" $emu

make -j 8

ls -l .

cp testmame $nitrobin
