# file: calculator.py
from ._ffi.function import _init_api

def add(a, b):
  # MyAdd has been registered via `_ini_api` call below
  return MyAdd(a, b)

_init_api("dgl.calculator")