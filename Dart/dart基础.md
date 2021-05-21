## Builtin Types
### Number
- int
- double

```
// string to number
var one = int.parse('1');
var onePointOne = double.parse('1.1');

// number to string
var one = 1.toString() => "1";
var onePointOne = 3.14159.toStringAsFixed(2) => "3.14";
```

### String
```
var str = "this is a string";
var str = 'this is a string';

const str  = 'this is a string';

print('print $str for test');
```
用 ${var} 来使用内嵌字符串表达

### Boolean
true / false

### List
var list = [1, 2, 3];
=> 被推断成 List<int> 类型


### Set
var set = Set<String>{}; => 空集合
var set = {'a', 'b', 'c'}; => 推断成Set<String>类型

如果直接写 var set = {}; => 会被编译器当成map
需要在改成 var set = <int>{} 或者 var set = Set<int>{}

