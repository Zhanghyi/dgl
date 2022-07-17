from .._ffi.function import _init_api
from .._ffi.object import register_object, ObjectBase

def add(a, b):
  return _CAPI_Add(a, b)

@register_object
class Calculator(ObjectBase):
  @staticmethod
  def create(brand, price):
    return _CAPI_CreateCaculator(brand, price)
  
_init_api("dgl.atlas.calculator")