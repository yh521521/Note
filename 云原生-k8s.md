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



#####################  10  存储快照 和拓扑调度    ####################
单选  1.在Kubernetes中使用自定义的拓扑（如rack, foo, bar）是否需要相关组件做修改？B   可以自定义 所以无需做出修改

A. 是

B. 否

单选  2.下面在Kube-Scheduler中结合Pod中声明的PVCs选择Node过程描述正确的有？

A. Pod中已经Bound的PVCs在Kube-Scheduler不做处理

B. Pod中所有UnBound的PVCs会先找到能匹配的PV列表，并check PV的NodeAffinity与Node Labals中的拓扑信息是否匹配

C. Pod中需要Dynamic Provisioning PV的PVCs，check StorageClass .allowedTopologies与Node Labals中的拓扑信息是否匹配
正确答案： C

多选  4.可以限制PV对象可被访问拓扑位置限制的地方？A B

A. StorageClass: .allowedTopologies

B. PV: .spec.nodeAffinity

C. Node: .metadata.labels

多选  6.Kubernetes中基于CSI实现存储快照（snapshot&restore）功能需要的组件有？

A. Kubernetes csi-snapshotter Controller

B. 云存储厂商基于存储快照的OpenAPI实现的Driver：Kubernetes csi-snapshotter GRPC server

C. Kubernetes csi-provisioner Controller

D. 云存储厂商基于存储快照create存储的OpenAPI实现的Driver：Kubernetes csi-provisioner GRPC server
正确答案： A B C D

多选  7.Kubernetes csi-snapshotter Controller中实现的功能包括？

A. watch VolumeSnapshot&&VolumeSnapshotContent等API资源对象变化

B. 根据VolumeSnapshot API资源对象声明调用相应云存储Driver（即csi-snapshotter GRPC server）创建快照，并生成VolumeSnapshotContent

C. bind VolumeSnapshot and VolumeSnapshotContent

D. 根据存储快照restore数据到新的PV对象中
正确答案： A B C

多选  9.下列有关使用存储拓扑调度时对StorageClass的配置正确的有？ ABC

A. 需要通过设置.volumeBindingMode: WaitForFirstConsumer来声明PVC延时处理

B. 可以通过.allowedTopologies限制动态生成的PV的拓扑限制，拓扑限制会写到动态生成的PV .spec.nodeAffinity中

C. 可以干预哪些需要使用该StorageClass动态生成PV对象的PVC的使用方Pod的可调度的Node
多选  10.下列有关如何使用存储拓扑调度的说法正确的有？ ABCD 

A. 声明delay binding的StorageClass对象（.volumeBindingMode=WaitForFirstConsumer）

B. PVC对象.spec.storageClassName指定为声明了delay binding的StorageClass对象

C. 在静态（预）创建的PV上的.spec.nodeAffinity添加对使用该PV的Pod所在Node拓扑限制

D. 在需要动态创建的PV所使用的StorageClass的.allowedTopologies中限制动态创建的存储能被使用的拓扑限制


##########     11  应用观测性   #########

Always     总是重启
OnFailure  失败才重启
Never      永远不重启

##  k8s支持存活livenessProbe和就绪readinessProbe两种探针

单选  1.kubectl-debug如何使用自定义的工具进行Pod调试？  A  debug-agent：部署在K8s的node上，用于启动关联  排错 工具容器；

A. 使用自定义镜像

B. 使用自定义命令

C. 使用自定义工具

D. 使用自定义配置

K8s pod诊断工具，kubectl-debug是一个简单、易用、强大的 kubectl 插件, 能够帮助你便捷地进行 Kubernetes 上的 Pod 排障诊断。它通过启动一个排错工具容器，并将其加入到目标业务容器的pid, network, user 以及 ipc namespace 中，这时我们就可以在新容器中直接用 netstat, tcpdump 这些熟悉的工具来解决问题了, 而业务容器可以保持最小化, 不需要预装任何额外的排障工具。
kubectl-debug 包含两部分:
kubectl-debug：命令行工具；
debug-agent：部署在K8s的node上，用于启动关联排错工具容器；


单选  2.以下哪个方式不是调试Pod的方法？  D 

A. 使用exec进入Pod进行调试

B. 查看Pod的事件

C. 查看Pod的日志

D. 查看Pod的标签

 #  一个应用可以组合两种探针同时使用。  
 
 # .Readiness Probe可以解决应用启动慢造成访问异常的问题。
 
 7.当Pod处在Pending的时候，可能是由于如下哪个问题造成的。   A B D

A. 资源不足，造成无法调度

B. Pod尚未进入调度阶段

C. Pod调度失败

D. Pod正在拉取镜像

多选  8.以下哪个关于Liveness Probe的描述是错误的？ A  D

A. Liveness Probe是就绪探针

B. Liveness Probe是存活探针

C. Livenss Probe和 Readiness Probe的探测方式是一致的

D. Liveness Probe主要面向有状态服务

###################     11  监控与日志   ##########################
判断  4.从功能性的角度而言，Heapster的Sink机制比Metrics-Server更强大。 正确

正确

错误
正确答案： 正确

判断  5.kube-eventer是一个开源的Kubernetes事件告警的工具，主要面向的场景是报警通道

正确

错误
正确答案： 错误
   .kube-eventer 是一个事件离线工具  
多选  8.以下哪些是阿里云容器服务的监控方案内容？  ABCD

A. 云监控

B. ARMS性能监控

C. AHAS架构感知监控


################### 12讲：Kubernetes网络概念及策略控   #############################

单选  3.一个只有spec的network policy，其他条件为空，意味着哪种行为？  B  

A. 进出流全部放行

B. 进出流全部禁止

C. 随意，看CNI实现

判断  5.net namespace拥有完全独立隔离的网络环境。 错误 

正确

错误
相关知识点： 不准确，协议栈代码是公用的，很多systemctl 可控参数并没有独立
正确答案： 错误

判断  6.Kubernetes的Pod只能有且只能配置1个IP地址。

正确

错误
相关知识点： 不准确，可以有多个IP地址，只是上报给CNI结果时候，只能报一个
正确答案： 错误

判断  7.Kubernetes 容器网络方案实现上，禁止任何形式的地址转换（NAT）。

正确

错误
相关知识点： 可以使用NAT作为实现手段，不能被Pod-APP感知
正确答案： 错误


判断  8.Kubernetes network policy只支持TCP/UDP作为协议字段值。

正确

错误
相关知识点： 还支持stcp（alpha特性）


D. 托管Prometheus资源监控

多选  10.以下哪些是阿里云容器服务的日志方案的优势？  ABCD

A. 丰富的数据采集方式

B. 多种的数据展现与集成能力

C. 数据分析与增值服务

D. 开源场景的整合

