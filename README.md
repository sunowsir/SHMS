# 服务器健康监控系统

* 安装：

  进入目录：cd ./Server/(服务器端)或cd ./Master(监控端)
  编辑配置文件：./Server/server.conf（服务器端配置文件）、./Master/master.conf（监控端配置文件）
  清空编译文件：make clean
  编译链接生成可执行程序：make
  添加到系统服务（使用systemd）：sudo make install
  服务器端：
  查看服务状态：sudo systemctl status SHMS-Server.service
  启动服务：sudo systemctl start SHMS-Server.service
  停止服务：sudo systemctl stop SHMS-Server.service
  重启服务：sudo systemctl restart SHMS-Server.service
  监控端：
  查看服务状态：sudo systemctl status SHMS-Master.service
  启动服务：sudo systemctl start SHMS-Master.service
  停止服务：sudo systemctl stop SHMS-Master.service
  重启服务：sudo systemctl restart SHMS-Master.service

*  更新：

  sudo make update

* 卸载：sudo make uninstall