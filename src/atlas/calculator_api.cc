#include <dgl/runtime/packed_func.h>
#include <dgl/runtime/registry.h>

using namespace dgl::runtime;

DGL_REGISTER_GLOBAL("atlas.calculator._CAPI_Add")
.set_body([] (DGLArgs args, DGLRetValue* rv) {
    int a = args[0];
    int b = args[1];
    *rv = a * b;
  });

