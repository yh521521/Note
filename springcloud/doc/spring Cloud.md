

# spring Cloud

## 2020/2/23

### 微服务是什莫,他的优点是什莫

> 微服务”一词来源于 Martin Fowler 的《Microservices》一文。微服务是一种架构风格，即将单体应用划分为小型的服务单元，微服务之间使用 HTTP 的 API 进行资源访问与操作。

### 微服务架构的优势

#### 1）服务的独立部署

每个服务都是一个独立的项目，可以独立部署，不依赖于其他服务，耦合性低。

#### 2）服务的快速启动

拆分之后服务启动的速度必然要比拆分之前快很多，因为依赖的库少了，代码量也少了。

#### 3）更加适合敏捷开发

敏捷开发以用户的需求进化为核心，采用迭代、循序渐进的方法进行。服务拆分可以快速发布新版本，修改哪个服务只需要发布对应的服务即可，不用整体重新发布。

#### 4）职责专一，由专门的团队负责专门的服务

业务发展迅速时，研发人员也会越来越多，每个团队可以负责对应的业务线，服务的拆分有利于团队之间的分工。

#### 5）服务可以动态按需扩容

当某个服务的访问量较大时，我们只需要将这个服务扩容即可。

#### 6）代码的复用

每个服务都提供 REST API，所有的基础服务都必须抽出来，很多的底层实现都可以以接口方式提供。

### 微服务架构的劣势

#### 1）分布式部署，调用的复杂性高

单体应用的时候，所有模块之前的调用都是在本地进行的，在微服务中，每个模块都是独立部署的，通过 HTTP 来进行通信，这当中会产生很多问题，比如网络问题、容错问题、调用关系等。

#### 2）独立的数据库，分布式事务的挑战

每个微服务都有自己的数据库，这就是所谓的去中心化的数据管理。这种模式的优点在于不同的服务，可以选择适合自身业务的数据，比如订单服务可以用 

MySQL

、评论服务可以用 Mongodb、商品搜索服务可以用 Elasticsearch。

缺点就是事务的问题了，目前最理想的解决方案就是柔性事务中的最终一致性，后面的章节会给大家做具体介绍。

#### 3）测试的难度提升

服务和服务之间通过接口来交互，当接口有改变的时候，对所有的调用方都是有影响的，这时自动化测试就显得非常重要了，如果要靠人工一个个接口去测试，那工作量就太大了。这里要强调一点，就是 API 文档的管理尤为重要。

#### 4）运维难度的提升

在采用传统的单体应用时，我们可能只需要关注一个 Tomcat 的集群、一个 MySQL 的集群就可以了，但这在微服务架构下是行不通的。当业务增加时，服务也将越来越多，服务的部署、监控将变得非常复杂，这个时候对于运维的要求就高了。

### spring cloud 是什莫 

Spring Cloud 是一系列框架的有序集合。它利用 Spring Boot 的开发便利性，巧妙地简化了分布式系统基础设施的开发，如服务注册、服务发现、配置中心、消息总线、负载均衡、断路器、数据监控等，这些都可以用 Spring Boot 的开发风格做到一键启动和部署。

通俗地讲，Spring Cloud 就是用于构建微服务开发和治理的框架集合（并不是具体的一个框架），主要贡献来自 Netflix OSS。

### 模块介绍

- Eureka：服务注册中心，用于服务管理。

- Ribbon：基于客户端的负载均衡组件。

- Hystrix：容错框架，能够防止服务的雪崩效应。

- Feign：Web 服务客户端，能够简化 HTTP 接口的调用。

- Zuul：API 网关，提供路由转发、请求过滤等功能。

- Config：分布式配置管理。

- Sleuth：服务跟踪。

- Stream：构建消息驱动的微服务应用程序的框架。

- Bus：消息代理的集群消息总线。

  此外还有Cli  Task

  # ## spring boot 开发优点

  - 基于 Spring 开发 Web 应用更加容易。
  - 采用基于注解方式的配置，避免了编写大量重复的 XML 配置。
  - 可以轻松集成 Spring 家族的其他框架，比如 Spring JDBC、Spring Data 等。
  - 提供嵌入式服务器，令开发和部署都变得非常方便。
  - ​

总结下来就是@PostMapping和@GetMapping都可以用@RequestMapping代替，如果读者怕在映射的时候出错，可以统一写@RequestMapping，当然这样写的话也有弊端，笼统的全用@RequestMapping, 写好路径过滤



spring-boot-devtools 的依赖即可实现热部署功能



自定义的actuator

```
引入依赖  直接启动 springboot  访问http://localhost:81/actuator/health
看到 健康信息
<!--监控-->
   <dependency>
      <groupId>org.springframework.boot</groupId>
      <artifactId>spring-boot-starter-actuator</artifactId>
   </dependency>
```

```
 UserHealthIndicator extends AbstractHealthIndicator
 //up 方法指定应用的状态为健康，down 方法指定应用的状态为不健康
		builder.up().withDetail("status",true);
		builder.down().withDetail("status", false);
```

```
{"status":"UP",
"components":{"diskSpace":{"status":"UP","details":{"total":321912827904,"free":103868465152,"threshold":10485760}},"ping":{"status":"UP"},"user":{"status":"UP","details":{"status":true}}}}
```

```
{"status":"DOWN","components":{"diskSpace":{"status":"UP","details":{"total":321912827904,"free":103868465152,"threshold":10485760}},"ping":{"status":"UP"},"user":{"status":"DOWN","details":{"status":false}}}}
```

访问 /actuator/user 可以看到返回的用户信息如下：

```
[{"userName":"yh521","userId":"521"}]
```

@ ControllerAdvice 注解  异常进行统一处理

为了方便对异常的统一管理，spring mvc提供了ControllerAdvice注解对异常进行统一的处理，拿到这些异常信息后，可以做一些处理，比如提供一个统一的web界面查看异常信息，或者普通到异常信息后，发送短信、邮件形式通知到相关人员，可以帮助开发人员快速发现并定位问题，减少以往通过查看线上日志文件排查问繁琐锁耗时的所耗费的时间。下面我跟大家介绍具体步骤。

可以省去set  get  方法  加上  @Data  注解

```
<dependency>
   <groupId>org.projectlombok</groupId>
   <artifactId>lombok</artifactId>
</dependency>
```

## Spring Cloud Eureka是什么？

Spring Cloud Eureka 是一个基于 REST 的服务，并且提供了基于 的客户端组件，能够非常方便地将服务注册到 Spring Cloud Eureka 中进行统一管理。

服务治理是微服务架构中必不可少的一部分，阿里开源的 Dubbo 框架就是针对服务治理的。服务治理必须要有一个注册中心，除了用 Eureka 作为注册中心外，我们还可以使用 Consul、Etcd、Zookeeper 等来作为服务的注册中心。

为什么 Eureka 比 Zookeeper 更适合作为注册中心呢？主要是因为 Eureka 是基于 AP 原则构建的，而 ZooKeeper 是基于 CP 原则构建的。

在分布式系统领域有个著名的 CAP 定理，即 C 为数据一致性；A 为服务可用性；P 为服务对网络分区故障的容错性。这三个特性在任何分布式系统中都不能同时满足，最多同时满足两个。

注册中心配置

```
spring.application.name=eureka-server
server.port=8761
# 由于该应用为注册中心, 所以设置为false, 代表不向注册中心注册自己
eureka.client.register-with-eureka=false
# 由于注册中心的职责就是维护服务实例, 它并不需要去检索服务, 所以也设置为 false
eureka.client.fetch-registry=false
```

启动报错的话很可能是cloud  版本 跟你引入的依赖不匹配 

服务提供者编写完成后  正常启动会打印出 

DiscoveryClient_EUREKA-CLIENT-USER-SERVICE/eureka-client-user-service:192.168.43.86:8081 - registration status: 204



![](img/springCloud/eureka-server.png)





![](img/springCloud/eureka-service.png)



![](img/springCloud/eureka-consumer.png)

![](img/springCloud/eureka-server.png)

