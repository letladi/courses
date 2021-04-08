a)
   typedef char (*func(int));
   func arr[10];

b) 
   typedef int func_list[5];
   func_list (*x(int));

c) 
   typedef float* (float_func(int));
   float_func (x(void));

d) typedef void (func(int));
   typedef void (func2(int));
   func2 (x(int, func));