**云原生-k8s**



ReplicaSet对象:得先说说ReplicationController（简称为RC）。在旧版本的Kubernetes中，只有ReplicationController对象。它的主要作用是**确保Pod以你指定的副本数运行**，即如果有容器异常退出，会自动创建新的 Pod 来替代；而异常多出来的容器也会自动回收。虽然 ReplicaSet 也可以独立使用，但建议使用 Deployment 来自动管理 ReplicaSet，这样就无需担心跟其他机制的不兼容问题（比如 ReplicaSet 不支持 rolling-update 但 Deployment 支持），并且Deployment还支持版本记录、回滚、暂停升级等高级特性。Deployment 的详细介绍和使用方法参见。