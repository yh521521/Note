**云原生-k8s**



ReplicaSet对象:得先说说ReplicationController（简称为RC）。在旧版本的Kubernetes中，只有ReplicationController对象。它的主要作用是**确保Pod以你指定的副本数运行**，即如果有容器异常退出，会自动创建新的 Pod 来替代；而异常多出来的容器也会自动回收。虽然 ReplicaSet 也可以独立使用，但建议使用 Deployment 来自动管理 ReplicaSet，这样就无需担心跟其他机制的不兼容问题（比如 ReplicaSet 不支持 rolling-update 但 Deployment 支持），并且Deployment还支持版本记录、回滚、暂停升级等高级特性。Deployment 的详细介绍和使用方法参见。

第 6讲____________________________________________________________________________________________________________________________
 3.以下关于paused说法错误的是： d 

A. 可以在deployment发布的过程中修改paused字段

B. paused默认值为false

C. paused不可以用来暂停扩缩容操作

D. deployment controller在发布出现问题时会自动设置paused
单选  6.关于MaxUnavailable以下说法正确的是：

A. MaxUnavailable不可以设置为0，否则无法发布

B. MaxUnavailable可以设置超过replicas

C. MaxUnavailable可以和MaxSurge同时设置为0

D. MaxUnavailable可以设置超过100%
正确答案： B

Deployment与ReplicaSet的关系与以下哪组资源最像？c

A. Pod与Node

B. Pod与Container

C. ReplicaSet与Pod

D. Deployment与Pod

多选  10.指定Deployment回滚到某个历史版本执行成功的过程中，不会发生以下哪些事件：

A. Pod创建和销毁

B. ReplicaSet创建和销毁

C. Deployment期望数量变化

D. Deployment template变化
正确答案： B C

单选  2.创建Deployment描述文件中写的template，用处不包括：d 

A. 声明Pod的挂载目录

B. 计算ReplicaSet的hash

C. 指定镜像版本

D. 指定期望数量

单选  4.一个Deployment中，哪些labels/selector必须一致：

A. deployment.Labels与deployment.Spec.Template.Labels一致

B. deployment.Labels与deployment.Spec.Selector一致

C. deployment.Spec.Selector与deployment.Spec.Template.Labels一致

D. deployment.Labels、deployment.Spec.Selector、deployment.Spec.Template.Labels三者都要一致
正确答案： C
