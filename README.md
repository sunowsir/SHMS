# 服务器健康监控系统

* 安装：

  1. 进入目录：`cd ./Server/`(服务器端)或`cd ./Master`(监控端)
  2. 编辑配置文件：`vim ./Server/server.conf`（服务器端配置文件）、`vim ./Master/master.conf`（监控端配置文件）
  3. 清空编译文件：`make clean`
  4. 编译链接生成可执行程序：`make`
  5. 添加到系统服务（使用systemd）：`sudo make install`
  6. 服务器端：
  7. 查看服务状态：`sudo systemctl status SHMS-Server.service`
  8. 启动服务：`sudo systemctl start SHMS-Server.service`
  9. 停止服务：`sudo systemctl stop SHMS-Server.service`
  10. 重启服务：`sudo systemctl restart SHMS-Server.service`
  11. 监控端：
  12. 查看服务状态：`sudo systemctl status SHMS-Master.service`
  12. 启动服务：`sudo systemctl start SHMS-Master.service`
  14. 停止服务：`sudo systemctl stop SHMS-Master.service`
  15. 重启服务：`sudo systemctl restart SHMS-Master.service`

*  更新：`sudo make update`

* 卸载：`sudo make uninstall`
