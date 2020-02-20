CloundNative-2

##   20  GPU管理和Device Plugin工作机制


     从kubernetes1.8版本开始，提供了设备插件框架，设备厂商无需修改kubernetes核心代码就可以将自己生产的设备的资源
     (kubernetes可管理的资源包括CPU、内存和存储资源)可以让kubelet使用(这一点与操作系统一样，所有设备厂商自己实现驱动
     
     1 Device Plugin 中API可以用来反映设备健康状况的方法名称是？ C

          A. Allocate

          B. Register

          C. ListAndWatch

          D. PreStartContainer
          
          
          
          
     
 
  ![](img/device-plugin.png)  


          第一步是 Device Plugin 的注册，需要 Kubernetes 知道要跟哪个 Device Plugin 进行交互。这是因为一个节点上可能有多个设备，
          需要 Device Plugin 以客户端的身份向 Kubelet 汇报三件事情：我是谁？就是 Device Plugin 所管理的设备名称，是 GPU 还是 RDMA；
          我在哪？就是插件自身监听的 unis socket 所在的文件位置，让 kubelet 能够调用自己；交互协议，即 API 的版本号；

          第二步是服务启动，Device Plugin 会启动一个 GRPC 的 server。在此之后 Device Plugin 一直以这个服务器的身份提供服务让 kubelet 来访问，
          而监听地址和提供 API 的版本就已经在第一步完成了；

          第三步，当该 GRPC server 启动之后，kubelet 会建立一个到 Device Plugin 的 ListAndWatch 的长连接， 
          用来发现设备 ID 以及设备的健康状态。当 Device Plugin 检测到某个设备不健康的时候，就会主动通知 kubelet。
          而此时如果这个设备处于空闲状态，kubelet 会将其移除可分配的列表。但是当这个设备已经被某个 Pod 所使用的时候，
          kubelet 就不会做任何事情，如果此时杀掉这个 Pod 是一个很危险的操作；

          第四步，kubelet 会将这些设备暴露到 Node 节点的状态中，把设备数量发送到 Kubernetes 的 api-server 中。
          后续调度器可以根据这些信息进行调度。
          
          单选  3.Device Plugin的AllocateResponse中可以接收如下哪些参数? ABC

          A. devices

          B. mounts

          C. envs

          D. cpus
          正确答案： A B C
        9.使用Kubernetes管理GPU资源可以利用Kubernetes的统一调度能力，使资源使用方能够用即申请，完即释放，从而盘活整个GPU资源池。

          正确

          错误
          正确答案： 正确  

          多选  10.Kubernetes通过哪些内部机制支持GPU管理？ bc 

          A. CNI Plugin

          B. Device Plugin

          C. Extended Plugin

          D. Cloud Provider


## k8s 本身通过  插件扩展机制来管理 gpu  分为两种 extend resources 和 Device Plugin Framework 

     extend resources通用的模式支持不同的异构设备，包括 RDMA、FPGA、AMD GPU 等等，而不仅仅是为 Nvidia GPU 设计的；
     evice Plugin Framework 允许第三方设备提供商以外置的方式对设备进行全生命周期的管理，而 Device Plugin Framework 建立 Kubernetes 和 Device Plugin 模块之间的桥梁。它一方面负责设备信息的上报到 Kubernetes，另一方面负责设备的调度选择。
     
     
   # Device Plugin 机制的缺陷
   需要指出的是 Device Plugin 整个工作机制和流程上，实际上跟学术界和工业界的真实场景有比较大的差异。这里最大的问题在于 GPU 资源的调度工作，实际上都是在 kubelet 上完成的。

而作为全局的调度器对这个参与是非常有限的，作为传统的 Kubernetes 调度器来说，它只能处理 GPU 数量。一旦你的设备是异构的，不能简单地使用数目去描述需求的时候，比如我的 Pod 想运行在两个有 nvlink 的 GPU 上，这个 Device Plugin 就完全不能处理。

更不用说在许多场景上，我们希望调度器进行调度的时候，是根据整个集群的设备进行全局调度，这种场景是目前的 Device Plugin 无法满足的。

更为棘手的是在 Device Plugin 的设计和实现中，像 Allocate 和 ListAndWatch 的 API 去增加可扩展的参数也是没有作用的。这就是当我们使用一些比较复杂的设备使用需求的时候，实际上是无法通过 Device Plugin 来扩展 API 实现的。

因此目前的 Device Plugin 设计涵盖的场景其实是非常单一的， 是一个可用但是不好用的状态。这就能解释为什么像 Nvidia 这些厂商都实现了一个基于 Kubernetes 上游代码进行 fork 了自己解决方案，也是不得已而为之。
  
