#include <dgl/packed_func_ext.h>
#include <dgl/runtime/packed_func.h>
#include <dgl/runtime/registry.h>

using namespace dgl::runtime;

class CalculatorObject : public Object {
 public:
  std::string brand;
  int price;

  void VisitAttrs(AttrVisitor *v) final {
    v->Visit("brand", &brand);
    v->Visit("price", &price);
  }

  static constexpr const char* _type_key = "Calculator";
  DGL_DECLARE_OBJECT_TYPE_INFO(CalculatorObject, Object);
};

// This is to define a reference class (the wrapper of an object shared pointer).
// A minimal implementation is as follows, but you could define extra methods.
class Calculator : public ObjectRef {
 public:
  const CalculatorObject* operator->() const {
    return static_cast<const CalculatorObject*>(obj_.get());
  }
  using ContainerType = CalculatorObject;
};

DGL_REGISTER_GLOBAL("atlas.calculator._CAPI_CreateCaculator")
.set_body([] (DGLArgs args, DGLRetValue* rv) {
  std::string brand = args[0];
  int price = args[1];
  auto o = std::make_shared<CalculatorObject>();
  o->brand = brand;
  o->price = price;
  *rv = o;
});