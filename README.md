# 服务器健康监控系统


* 简介：

  本程序是使用C语言和bash脚本实现的服务器健康监控系统。服务器端通过执行bash脚本获取健康信息，利用socket即时发送到监控端主机。

* 监测数据类型：

  * cpu
  * 内存
  * 硬盘
  * 恶意进程
  * 系统信息
  * 登录用户信息

* 技术说明：

  * C语言socket编程。
  * C语言多线程与多进程编程。
  * 数据结构实现（链表）。
  * linux的bash脚本编程。
  * linux systemd 的使用。

* 架构：

  * 监控端（Master）

    * 线程一：

      循环监听：使用socket监听，将收到的连接的套接字存储到长度最短的链表里。

    * 线程二：

      数据接收：通过读取配置文件创建若干数据发送的线程，每个线程分配一个链表。

      从链表读取一个套接字，接收六组数据，然后断开连接，将该套接字从链表中删除。

      保证数据的可靠性：六组数据，每组数据接收前，发送约定好的数据类型标志码，通知服务器本组应该发送的数据的类型。然后接收数据，存储到本地。

    * 线程三：

      紧急连接：单独开启通道，接受服务器连接，发送紧急报警信息。

      该数据单独存放在发送者目录下。

  * 服务器端（Server）:

    * 线程一：

      数据监测：运行监测脚本，将监测数据存储到文件。

    * 线程二：

      数据发送：根据监控端发来的数据类型读取相应监测数据的日志文件，发送给监控端。

      通过分析监测数据判断是否有警报信息，发送警报信息。

      数据获取与警报信息的即时性：无法做到数据发送的实时性，但是可以保证监测数据的实时性。每次只发送每种类型数据日志文件中的最上面一行，一共六组数据发送完成关闭连接。该方式牺牲一定的资源与数据传输的实时性，来保证线程一的一定程度的实时性。若非如此，只能采用文件锁来避免文件指针的冲突，这将会导致线程一阻塞，从而导致既服务法达到信息传输的实时性又无法达到监测数据与警报信息的实时性。

* 相关文件：
  * 配置文件：
    * 监控端：`/etc/SHMS-Master/master.conf` 
    * 服务端；`/etc/SHMS-Server/server.conf`
  * 运行日志文件：
    * 监控端：`/var/log/SHMS-Master/SHMS-Master.log`
    * 服务端：`/var/log/SHMS-Server/SHMS-Server.log`

* 编译安装：
  * 进入目录：`cd ./Server/build/`(服务器端)或`cd ./Master/build/`(监控端)
  * 清空编译文件：`make clean`
  * 编译链接生成可执行程序：`make`
  * 添加到系统服务(使用systemd)：`sudo make install`

* deb包安装：
  * 下载deb包：[release页面](https://github.com/sunowsir/SHMS/releases) 
  * 安装：`sudo dpkg -i xxx.deb`

* 服务操作：
  * 服务器端：
    * 查看服务状态：`sudo systemctl status SHMS-Server.service`
    * 启动服务：`sudo systemctl start SHMS-Server.service`
    * 停止服务：`sudo systemctl stop SHMS-Server.service`
    * 重启服务：`sudo systemctl restart SHMS-Server.service`
  * 监控端：
    * 查看服务状态：`sudo systemctl status SHMS-Master.service`
    * 启动服务：`sudo systemctl start SHMS-Master.service`
    * 停止服务：`sudo systemctl stop SHMS-Master.service`
    * 重启服务：`sudo systemctl restart SHMS-Master.service`
