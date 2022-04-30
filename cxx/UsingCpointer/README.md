# ch2 dynamic memory allocators

四个用于动态内存分配的函数。

| Function |                 Description                  |
| :------: | :------------------------------------------: |
|  malloc  |           allocing memory for heap           |
| realloc  | 在之前分配的内存的基础上，重新分配内存的大小 |
|  calloc  |           分配内存，并且初始化为0            |
|   free   |               释放内存到堆中。               |

## 2.4  迷途指针

如果内存已经释放，而指针还在引用原始内存，这样的指针就称为迷 途指针。迷途指针没有指向有效对象，有时候也称为过早释放。 

使用迷途指针会造成一系列问题，包括： 

- 如果访问内存，则行为不可预期； 

- 如果内存不可访问，则是**段错误**； 

- 潜在的安全隐患。 

导致这几类问题的情况可能如下： 

- 访问已释放的内存； 

- 返回的指针指向的是上次函数调用中的自动变量。

一个示例是在free后继续通过该指针访问变量：

```c
int *pi = (int *)malloc(sizeof(int));
free(pi);

*pi = 5; //访问已释放的内存
```

或者更复杂点，p1，p2指向相同的位置，释放了p1，然后继续使用p2。

```c
int *p1 = (int *)malloc(sizeof(int));
int *p2 = p1；
free(p1);

*p2 = xxx // p2变成了迷途指针
```

### 解决方案

1. 释放指针后置为NULL，后续使用这个指针会终止应用程序。 不过，如果存在多个指针的话还是会有问题。因为赋值只会影响一个指针。 

2. 写一个特殊的函数代替free函数。 

```c
#define safeFree(p) safeFree((void **)&(p))

void safeFree(void **pp){
	if (pp != NULL && *pp != NULL){
		free(*pp);
		*pp = NULL
	}
}
```

3. 使用Visual Studio。VS的 malloc保存了更多的调试信息。

> [Finding Memory Leaks Using the CRT Library - Visual Studio 2015 | Microsoft Docs](https://docs.microsoft.com/zh-cn/previous-versions/visualstudio/visual-studio-2015/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2015&redirectedfrom=MSDN)

4. 用第三方工具检测迷途指针和其他问题。(使gcc达到VS的效果) 

除此之外，传统的print与assert调试方法也很好用。

## 2.5 一些非标准的工具来回收malloc出来的内存。

### 2.5.1 垃圾回收

http://www.hpl.hp.com/personal/Hans_Boehm/gc/

### 2.5.2 RAII for GNU

```c
#include <stdlib.h> // for malloc,realloc
#include <string.h> // for strcpy
#include <stdio.h> // for printf
#define RAII_VARIABLE(vartype,varname,initval,dtor) \
    void _dtor_ ## varname (vartype * v) { dtor(*v); } \
    vartype varname __attribute__((cleanup(_dtor_ ## varname))) = (initval)

void raiiEaxmple(){
	RAII_VARIABLE(char* ,name, (char *)malloc(sizeof(char) * 32), free);
    // char *name = malloc(32)
	strcpy(name,"RAII Eaxmple!");
	printf("%s\n",name);
    // 当name超出作用域时，会自动调用free。
}

int main(){
	raiiEaxmple();
	return 0;
}
```

> 使用gcc -E 可以获得一个展开后的程序。

### 2.5.3 异常处理

```c
void exceptionExample() { 
	int *pi = NULL; 
	__try{ 
		pi = (int*)malloc(sizeof(int)); 
		*pi = 5; 
		printf("%d\n",*pi); 
	}
	__finally{ 
		free(pi); 
	}
}
```

（http://www.adomas.org/excc/）这个例子仅适用于VS，由于finally块永远都会被执行，所以我们不用担心泄漏问题。

### 总结

动态内存分配是C语言的重要特性。本章主要关注用malloc和free函 数实现手动分配内存。我们解决了涉及这两个函数的一系列常见问 题，包括内存分配失败和迷途指针。 

**此外，还有一些非标准技术可用来实现C的动态内存管理。我们也接触了几种垃圾回收技术，包括RAII和异常处理。**

# ch4 pointers and arrays

分多次调用malloc，可以创建一个不规则数组。

