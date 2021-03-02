## 如何写一个NN编译器

### NN编译器作用
NN编译器是把一种op描述(src op)翻译到另外一种op(dst op)的过程, 从而能使不同的前端都可以统一用一种op来描述.

### IR定义(op)
Conv Pooling BatchNorm Relu FullConnect等

### 计算图(compute graph)
op之间的的联系组成一颗单/多输入输出的树(有向无环图DAG)
然后通过拓扑排序(Toplogic Sort)将这个DAG序列化, 然后按照顺序执行op来得到输出结果

### 后端(backend)
要在不同的硬件平台上执行op序列, 必须要抽象一个Device来表示后端设备
将high level op转化到设备的指令序列(cmd)的过程叫做lowering

### 前端优化(optimize)
为了加速计算过程, 通常会在计算图上做优化, 比如op的合并/转化得到一个等价图

### 后端优化(optimize)
优化的过程还可以在后端的指令序列上进行, 比如tiling, unroll, vector(SIMD)等

### 量化(quantization)
将weight和activation从float转到int8的过程叫做量化, 量化是为了加速计算