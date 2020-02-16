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


第7讲：应用编排与管理：Job 和 DaemonSet
scale up 增大 提高  scale down  缩小 减弱

parallelism   并行执行的pod 数量  
英 [ˈpærəlelɪzəm]   美 [ˈpærəlelɪzəm]  

多选  10.使用哪些标签能让 daemonset 的 pod 只运行在某些节点？A B

A. .spec.template.spec.nodeSelector

B. .spec.template.spec.affinity

C. Taints and Tolerations

D. matchExpressions


单选  5.有一个任务会偶发失败，我们希望失败的时候能够不断的重试直到任务能够运行成功，应该使用哪几个标签配合完成?

A. restartPolicy: Never  此失败容器不会被重启  

B. restartPolicy: OnFailure   容器失败后会自动重启

C. restartPolicy: Always  job  只有两种状态
正确答案： B

                 .restartpolicy指定什么情况下需要重启容器。对于job只能设置为never或者onfailure

                   对于其他的controller（比如deployment，replicaset等）可以设置为always

A. DeadlineExceeded
 
多选  8.以下 Daemonset yaml 中，哪些是正确的？  C D 

A. apiVersion: apps/v1 kind: DaemonSet metadata: name: fluentd-elasticsearch namespace: default labels: k8s-app: fluentd-logging spec: selector: matchLabels: name: fluentd-elasticsearch template: metadata: labels: name: fluentd-elasticsearch spec: containers: - name: fluentd-elasticsearch image: gcr.io/fluentd-elasticsearch/fluentd:v2.5.1 restartPolicy: Never

B. apiVersion: apps/v1 kind: DaemonSet metadata: name: fluentd-elasticsearch namespace: default labels: k8s-app: fluentd-logging spec: selector: matchLabels: name: fluentd-elasticsearch template: metadata: labels: name: fluentd-elasticsearch spec: containers: - name: fluentd-elasticsearch image: gcr.io/fluentd-elasticsearch/fluentd:v2.5.1 restartPolicy: Onfailure

C. apiVersion: apps/v1 kind: DaemonSet metadata: name: fluentd-elasticsearch namespace: default labels: k8s-app: fluentd-logging spec: selector: matchLabels: name: fluentd-elasticsearch template: metadata: labels: name: fluentd-elasticsearch spec: containers: - name: fluentd-elasticsearch image: gcr.io/fluentd-elasticsearch/fluentd:v2.5.1 restartPolicy: Always

D. apiVersion: apps/v1 kind: DaemonSet metadata: name: fluentd-elasticsearch namespace: default labels: k8s-app: fluentd-logging spec: selector: matchLabels: name: fluentd-elasticsearch template: metadata: labels: name: fluentd-elasticsearch spec: containers: - name: fluentd-elasticsearch image: gcr.io/fluentd-elasticsearch/fluentd:v2.5.1


多选  10.使用哪些标签能让 daemonset 的 pod 只运行在某些节点？ A  B

A. .spec.template.spec.nodeSelector

B. .spec.template.spec.affinity

C. Taints and Tolerations

D. matchExpressions
单选  1.Job 中 spec 可否指定replicas 参数？B   Replicas 副本   ReplicaSet控制器才可以设置副本数量

A. 可以

B. 不可以

8 应用配置管理
_____________________________________________________________________________________________________________________

单选  3.ServiceAccount创建完成，其对应的Secret信息由哪个组件更新

A. kube-apiserver

B. kube-controller-manager

C. kube-scheduler

D. kubelet
正确答案： B

多选  7.InitContainer理解正确的有

A. InitContainer先于普通容器启动执行

B. 多个InitContainer的执行是按定义次序串行执行，而多个普通容器是并行执行

C. InitContainer执行成功后就结束退出，而普通容器可以一直执行

D. Pod重启时，InitContainer会再次执行      **************************
正确答案： A B C D

多选  8.如下哪些方式创建的Pod可以使用ConfigMap  

A. Kubectl

B. Dashboard

C. kubelet mainifests

D. kubelet url
正确答案： A B

kubectl是k8s集群的   客户端  ，用户通过kubectl连接到集群的apiserver，并将命令传递到master上，然后master再将命令分发到node节点上执行。

多选  10.下面容器资源申明合理的是

A. resources: requests: cpu: 100m limits: cpu: 500m

B. resources: requests: cpu: 200m limits: cpu: 100m      应该是限制写反了吧   

C. resources: requests: cpu: 100m memory: 64Mi

D. resources: limits: cpu: 100m
正确答案： A C D

