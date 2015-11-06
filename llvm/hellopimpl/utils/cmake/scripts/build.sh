
if [ -z "$1" ]; then
  echo "'source dir path' argument required."
  exit 1
fi

CC=clang \
cmake -v \
  -DLLVM_DIR=$(llvm-config --prefix)/share/llvm/cmake/ \
  -DCMAKE_BUILD_TYPE=DEBUG -DCMAKE_INSTALL_PREFIX=../install \
  -DCMAKE_EXPORT_COMPILE_COMMANDS=ON $1

