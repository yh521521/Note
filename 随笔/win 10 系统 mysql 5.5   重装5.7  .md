win 10 系统 mysql 5.5   重装5.7  

   自学cloud  Apollo  需要 mysql 5.65以上 只能卸载 之前的老版本 重装新版本  用的是压缩版

解压即可用

 1 首先卸载 mysql旧版数据库 解压5.7.11到指定位置

2复制 my-default.ini 改为 my.ini

> > > [mysqld]
> > > server_id=2
> > > port=3306
> > > basedir=E:\\Mysql_5.7\\mysql-5.7.11-winx64
> > > datadir=E:\\Mysql_5.7\\mysql-5.7.11-winx64\\data

3 进入到 bin 目录  mysqld --initialize --console 

会生成密码  2020-02-29T02:52:50.799276Z 1 [Note] A temporary password is generated for root@localhost: **CX_tjNygj8zA** 

4  打开 services.msc关闭服务 regedit  打开注册表 



![mysql 注册表](../../img/mysql/mysql-service.png)

![](../../img/mysql/mysql-rededit.png)

![](../../img/mysql/mysql-cmd.png)

