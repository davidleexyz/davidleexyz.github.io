import numpy as np

class Tensor(object):
  def __init__(self, data):
    if isinstance(data, np.ndarray):
      self._data = data
    else:
      raise "data is not an instance of numpy ndarray"

    self._creator = None

  @property
  def data(self):
    return self._data

  @property
  def shape(self):
    return self._data.shape

  @setattr
  def data(self, data):
    if isinstance(data, np.ndarray):
      self._data = data
    else:
      raise "data is not an instance of numpy ndarray"

  def reshape(self, shape):
    self._data = np.reshape(self._data)

  def device(self):
    return "cpu"