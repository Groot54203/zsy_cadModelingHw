## 关键功能

1. 定义半边数据结构

   ```c++
   class Solid;
   class Face;
   class Loop;
   class HalfEdge;
   class Edge;
   class Vertex;
   class Edge;
   class Point;
   ```

2. 基于半边数据结构的五个欧拉操作

   ```c++
   Solid *mvfs(Point _point, Vertex *&_vertex);
   HalfEdge *mev(Vertex *_vertex, Point _point, Loop *_loop);
   Loop *mef(Vertex *_vertex_1, Vertex *_vertex_2, Loop*& _largeLoop);
   Loop *kemr(Vertex *_vertex_1, Vertex *_vertex_2, Loop*& _largeLoop);
   void kfmrh(Loop *_outter_loop, Loop *_inner_loop);
   
   ```

3. 基于欧拉操作的扫成操作

   ```c++
   Solid *sweep(Face *_face, glm::vec3 direction, float distance);
   ```

## 结果展示

1. 扫成操作

   ![result1](/Users/siyuanzhang/zsy_cadModelingHw/result1.png)

2. 欧拉操作生成的任意多环实体模型

   ![result2](/Users/siyuanzhang/zsy_cadModelingHw/result2.png)

![result3](/Users/siyuanzhang/zsy_cadModelingHw/result3.png)

## 操作说明

1. 旋转控制：WSAD
2. 切换实体模型：P
3. 终止程序：Q

## 环境说明、运行方法

1. OpenGL: glew, glfw, glut

2. VScode+CMake搭建

3. Terminal中直接生成Unix可执行文件

   ```shell
   cd /targetFolder
   cmake .
   make
   ```

