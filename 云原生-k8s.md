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

9
******************************************************************************************************
 *1 volumes  k8s中 的数据卷  也就是存放数据的地方   持久化数据  Volume主要是为了存储一些有必要保存的数据,
   而Persistent Volume主要是为了管理集群的存储。
*2 Persistent Volume和Persistent Volume Claim类似Pods和Nodes的关系，创建Pods需要消耗一定的Nodes的资源。而Persistent Volume则是提供了各种存储资源，而Persistent Volume Claim提出需要的存储标准，然后从现有存储资源中匹配或者动态建立新的资源，最后将两者进行绑定。

　PersistentVolume（PV）是集群中由管理员配置的一段网络存储
 
 PersistentVolumeClaim（PVC）是由用户进行存储的请求。
 
 虽然PersistentVolumeClaims允许用户使用抽象存储资源，但是PersistentVolumes对于不同的问题，用户通常需要具有不同属性（例如性能）。群集管理员需要能够提供各种PersistentVolumes不同的方式，而不仅仅是大小和访问模式，而不会让用户了解这些卷的实现方式。对于这些需求，有StorageClass 资源。
 
 ##   pv   pvc 生命周期  pv和pvc是一对一绑定的   一对一  
 Provisioning ——-> Binding ——–>Using——>Releasing——>Recycling
  供应准备Provisioning 分为静态 Static  和动态 Dynamic
   绑定Binding
    使用Using---用户可在pod中像volume一样使用pvc。
     释放Releasing
     
     回收Recycling---pv可以设置三种回收策略：保留（Retain），回收（Recycle）和删除（Delete）
     - 保留策略：允许人工处理保留的数据。
    - 删除策略：将删除pv和外部关联的存储资源，需要插件支持。
    - 回收策略：将执行清除操作，之后可以被新的pvc使用，需要插件支持。
    
     PV卷阶段状态

 Available – 资源尚未被claim使用
 
 Bound – 卷已经被绑定到claim了
 
 Released – claim被删除，卷处于释放状态，但未被集群回收。
 
 Failed – 卷自动回收失败
## 1  pod 和node区别 Kubelet 
 Pod是Kubernetes抽象出来表示一组应用容器(比如Docker、rkt)，还有这些容器共享的资源。这些资源包括： 
 共享存储，比如Volumes
网络，比如独立的集群IP地址
如何去运行每个容器的信息，比如容器镜像版本、要使用的端口

，它们在同一个Node的上的共享上下文。
Pod总是运行在Node之上。Node是Kubernetes中的一个工作机器 通常是一个虚拟机或者物理机。每个Node被Master管理。一个节点能有多个pod,同时Kubernetes master在集群之上自动调度pod。Master的自动调度考虑到每个Node上的可用资源。

Kubelet,一个负责Kubernetes Master和Node之间通讯的进程；它管理着运行在机器上Pods和Containers

多选  10.在Kubernetes PVC+PV体系下通过CSI实现的volume plugins包括？

A. Kubernetes社区驱动实现的通用功能部分（https://kubernetes-csi.github.io/）

B. 云存储厂商实现的对接其OpenAPIs的driver部分

C. 自定义CRD以及Controller
正确答案： A B

attach：将存储卷挂载到 Node 上

mount：将存储卷挂载到指定目录中
##   k8s  卷插件从FlexVolume演变为CSI
在2019年初，in-tree插件被宣布弃用。 Kubernetes开发人员将维护FlexVolume插件，但是新功能只会添加到CSI，而不会添加到FlexVolume。


## pvc pv locac pv
刚开始的pvc  pv  是一个分布式系统要进行通信  后来用local pv 本地 不需要考虑通信
CSI(Container Storage Interface)不是一个卷插件，它是用于创建自定义组件以与数据存储一起使用的成熟标准。容器编排系统  相当于一个约定标准
