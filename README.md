# 服务器健康监控系统

* 安装：
    * 进入目录：cd ./Server/(服务器端)或cd ./Master(监控端)
    * 清空编译文件：make clean
    * 编译链接生成可执行程序：make 
    * 安装到系统服务（使用systemd）：sudo make install
    * 卸载：sudo make uninstall
    * 服务器端：
        1. 查看服务状态：sudo systemctl status SHMS-Server.service
        2. 启动服务：sudo systemctl start SHMS-Server.service
        3. 停止服务：sudo systemctl stop SHMS-Server.service
        4. 重启服务：sudo systemctl restart SHMS-Server.service
    * 监控端：
        1. 查看服务状态：sudo systemctl status SHMS-Master.service
        2. 启动服务：sudo systemctl start SHMS-Master.service
        3. 停止服务：sudo systemctl stop SHMS-Master.service
        4. 重启服务：sudo systemctl restart SHMS-Master.service


