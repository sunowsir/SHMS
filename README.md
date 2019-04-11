# 服务器健康监控系统

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
