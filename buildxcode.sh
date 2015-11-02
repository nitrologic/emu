dev=$(pwd)
build="/build"
target="$build/xcode-mame"

set -e

if [ ! -d $build/stub ]; then
  ./mountbuild.sh
fi

if [ ! -d $target ]; then
  mkdir $target
fi

cd $target
cmake -D"CMAKE_CONFIGURATION_TYPES=Release;Debug;MinSizeRel;RelWithDebInfo" -D"CMAKE_BUILD_TYPE=Release" -D"MAC=1" -GXcode $dev

# xcodebuild
