// file: calculator.cc (put it in dgl/src folder)
#include <dgl/runtime/packed_func.h>
#include <dgl/runtime/registry.h>

using namespace dgl::runtime;

DGL_REGISTER_GLOBAL("calculator.MyAdd")
.set_body([](DGLArgs args, DGLRetValue* rv) {
    // int a = args[0];
    // int b = args[1];
    *rv = 1 * 1;
  });