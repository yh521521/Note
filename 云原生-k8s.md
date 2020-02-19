## cloudNative-k8s



ReplicaSet对象:得先说说ReplicationController（简称为RC）。在旧版本的Kubernetes中，只有ReplicationController对象。它的主要作用是**确保Pod以你指定的副本数运行**，即如果有容器异常退出，会自动创建新的 Pod 来替代；而异常多出来的容器也会自动回收。虽然 ReplicaSet 也可以独立使用，但建议使用 Deployment 来自动管理 ReplicaSet，这样就无需担心跟其他机制的不兼容问题（比如 ReplicaSet 不支持 rolling-update 但 Deployment 支持），并且Deployment还支持版本记录、回滚、暂停升级等高级特性。Deployment 的详细介绍和使用方法参见。


## 6应用编排与管理： Deployment


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


## 7 应用编排与管理：Job 和 DaemonSet


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


## 8 应用配置管理


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

D. Pod重启时，InitContainer会再次执行     
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

## 9 应用存储和持久化数据卷 - 核心知识

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



##  10  存储快照 和拓扑调度 


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


##  11  应用观测性   

Always     总是重启
OnFailure  失败才重启
Never      永远不重启

 #  k8s支持存活livenessProbe和就绪readinessProbe两种探针

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

## 12  监控与日志   


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


## 13 Kubernetes网络概念及策略控 

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


## 14     Kubernetes Services 


 单选  1.Kubernetes的Service的对象中怎么声明选择负载均衡的后端Pod？

A. 通过Pod的label选择

B. 通过Pod的IP选择

C. 通过Pod的annotation选择

D. 通过Pod的镜像选择
正确答案： A

service 模版  这个service代理了所有具有MyApp标签的pod
 {    "kind": "Service”,    当前资源类型为  service  
        "apiVersion": "v1”,     版本
          "metadata”: 元数据
                 {        "name": "my-service"    },     资源的名字  是   my-service b 
           "spec": {        "selector”:  选择器
                            {            "app": "MyApp"        },    app name     
                                     "ports": [            端口
                       {                "protocol": "TCP”,      tcp 协议       
                                            "port": 80,                     访问端口                     
                                       "targetPort": 9376            }   重定向刀9376端口     ]    }
                                       
   ##   service：
      服务，是一个虚拟概念，逻辑上代理后端pod。众所周知，pod生命周期短，状态不稳定，pod异常后新生成的pod ip会发生变化，之前pod的访问方式均不可达。通过service对pod做代理，service有固定的ip和port，ip:port组合自动关联后端pod，即使pod发生改变，kubernetes内部更新这组关联关系，使得service能够匹配到新的pod。这样，通过service提供的固定ip，用户再也不用关心需要访问哪个pod，以及pod是否发生改变，大大提高了服务质量。
      
  #在Pod中，应用可以直接通过资源的名字直接访问的资源是 service
  
  单选  3.Kubernetes clusterIP的Service的域名解析响应是什么DNS记录类型？

A. CNAME

B. A

C. TXT

D. SOA
正确答案： B  
## dns 类型 
soa   起始授权机构(SOA, Start Of Authority)的资源记录，描述了域名的管理员、电子邮件地址，和一些时间参数
A   A (Address) 记录是用来指定主机名（或域名）对应的IP地址记录。用户可以将该域名下的网站服务器指向到自己的web server上。同时也可以设置您域名的子域    名。通俗来说A记录就是服务器的IP,域名绑定A记录就是告诉DNS,当你输入域名的时候给你引导向设置在DNS的A记录所对应的服务器 

Cname (Canonical Name)记录，通常也被称为规范名字 kəˈnɒnɪkl 规范的
     CNAME是别名解析，别名解析是先将域名解析到主机别名再转跳到IP，这样主机IP改变了不用重新解析。
MX  MX记录也叫做邮件路由记录，用户可以将该域名下的邮件服务器指向到自己的mail server上，然后即可自行操控所有的邮箱设置。   
NS（Name Server）记录是域名服务器记录 NS记录是指定由哪个DNS服务器解析你的域名。 
TXT TXT记录一般是为某条记录设置说明
 AAAA   记录是用来指定主机名（或域名）对应的IPv6地址记录。
 SRV 记录了哪台计算机提供了哪个服务。格式为：服务的名字.协议的类型（例如：_example-server._tcp）
 
 判断  5.Pod可以直接用Service名来访问同一个集群里的Service，不管Pod和Service在不在一个Namespace。  错误

正确

错误

同一个namespace  可以直接servicename访问  不同的namespace要加上namespace访问  访问方式 {serviceName}.{nameSpace}

9.下列哪些方式可以作为Pod访问Service的途径？  A B  D 

A. 环境变量

B. Service名

C. Service的Label

D. Service的ClusterIP

多选  10.下列哪些类型的Service用于向集群外部暴露访问？ A C 

A. NodePort

B. ClusterIP

C. LoadBalancer

D. ExternalName

## 建LoadBalancer类型的Service会自动创建和绑定外部LoadBalancer到节点映射的NodePort上。



## 15  深入剖析 Linux 容器  



单选  1.docker run –net=none busybox top，请问这个容器会有自己的netns（网络namespace 文件）吗？  A   

A. 有，none也是一种网络模式，所以有       

B. 没有，都是none了，所以没有netns
–net=none   ###  可以自行配置网络，让容器达到跟平常一样具有访问网络的权限

单选  2.一个docker容器，在宿主机上有几个进程（除了容器内部进程之外的其他进程）？  C

A. 3个，docker进程，contanerd-shim进程和runc进程

B. 2个，contanerd-shim进程和runc进程

C. 1个，contanerd-shim进程
docker容器内的一个进程对应于宿主机器上的一个进程。容器内的进程，与相对应的宿主进程，由相同的uid、gid拥有

单选  3.宿主机上能否看见容器内的进程？ B 

A. 不能，因为容器有自己的pid namespace，隔离了宿主机上的进程可见性

B. 能，只是容器内外看到的进程pid不一样
正确答案： B

查看容器日志的命令   docker logs $container
 runc 的作用是什么一种oci运行时，负责创建容器   常用的就是docker  run  命令 就是创建容器 的
 
 单选  6.要创建一个共享宿主机pid namespace的容器，命令是？

A. docker run --name demo-1 –pid non-container busybox top

B. docker run --name demo-2 –pid host busybox top

C. docker run --name demo-1 –pid container:host busybox top
正确答案： B
单选  7.运行 docker stop $container 命令停止一个容器后，容器的相关文件还在吗？ A

A. 在，stop只是停止了进程，文件等内容还是在宿主机上的
B. 不在，进程消失了，容器全部都不见了
好像是 用的volume  数据卷  持久化之类的     文件还在的

单选  8.docker在宿主机上最多可以创建多少个容器？ C 

A. 1000

B. 和宿主机的cpu/memory 资源有关系

C. 不一定
默认的情况下，docker 没有对容器进行硬件资源的限制
Docker 的资源限制和隔离完全基于 Linux cgroups

###  Docker  是什莫  
     Docker 本身并不是容器，它是创建容器的工具，是应用容器引擎。
   Docker包括三个基本概念：
镜像（Image） 一个特殊的文件系统
容器（Container） 镜像运行时的实体
仓库（Repository）集中存放镜像文件的地方

Docker - Build, Ship, and Run Any App, Anywhere
Build（构建镜像）：镜像就像是集装箱包括文件以及运行环境等等资源。
Ship（运输镜像）：主机和仓库间运输，这里的仓库就像是超级码头一样。
Run （运行镜像）：运行的镜像就是一个容器，容器就是运行程序的地方。
 
 
 判断  9.已运行 docker run -d -t --name demo ubuntu top 和 docker run --name demo-x --pid container:demo ubuntu ps 命令，是否可以在 demo-x 容器内停止容器？   正确

正确

错误

判断  10.已运行 docker run -d -t --name demo ubuntu top 和 docker run --name demo-x --pid container:demo ubuntu ps 命令，如果 demo 容器退出了，正在运行的 demo-x 容器是否会退出？ 正确 

正确

错误

-d  后台启动的 


## 16   etcd 基本原理解析     


## 什么是 etcd   
    etcd是CoreOS团队于2013年6月发起的开源项目，它的目标是构建一个高可用的分布式键值(key-value)数据库。etcd内部采用raft协议作为一致性算法，etcd基于Go语言实现。
    
    quorum  = (n+1)/2  3+1  /2 = 2 
    3 个节点容忍1个故障   3-2 =1 
    5 个节点容忍2个故障   
    
    单选  1.关于 etcd watch，以下说法错误的是？  C 

A. etcd watch 支持订阅指定 key 的最新数据变化。

B. etcd watch 支持订阅指定 key 前缀的数据变化。

C. etcd server 推送数据更新时，只包含数据变化的事件，不包含数据的内容。

D. etcd 支持订阅过去一段时间范围内的数据。

单选  4.关于 etcd 的数据，以下说法错误的是？ C 

A. etcd 支持存储多个版本的数据，允许查询指定 key 历史版本的数据。

B. etcd 为了控制数据总空间，会周期性的清理数据的历史版本。

C. etcd 支持修改旧版本的数据。

D. etcd 中，数据以二进制的方式存储在磁盘中。  
由于ETCD数据存储多版本数据，随着写入的主键增加历史版本需要定时清理，　  默认的历史数据是不会清理的，数据达到2G就不能写入，必须要清理压缩历史数据才能继续写入；
判断  5.etcd 集群中存在 3 个 server 时，重启其中一个 server 完全不会影响服务。

正确

错误
正确答案： 错误

多选  7.关于 etcd lease，以下说法正确的是？

A. etcd 创建 lease 对象时，需要指定一个时间作为其超时时间。

B. lease 对象被创建后，超过设定的时间一定会被系统自动回收。

C. 将 key 关联到 lease 对象上，当 lease 对象超时后，key 会被系统自动回收。

D. etcd 支持将多个 key 关联到同一个 lease 对象上，从而大幅降低刷新 lease 的性能开销。
正确答案： A C D

多选  9.关于 etcd 提供的 API，以下说法正确的是？

A. etcd 提供了 KeyValue 的存储结构，支持指定 key 查询数据。

B. etcd 提供了 Watch 接口，可以用于订阅 etcd 中数据的更新。

C. etcd 提供了基本的事务操作接口，etcd 确保单条事务执行的原子性。  支持事务  有一个commit  方法  涉及到事务 

D. etcd 支持范围查询。
正确答案： A B C D
lease 对象
Cluster：向集群里增加etcd服务端节点之类，属于管理员操作。
KV：我们主要使用的功能，即操作K-V。
Lease：租约相关操作，比如申请一个TTL=10秒的租约。
Watcher：观察订阅，从而监听最新的数据变化。
Auth：管理etcd的用户和权限，属于管理员操作。
Maintenance：维护etcd，比如主动迁移etcd的leader节点，属于管理员操作。

lease 功能
Grant：分配一个租约。
Revoke：释放一个租约。
TimeToLive：获取剩余TTL时间。
Leases：列举所有etcd中的租约。
KeepAlive：自动定时的续约某个租约。
KeepAliveOnce：为某个租约续约一次。
Close：貌似是关闭当前客户端建立的所有租约

事务Tnx
etcd中事务是原子执行的，只支持if … then … else …这种表达，能实现一些有意思的场景。
首先，我们需要开启一个事务，这是通过KV对象的方法实现的

## 17 etcd 性能优化实践
    4.一个节点数为 n 的 etcd 集群，它的 quorum 成员的数量是？ C 

     A. n/3

     B. n/2

     C. (n/2)+1

     D. n
     
     多选  8.以下说法正确的是？

     A. 新的etcd采用了segregated hashmap算法管理freelist

     B. freelist是内部已存储数据页面的集合

     C. 采用新的页面管理算法后，etcd存储数据量大幅度提升

     D. compact删除历史数据不会影响etcd性能
     正确答案： A C
         什莫是freelist  :
         可利用空间表 是动态内存管理的一种方法。通过把空闲内存划分成固定大小的数据块，而且利用指针字段把这些数据块链接起来，并使用一个指针指向首结点，这样就形成了一个单链表，即可利用空间表（free list）。
         当用户请求分配时，系统从可利用空间表中删除一个结点分配之；当用户释放其所占内存时，系统即回收并将它插入到可利用空间表中，因此，可利用空间表亦称为“存储池”。
         
         多选  9.下列哪些会影响etcd的性能？   ABCD

        A. etcd grpc api层延时

        B. etcd 客户端使用不当

        C. etcd boltdb性能不佳

        D. etcd 内存索引层中锁使用不当
        
        多选  10.关于 etcd lease，以下说法正确的是？

     A. 新版本的etcd 对lease处理进行了优化

     B. etcd中可以存有大量的lease

     C. etcd 切换leader后，lease会丢失   不会丢失 租约机制 会自动续约的

     D. etcd 切换leader后，原有lease ttl信息会不准
     正确答案： A D
   # 首先raft的协议是做什么的？

     分布式共识算法，通过raft协议让各个节点保持状态一致；
  # 不适合频繁读写的业务场景
     从其设计出发点，应该明白etcd提供的kv不适合对读写性能要求特别高的场景，它比较适合量小，但需要可靠的一致性数据存储服务，比如存储配置数据，在k8s中etcd用来存储集群的元数据。
     etcd 满足了 CAP 原理中的  CP 特性
     etcd可以手动增加、删除节点，也就是说节点数量对于各节点来说是相对静止的，在手动删除/增加后，节点数量变化，并通知到各节点
     可以通过 member list查看节点数量
     
     那节点数量是不是越多越好？
     不是的，etcd leader是需要向follower发送日志的，节点越多，发送的日志也就越多，同样leader的连接数也就越多；leader确认时，也就需要收到更多的follower的投票才能成为leader。所以数量较多可靠性较高，但性能会下降。
     
   #  网络分区对etcd的影响，以及节点数量对于服务的影响？

     以5（ABCDE,A:leader）节点的etcd集群为例，发生网络分区AB|CDE：
     AB部分，leader A向followers发送心跳，但无法获得大多数节点的响应，timeout后，进入选举阶段，AB都无法获得大多数的节点投票（因为和CDE分区，5节点下大多数要求包括自己在内的至少3个节点的投票确认）；
     CDE部分，超时后，也进入选举阶段，因为CDE的个数为5节点中的多数，所以可以选出leader对外提供服务；

     以上是从集群角度看网络分区，接下来看客户端收网络分区的影响：
     因为raft是强leader型算法，客户端使用etcd服务只能通过leader进行，AB分区后，不存在leader，所以无法对外提供服务，之前连接AB节点的客户端将无法获取服务；
     客户端无法感知leader发生变换，它将请求交给AB时，因为AB知道自己不是leader，但同时也不知道leader是谁，所以会向客户端响应轮询节点更换，找到新的leader。
     因为分区后AB服务对外提供读写服务，之前连接AB的客户端会受此影响，所以会增加请求读时间，这里就体现了raft协议满足了CAP中的CP，而没有满足A。
     
     etcd内部持久化存储采用的是 boltdb


## 18  Kubernetes 调度和资源管理

