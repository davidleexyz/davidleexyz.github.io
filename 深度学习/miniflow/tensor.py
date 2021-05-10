import numpy as np

class Tensor(object):
  def __init__(self, data):
    if isinstance(data, np.ndarray):
      self._data = data
    else:
      raise "data is not an instance of numpy ndarray"
  
  @property
  def shape():
    return self._data.shape

  def reshape(self, shape):
    self._data = np.reshape(self._data)

  def device(self):
    return "cpu" if isinstance(self._data, np.ndarray) else "gpu"